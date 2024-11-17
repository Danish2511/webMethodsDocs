/*
 *
 *   Copyright (c) 1999 - 2011 my-Channels Ltd
 *   Copyright (c) 2012 - 2022 Software AG, Darmstadt, Germany and/or Software AG USA Inc., Reston, VA, USA, and/or its subsidiaries and/or its affiliates and/or their licensors.
 *
 *   Use, reproduction, transfer, publication or disclosure is prohibited except as specifically provided for in your License Agreement with Software AG.
 *
 */
#pragma once

#include "Poco/Runnable.h"
#include "BroadcastMessage.h"
#include "SynchronousClient.h"

namespace com{
namespace softwareag{
namespace umtransport{
namespace samples{
namespace broadcaster{
class SynchronousBroadcasterClient : public Poco::Runnable{

public:
	SynchronousBroadcasterClient(std::shared_ptr<SynchronousClient<BroadcastMessage>> client);
	virtual ~SynchronousBroadcasterClient();
	virtual void run();
	virtual void shutdown();

	static int main (int argc, char** argv);

private:
	std::shared_ptr<SynchronousClient<BroadcastMessage>> m_client;
	bool canRun;

};
}}}}}
