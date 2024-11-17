/*
 *
 *   Copyright (c) 1999 - 2011 my-Channels Ltd
 *   Copyright (c) 2012 - 2022 Software AG, Darmstadt, Germany and/or Software AG USA Inc., Reston, VA, USA, and/or its subsidiaries and/or its affiliates and/or their licensors.
 *
 *   Use, reproduction, transfer, publication or disclosure is prohibited except as specifically provided for in your License Agreement with Software AG.
 *
 */
#pragma once
#include <cstring>

#include "SynchronousTransport.h"

namespace com{
namespace softwareag{
namespace umtransport{
namespace samples{
class Message{
public:
	virtual void writeOut(com::softwareag::umtransport::SynchronousTransport::OutputStream &outputStream) = 0;
	virtual void readIn(com::softwareag::umtransport::SynchronousTransport::InputStream &inputStream) = 0;
	
	void sendString(com::softwareag::umtransport::SynchronousTransport::OutputStream &outputStream, std::string str){
		unsigned char* length = new unsigned char[2];
		unsigned char* text = new unsigned char[str.length()];

		length[0] = (char)((str.length() >> 15) & 0xff);
		length[1] = (char)(str.length() & 0xff);
		std::memcpy(text, str.c_str(), str.length());

		outputStream.write(length, 0, 2);
		outputStream.write(text, 0, str.length());

		delete[] length;
		delete[] text;
	};

	std::string readString(com::softwareag::umtransport::SynchronousTransport::InputStream &inputStream){
		unsigned char* size = new unsigned char[2];
		int sizeRead = 0;
		while (sizeRead<2){
			sizeRead += inputStream.read(size, sizeRead, 2);
		}
		int val = (((longlong)size[0] & 0xff) << 15);
		val = ((longlong)size[1] & 0xff) | val;
		delete[] size;
		std::string str;

		if (val>0){
			unsigned char* text = new unsigned char[val];
			inputStream.read(text, 0, val);
			for (int i = 0; i < val; i++) {
				str += text[i];
			}
			delete[] text;
		}
		return str;
	};

	void sendLong(com::softwareag::umtransport::SynchronousTransport::OutputStream &outputStream, long long num){
		int bitPos = 63;
		unsigned char* output = new unsigned char[8];

		for (int x = 0; x < 8; x++) {
			output[x] = (char)((num >> bitPos) & 0xff);
			bitPos -= 8;
		}
		outputStream.write(output, 0, 8);
		delete[] output;
	};

	long long readLong(com::softwareag::umtransport::SynchronousTransport::InputStream &inputStream){
		unsigned char* input = new unsigned char[8];
		int readSize = 0;
		while (readSize <8){
			readSize += inputStream.read(input, readSize, 8);
		}
		long long val = 0;
		int bitPos = 63;

		for (int x = 0; x < 8; x++) {
			val = (((long long)input[x] & 0xff) << bitPos) | val;
			bitPos -= 8;
		}
		delete[] input;
		return val;
	};
};
}
}
}
}