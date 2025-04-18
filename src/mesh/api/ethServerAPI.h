#pragma once

#include "ServerAPI.h"
#ifndef USE_WS5500
#include <RAK13800_W5100S.h>

/**
 * Provides both debug printing and, if the client starts sending protobufs to us, switches to send/receive protobufs
 * (and starts dropping debug printing - FIXME, eventually those prints should be encapsulated in protobufs).
 */
class ethServerAPI : public ServerAPI<EthernetClient>
{
  public:
    explicit ethServerAPI(EthernetClient &_client);
};

/**
 * Listens for incoming connections and does accepts and creates instances of EthernetServerAPI as needed
 */
class ethServerPort : public APIServerPort<ethServerAPI, EthernetServer>
{
  public:
    explicit ethServerPort(int port);
};

void initApiServer(int port = SERVER_API_DEFAULT_PORT);
#endif
