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

$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns make-lan "$n2 $n3 $n4" 100Mb 1ms LL Queue/DropTail Mac/802_3 Channel Phy/WiredPhy

set errModel [new ErrorModel]
$errModel set rate_ 0.2
$errModel ranvar [new RandomVariable/Uniform]
$errModel drop-target [new Agent/Null]

$ns lossmodel $errModel $n1 $n2

set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0

set ftp0 [new Application/FTP];
$ftp0 attach-agent $tcp0

set sink0 [new Agent/TCPSink]
$ns attach-agent $n4 $sink0

$ns connect $tcp0 $sink0

set fileSize [expr 4*1024*1024]
$ns at 0.0 "$ftp0 send $fileSize"

proc finish {} {
    global ns nf tf
    $ns flush-trace
    close $tf
    close $nf
    
    set awkCode {
        BEGIN {}
        {
            if($1=="d" && $5=="tcp" && $6 > 1460){
                count_packets++;
                print $2, count_packets >> "lan.data"
            }
        }
        END {}
    }
    exec awk $awkCode lan.tr
    exec nam "lan.nam" &
    exec xgraph -bb -x Time -y Droped_Packets lan.data -bg white &
    exit 0;
}

$ns at 10.0 "finish"
$ns run
