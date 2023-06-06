set ns [new Simulator]

set tf [open lan.tr w]
$ns trace-all $tf

set nf [open lan.nam w]
$ns namtrace-all $nf

Agent/TCP set packetSize_ 1460

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]

$ns duplex-link $n0 $n1 1mb 10ms DropTail
$ns duplex-link $n1 $n2 1mb 10ms DropTail
$ns make-lan "$n2 $n3 $n4" 100mb 1ms LL Queue/DropTail Mac/802_3 Channel Phy/WiredPhy

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

set fileSize [expr 4*1024*1024]

$ns at 0.0 "$tcp send $fileSize"

proc finish {} {
    global ns nf tf
    close $tf
    close $nf
    set awkCode {
        BEGIN {}
        {
            if($1 =="d" && $5 =="tcp" && $6 > 1460){
                count_packets++;
                print $2, count_packets >> "lan.data"
            }

        }
        END {}
    }
    exec awk $awkCode lan.tr 
    exec nam lan.nam &
    exec xgraph -bb -x Time -y Dropped_Packets lan.data -bg white &
    exit 0
}

$ns at 10.0 "finish"
$ns run