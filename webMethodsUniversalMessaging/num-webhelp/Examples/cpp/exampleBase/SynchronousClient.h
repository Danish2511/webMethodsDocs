/*
 *
 *   Copyright (c) 1999 - 2011 my-Channels Ltd
 *   Copyright (c) 2012 - 2022 Software AG, Darmstadt, Germany and/or Software AG USA Inc., Reston, VA, USA, and/or its subsidiaries and/or its affiliates and/or their licensors.
 *
 *   Use, reproduction, transfer, publication or disclosure is prohibited except as specifically provided for in your License Agreement with Software AG.
 *
 */
#pragma once

#include <memory>
#include "SynchronousTransport.h"

namespace com{
namespace softwareag{
namespace umtransport{
namespace samples{

template <class T>
class SynchronousClient
{
private:	
	std::shared_ptr<SynchronousTransport> m_transport;	
public:

	SynchronousClient(std::shared_ptr<SynchronousTransport> transport){
		m_transport = transport;		
	};

	virtual ~SynchronousClient(){

	};

	void close(){
		m_transport->close();
	}

	void write(T & mess){
		mess.writeOut(m_transport->getOutputStream());
		m_transport->getOutputStream().flush();
	}

	void read(T & mess){
		mess.readIn(m_transport->getInputStream());
	}

};

}}}}