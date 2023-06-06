# Simulate to study transmission of packets over
# Ethernet LAN and determine the number of packets drop destination.

set ns [new Simulator]

set nf [open lan.nam w]
$ns namtrace-all $nf

set tf [open lan.tr w]
$ns trace-all $tf

Agent/TCP set packetSize_ 1460

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]

$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns make-lan "$n2 $n3 $n4" 100Mb 1ms LL Queue/DropTail Mac/802_3 Channel Phy/WiredPhy

set errmodel [new ErrorModel]
$errmodel set rate_ 0.2
$errmodel ranvar [new RandomVariable/Uniform]
$errmodel drop-target [new Agent/Null]

$ns lossmodel $errmodel $n1 $n2

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n4 $sink
$ns connect $tcp $sink

set ftp [new Application/FTP]
$ftp attach-agent $tcp
set filesize [expr 4*1024*1024]
$ns at 0.0 "$ftp send $filesize"

proc finish { } {
    global ns nf tf
    $ns flush-trace
    close $nf
    close $tf
    set awkCode {
        BEGIN{}
        {
            if ($1=="d" && $5=="tcp" && $6 > 1460) {
                count_packets++;
                print $2, count_packets >> "lan.data"
            }
        }
        END{}
    }
    exec awk $awkCode lan.tr
    exec nam lan.nam &
    exec xgraph -bb -x Time -y Dropped_Packets lan.data -bg white &
    exit 0
}
$ns at 10.0 "finish"
$ns run

