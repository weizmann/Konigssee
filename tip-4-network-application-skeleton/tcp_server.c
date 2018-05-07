#include "inc.h"

void server(SOCKET s, struct sockaddr_in* peer_addr)
{
	printf("hello world\n");	
}

int main(int argc, char **argv) 
{
	INIT();
	
	struct sockaddr_in addr_local;
	struct sockaddr_in addr_client;
	char* host_name;
	char* port_name;

	SOCKET socket_local;
	SOCKET socket_client;

	if (argc == 2) 
	{
		host_name = NULL;
		port_name = argv[1];
	} 
	else if (argc == 3)
	{
		host_name = argv[1];
		port_name = argv[2];
	} else {
		printf("invalid params\n");
		EXIT(1);
	}

	socket_local = tcp_server(host_name, port_name);

	do 
	{
		int addr_len = sizeof(addr_client);
		socket_client = accept(socket_local, (struct sockaddr*) &addr_client, &addr_len);
		if (!IS_VALID_SOCKET(socket_client)) 
		{
			error(1, errno, "accept failed");
			server(socket_client, &addr_client);
			CLOSE(socket_client);
		}
	} while (1);

	EXIT(0);	
}
