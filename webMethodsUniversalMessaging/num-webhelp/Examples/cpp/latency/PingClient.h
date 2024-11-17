/*
 *
 *   Copyright (c) 1999 - 2011 my-Channels Ltd
 *   Copyright (c) 2012 - 2022 Software AG, Darmstadt, Germany and/or Software AG USA Inc., Reston, VA, USA, and/or its subsidiaries and/or its affiliates and/or their licensors.
 *
 *   Use, reproduction, transfer, publication or disclosure is prohibited except as specifically provided for in your License Agreement with Software AG.
 *
 */
#pragma once

#include "SynchronousTransport.h"

#include <memory>
#include "Poco/Runnable.h"
#include "SynchronousTransport.h"


namespace com{
namespace softwareag{
namespace umtransport{
namespace samples{
namespace ping{
class PingClient
{
public:
	static int main(int argc, char** argv);

private:
	static void writeValue(unsigned char* workingBuffer, int offset, long long val, int size);
	static long long readValue(unsigned char* workingBuffer, int offset, int size);

protected:
	class Writer {
	public:		
		virtual void send()=0;
	};

	class SyncWriter : public Writer {
	public:
		SyncWriter(std::shared_ptr<SynchronousTransport> transport, int packetSize);
		virtual ~SyncWriter();
		virtual void send();
	private:
		unsigned char* buffer;
		int bufferSize;
		std::shared_ptr<SynchronousTransport> m_transport;
	};

	class Reader : public Poco::Runnable {
	public:
		Reader(std::shared_ptr<SynchronousTransport> transport, int pktSize);
		virtual ~Reader();
		virtual void run();
	private:
		std::shared_ptr<SynchronousTransport> m_transport;
		int packetSize;
	};

	class PacketGenerator : public Poco::Runnable {
	public:
		PacketGenerator(std::shared_ptr<SynchronousTransport> transport, Writer* writer, int packetsPerSecond);
		virtual ~PacketGenerator();
		virtual void run();
	private:
		std::shared_ptr<SynchronousTransport> m_transport;
		Writer* m_writer;
		int m_packetsPerSecond;
	};

};
}}}}}
