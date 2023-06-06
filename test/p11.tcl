set ns [new Simulator]

set tf [open dup.tr w]
$ns trace-all $tf

set nf [open dup.nam w]
$ns namtrace-all $nf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$ns color 1 "red"
$ns color 2 "blue"

$n0 label "source/udp0"
$n1 label "source/udp1"
$n2 label "router"
$n3 label "destination/null"

$ns duplex-link $n0 $n2 10mb 300ms DropTail
$ns duplex-link $n1 $n2 10mb 300ms DropTail
$ns duplex-link $n2 $n3 1mb 300ms DropTail

$ns set queue-limit $n0 $n2 10
$ns set queue-limit $n1 $n2 10
$ns set queue-limit $n2 $n3 5

set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0

set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0

set udp1 [new Agent/UDP]
$ns attach-agent $n1 $udp1

set cbr1 [new Application/Traffic/CBR]
$cbr1 set packetSize_ 500
$cbr1 set interval_ 0.005
$cbr1 attach-agent $udp1

set null3 [new Agent/Null]
$ns attach-agent $n3 $null3

$udp0 set class_ 1
$udp1 set class_ 2

$ns connect $udp0 $null3
$ns connect $udp1 $null3

proc finish {} {
    global ns tf nf
    $ns flush-trace
    exec nam dup.nam &
    close $tf
    close $nf
    exit 0;
}

$ns at 0.1 "$cbr0 start"
$ns at 0.1 "$cbr1 start"

$ns at 10 "finish"
$ns run




