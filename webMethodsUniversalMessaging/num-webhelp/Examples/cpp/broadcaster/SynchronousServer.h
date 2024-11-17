/*
 *
 *   Copyright (c) 1999 - 2011 my-Channels Ltd
 *   Copyright (c) 2012 - 2022 Software AG, Darmstadt, Germany and/or Software AG USA Inc., Reston, VA, USA, and/or its subsidiaries and/or its affiliates and/or their licensors.
 *
 *   Use, reproduction, transfer, publication or disclosure is prohibited except as specifically provided for in your License Agreement with Software AG.
 *
 */
#pragma once
#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "Poco/Mutex.h"
#include "SynchronousServerTransport.h"
#include "TransportFactory.h"
#include "SynchronousServerTransport.h"
#include "ServerTransportContextFactory.h"
#include "ServerTransportContext.h"
#include "SynchronousTransport.h"
#include "BroadcastMessage.h"
#include "SynchronousClient.h"

#include <memory>
#include <vector>

namespace com{
namespace softwareag{
namespace umtransport{
namespace samples{
namespace broadcaster{

class SynchronousServer
{
public:
	static int main (int argc, char** argv);

protected:
	class SocketAcceptor : public Poco::Runnable {
	public:
		SocketAcceptor(std::unique_ptr<SynchronousServerTransport> transport);
		virtual ~SocketAcceptor();
		virtual void run();
		void stop();
	private:
		std::unique_ptr<SynchronousServerTransport> m_serverTransport;		
		bool stopped;
	};

private:
	static void fanout(BroadcastMessage & message);

protected:	
	static Poco::Mutex clientListMutex;
	static std::vector<SynchronousClient<BroadcastMessage>*> clientList;

};
}}}}}
