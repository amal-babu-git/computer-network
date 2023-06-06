#Create a simulator object
set ns [new Simulator]
#open a trace file
set tf [ open dup.tr w ]
$ns trace-all $tf
#open a nam trace file .This file will be used for visualizing the simulation results using the Network Animator tool (nam).
set nf [open dup.nam w] 
$ns namtrace-all $nf 
#creating nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
#Assign color to packet
$ns color 1 "red"
$ns color 2 "blue"
#label the node
$n0 label "source/udp0"
$n1 label "source/udp1"
$n2 label "router"
$n3 label "destination/null"
#create link vary bandwidth to check
$ns duplex-link $n0 $n2 10mb 300ms DropTail
$ns duplex-link $n1 $n2 10mb 300ms DropTail
$ns duplex-link $n2 $n3 1mb 300ms DropTail
#set queue size between the nodes
$ns set queue-limit $n0 $n2 10
$ns set queue-limit $n1 $n2 10
$ns set queue-limit $n2 $n3 5
#Set a udp connection
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0
#create a cbr traffic source and attach it to udp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0
#crate a UDP agent and attach it to node n1
set udp1 [new Agent/UDP]
$ns attach-agent $n1 $udp1
#create a cbr traffic source and attach
set cbr1 [new Application/Traffic/CBR]
$cbr1 set packetSize_ 500
$cbr1 set interval_ 0.005
$cbr1 attach-agent $udp1
#creata null agent (a traffic link) and attach it to n3
set null3 [new Agent/Null]
$ns attach-agent $n3 $null3
#set colors to udp packets
$udp0 set class_ 1
$udp1 set class_ 2
#connect traffic source with the traffic
$ns connect $udp0 $null3
$ns connect $udp1 $null3
#define a finish procedure
proc finish {} {
    global ns nf tf
    $ns flush-trace
    exec nam dup.nam &
    close $tf
    close $nf
    exit 0;
}
#shedule events for CBR agent
$ns at 0.1 "$cbr0 start"
$ns at 0.1 "$cbr1 start"
#call the finish proc after 10 seconds
$ns at 10.0 "finish"
#Run the simulation
$ns run
