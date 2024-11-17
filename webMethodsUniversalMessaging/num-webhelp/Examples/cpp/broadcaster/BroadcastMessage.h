/*
 *
 *   Copyright (c) 1999 - 2011 my-Channels Ltd
 *   Copyright (c) 2012 - 2022 Software AG, Darmstadt, Germany and/or Software AG USA Inc., Reston, VA, USA, and/or its subsidiaries and/or its affiliates and/or their licensors.
 *
 *   Use, reproduction, transfer, publication or disclosure is prohibited except as specifically provided for in your License Agreement with Software AG.
 *
 */
#pragma once

#include <string>
#include <iostream>

#include "SynchronousTransport.h"
#include "Message.h"

namespace com{
namespace softwareag{
namespace umtransport{
namespace samples{
namespace broadcaster{

class BroadcastMessage : public com::softwareag::umtransport::samples::Message
{
public:
	BroadcastMessage();
	BroadcastMessage(std::string body, std::string from);	
	virtual ~BroadcastMessage();
	void writeOut(com::softwareag::umtransport::SynchronousTransport::OutputStream &outputStream);
	void readIn(com::softwareag::umtransport::SynchronousTransport::InputStream &inputStream);

	friend std::ostream & operator<<(std::ostream & _stream, BroadcastMessage const & mc){
		_stream << "Message Recieved\n From : " << mc.m_from << "\n Sent : " << mc.m_time << "\n " << mc.m_body << std::endl;
		return _stream;
	}

private:

	std::string m_body;
	std::string m_from;
	long long m_time;
};



}}}}}