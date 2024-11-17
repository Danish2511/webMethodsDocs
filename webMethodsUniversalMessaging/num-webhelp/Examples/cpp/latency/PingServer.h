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

#include <memory>
#include <vector>

namespace com{
namespace softwareag{
namespace umtransport{
namespace samples{
namespace ping{
class PingServer
{
public:
	PingServer();
	virtual ~PingServer();
	static int main(int argc, char** argv);

	protected:
		class ReadThread : public Poco::Runnable {
		public:
			ReadThread(std::unique_ptr<SynchronousTransport> transport);
			virtual ~ReadThread();
			virtual void run();
		private:
			std::unique_ptr<SynchronousTransport> m_client;
		};
	protected:
		class ServerAcceptThread : public Poco::Runnable {
		public:
			ServerAcceptThread(std::unique_ptr<SynchronousServerTransport> transport);
			virtual ~ServerAcceptThread();
			virtual void run();
			void close();
		private:
			std::unique_ptr<SynchronousServerTransport> m_serverTransport;
			std::vector<ReadThread*> readThreadObjects;
		};

	protected:
		static Poco::Mutex threadMutex;
		static std::vector<Poco::Thread*> threadList;
		static volatile bool canRun;
	};
}
}
}
}
}
