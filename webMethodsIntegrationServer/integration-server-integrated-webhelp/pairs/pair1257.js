// 
// Search index entries generated by WebWorks ePublisher
//
// Copyright (c) 2007-2022 Software AG, Darmstadt, Germany and/or Software AG USA, Inc., Reston, VA, USA, and/or its subsidiaries and/or its affiliates and/or their licensors
//
var pairs =
{
"checkpoint":{"restart":1,"rather":1}
,"restart":{"stateful":1,"services":1}
,"stateful":{"stateless":1,"clusters":1}
,"stateless":{"clusters":1}
,"clusters":{"pub.storage":1,"stateless":1}
,"pub.storage":{"pub.cache":1,"service":1}
,"pub.cache":{"service":1,"services":1}
,"service":{"code":1,"fails":1,"restarted":1,"checkpoint":1}
,"code":{"flow":1}
,"flow":{"services":1,"service":1}
,"services":{"store":1,"webmethods":1,"reference":1,"stateful":1}
,"store":{"state":1,"flow":1}
,"state":{"information":1}
,"information":{"pertinent":1,"short-term":1,"pub.storage":1}
,"pertinent":{"information":1}
,"short-term":{"data":1}
,"data":{"store":1}
,"fails":{"server":1}
,"server":{"becomes":1,"built-in":1}
,"becomes":{"unavailable":1}
,"unavailable":{"flow":1}
,"restarted":{"last":1}
,"last":{"checkpoint":1}
,"rather":{"beginning":1}
,"beginning":{"information":1}
,"webmethods":{"integration":1}
,"integration":{"server":1}
,"built-in":{"services":1}
,"reference":{"checkpoint":1}
}
;Search.control.loadWordPairs(pairs);