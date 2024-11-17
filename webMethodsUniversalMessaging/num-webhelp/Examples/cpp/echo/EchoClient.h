/*
 *
 *   Copyright (c) 1999 - 2011 my-Channels Ltd
 *   Copyright (c) 2012 - 2022 Software AG, Darmstadt, Germany and/or Software AG USA Inc., Reston, VA, USA, and/or its subsidiaries and/or its affiliates and/or their licensors.
 *
 *   Use, reproduction, transfer, publication or disclosure is prohibited except as specifically provided for in your License Agreement with Software AG.
 *
 */
#pragma once
#include "SynchronousClient.h"
#include "SimpleMessage.h"
#include <string>
#include "Poco/Runnable.h"

namespace com{
namespace softwareag{
namespace umtransport{
namespace samples{
namespace echo{
class EchoClient
{
public:
	static int main(int argc, char** argv);

	EchoClient(std::string url);
	virtual ~EchoClient();
	void run();	

private:
	std::string m_url;

protected:
	class ReadThread : public Poco::Runnable {
	public:
		ReadThread(SynchronousClient<SimpleMessage> &client);
		virtual ~ReadThread();
		virtual void run();
		virtual void shutdown();
	private:
		SynchronousClient<SimpleMessage> m_client;
		volatile bool canRun;		
	};
};
}}}}}

