#ifndef __ETIP_H__
#define __ETIP_H__

#include "basic.h"

void set_address(char* host_name, char* port_name, struct sockaddr_in* addr, char* protocol);

void error(int status, int err, char* fmt, ...);

void server(SOCKET s, struct sockaddr_in* peer_addr);

SOCKET tcp_server(char* host_name, char* port_name);

#endif
