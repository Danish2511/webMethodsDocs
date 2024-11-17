/*
 *
 *   Copyright (c) 1999 - 2011 my-Channels Ltd
 *   Copyright (c) 2012 - 2022 Software AG, Darmstadt, Germany and/or Software AG USA Inc., Reston, VA, USA, and/or its subsidiaries and/or its affiliates and/or their licensors.
 *
 *   Use, reproduction, transfer, publication or disclosure is prohibited except as specifically provided for in your License Agreement with Software AG.
 *
 */
#pragma once

#include "nReconnectHandler.h"
#include "nAsyncExceptionListener.h"
#include "Exception.h"
#include <string>
#include <cstdlib>
#include <stdio.h>

namespace com {
namespace pcbsys {
namespace nirvana {
namespace client {
class nSession;
class nBaseClientException;
class nSessionAttributes;
class nEventProperties;
class nEventAttributes;
}
namespace apps {

using namespace client;

class nSampleApp :
    public nReconnectHandler, public nAsyncExceptionListener {
  public:
    nSampleApp(void);
    virtual ~nSampleApp(void);

    void disconnected(nSession *pSession);
    void reconnected(nSession *pSession);
    bool tryAgain(nSession *pSession);
    void handleException(nBaseClientException *pEx);

  protected:
    static void UsageEnv();
    static void processEnvironmentVariables();
    static std::string* parseRealmProperties(std::string& realmdetails, int& nURL);
    void constructSession(std::string *pRealmDetails, int nRealmDetail);
    void displayEventProperties(nEventProperties *pProp);
    void displayEventAttributes(nEventAttributes *pAttributes);

    nSession *m_pSession;
    nSessionAttributes *m_pNsa;

  private:
    std::string m_lastSessionID;
};

}
}
}
}
