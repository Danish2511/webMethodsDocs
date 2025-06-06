// 
// Search index entries generated by WebWorks ePublisher
//
// Copyright (c) 2000-2023 Software AG, Darmstadt, Germany and/or Software AG USA, Inc., Reston, VA, USA, and/or its subsidiaries and/or its affiliates and/or their licensors
//
var pairs =
{
"invoking":{"generatefa":1,"envelopeprocess":1}
,"generatefa":{"invoking":1,"service":1}
,"envelopeprocess":{"invoke":1,"service":1}
,"invoke":{"generatefa":1,"service":1}
,"service":{"envelopeprocess":1,"service":1,"uses":1,"following":1,"note":1,"invoking":1,"generate":1,"hat":1}
,"uses":{"unparsed":1}
,"unparsed":{"edi":1,"document":1}
,"edi":{"document":1,"content":1}
,"document":{"inpu":1,"pipeline":1,"time":1}
,"inpu":{"unparsed":1}
,"pipeline":{"edidata":1,"edi":1,"section":1,"mapped":1}
,"edidata":{"parameter":1,"service":1}
,"parameter":{"edidata":1,"placed":1,"inputs":1,"pipeline":1}
,"placed":{"pipeline":1}
,"content":{"handl":1}
,"handl":{"information":1}
,"information":{"edidata":1}
,"inputs":{"service":1}
,"following":{"diagram":1}
,"diagram":{"shows":1}
,"shows":{"updated":1}
,"updated":{"version":1}
,"version":{"servic":1}
,"servic":{"illustrated":1}
,"illustrated":{"processing":1}
,"processing":{"entire":1}
,"entire":{"document":1}
,"time":{"includes":1}
,"includes":{"invocation":1}
,"invocation":{"generatefa":1}
,"note":{"pipeline":1}
,"section":{"screen":1}
,"screen":{"edidata":1}
,"mapped":{"edidata":1}
,"generate":{"add":1}
,"add":{"logic":1}
,"logic":{"invoke":1}
,"hat":{"create":1}
,"create":{"deliver":1}
,"deliver":{"sender":1}
,"sender":{"origin":1}
,"origin":{"edi":1}
}
;Search.control.loadWordPairs(pairs);
