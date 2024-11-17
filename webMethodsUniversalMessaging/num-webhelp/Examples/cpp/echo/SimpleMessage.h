/*
 *
 *   Copyright (c) 1999 - 2011 my-Channels Ltd
 *   Copyright (c) 2012 - 2022 Software AG, Darmstadt, Germany and/or Software AG USA Inc., Reston, VA, USA, and/or its subsidiaries and/or its affiliates and/or their licensors.
 *
 *   Use, reproduction, transfer, publication or disclosure is prohibited except as specifically provided for in your License Agreement with Software AG.
 *
 */
#pragma once
#include "Message.h"
#include <string>
#include <iostream>

namespace com{
namespace softwareag{
namespace umtransport{
namespace samples{
namespace echo{

class SimpleMessage : public com::softwareag::umtransport::samples::Message
{
public:
	SimpleMessage();
	SimpleMessage(std::string text);
	virtual ~SimpleMessage();
	void writeOut(com::softwareag::umtransport::SynchronousTransport::OutputStream &outputStream);
	void readIn(com::softwareag::umtransport::SynchronousTransport::InputStream &inputStream);

	friend std::ostream & operator<<(std::ostream & _stream, SimpleMessage const & mc){
		_stream << mc.m_text << std::endl;
		return _stream;
	}

private:
	std::string m_text;
};
}}}}}