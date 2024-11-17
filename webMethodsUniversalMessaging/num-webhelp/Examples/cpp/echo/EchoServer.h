/*
 *
 *   Copyright (c) 1999 - 2011 my-Channels Ltd
 *   Copyright (c) 2012 - 2022 Software AG, Darmstadt, Germany and/or Software AG USA Inc., Reston, VA, USA, and/or its subsidiaries and/or its affiliates and/or their licensors.
 *
 *   Use, reproduction, transfer, publication or disclosure is prohibited except as specifically provided for in your License Agreement with Software AG.
 *
 */
#pragma once

#include "SynchronousServerTransport.h"

#include "Poco/Runnable.h"
#include <string>

namespace com{
namespace softwareag{
namespace umtransport{
namespace samples{
namespace echo{

/**
* This sample will only handle one client connection at a time. When a client connects,
* the EchoServer will immediately respond to any messages with exactly the same message.
*/
class EchoServer : public Poco::Runnable
{
public:
	static int main(int argc, char** argv);

	EchoServer(std::string url);
	virtual ~EchoServer();
	virtual void run();
	virtual void close();

private:
	std::unique_ptr<SynchronousServerTransport> m_transport;
	volatile bool stopped;

};
}
}
}
}
}

