#include "inc.h"

int main(int argc, char **argv) 
{
	INIT();

	struct sockaddr_in addr_local, addr_peer;
	char* host_name, port_name;

	SOCKET socket_local, socket_client;

	if (argc == 2) 
	{
		host_name = NULL;
		port_name = argv[1];
	} 
	else
	{
		host_name = argv[1];
		port_name = argv[2];
	}
	

	set_address(host_name, port_name, &addr_local, "tcp");

	socket_local = socket(AF_INET, SOCK_STREAM, 0);
	if (!IS_VALID_SOCKET(socket_local))
	{
		error(1, errno, "socket call failed");
	}

	EXIT(0);	
}
