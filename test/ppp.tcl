set ns [new Simulator]

set tf [open star.tr w]
$ns trace-all $tf

set nf [open star.nam w]
$ns namtrace-all $nf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]

$n0 label "source/tcp0"
$n1 label "source/udp0"
$n2 label "destination/null0"
$n3 label "destnation/sink0"

$n0 color "red"
$n3 color "green"
$n2 color "green"
$n1 color "red"
$n4 color "black"
$ns color 1 "red"
$ns color 2 "blue"

$n0 shape square
$n3 shape square
$n1 shape hexagon
$n2 shape hexagon
$n4 shape circle

$ns duplex-link $n0 $n4 1mb 10ms DropTail
$ns duplex-link $n1 $n4 1mb 10ms DropTail
$ns duplex-link $n2 $n4 1mb 10ms DropTail
$ns duplex-link $n3 $n4 1mb 10ms DropTail

set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0

set ftp0 [new Application/FTP]
# $ftp0 set rate_ 0.2
$ftp0 attach-agent $tcp0

set sink0 [new Agent/TCPSink]
$ns attach-agent $n3 $sink0

set udp0 [new Agent/UDP]
$ns attach-agent $n1 $udp0

set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0

set null0 [new Agent/Null]
$ns attach-agent $n2 $null0

$tcp0 set class_ 1
$udp0 set class_ 2

$ns connect $tcp0 $sink0
$ns connect $udp0 $null0

proc finish {} {
    global ns nf tf
    exec nam star.nam &
    close tf
    close nf
    exit 0;
}

$ns at 0.1 "$ftp0 start"
$ns at 0.8 "$ftp0 stop"
$ns at 0.3 "$cbr0 start"
$ns at 0.9 "$cbr0 stop"

$ns at 10.0 "finish"
$ns run