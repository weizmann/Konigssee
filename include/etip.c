#include "etip.h"

void set_address(char* host_name, char* port_name, struct sockaddr_in* addr, char* protocol)
{
	struct servent *sp;
	struct hostent *hp;
	char* endptr;
	short port;

	bzero(addr, sizeof(*addr));
	addr->sin_family = AF_INET;

	if (host_name != NULL)
	{
		if (!inet_aton(host_name, &addr->sin_addr))
		{
			hp = gethostbyname(host_name);
			if (hp == NULL)
			{
				error(1, 0, "unknown host: %s\n", host_name);
			}
			addr->sin_addr = *(struct in_addr *)hp->h_addr;
		}
	}
	else
	{
		printf("a");
		addr->sin_addr.s_addr = htonl(INADDR_ANY);
		port = strtol(port_name, &endptr, 0);
		if (*endptr == '\0')
		{
			addr->sin_port = htons(port);
		}
		else
		{
			sp = getservbyname(port_name, protocol);
			if (sp == NULL)
			{
				error(1, 0, "unknown service: %s\n", port_name);
			}
			addr->sin_port = sp->s_port;
		}
	}
}

void error(int status, int err, char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	fprintf(stderr, "%s: ", program_name);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	if (err) 
	{
		fprintf(stderr, ": %s (%d)\n", strerror(err), err);	
	}

	if (status)
	{
		EXIT(status);
	}
}

SOCKET tcp_server(char* host_name, char* port_name)
{
	SOCKET s;
	struct sockaddr_in addr_local;

	set_address(host_name, port_name, &addr_local, "tcp");
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (!IS_VALID_SOCKET(s))
	{
		error(1, errno, "socket call failed");
	}

	if (bind(s, (struct sockaddr *)&addr_local, sizeof(addr_local))) 
	{
		error(1, errno, "bind failed");
	}

	if (listen(s, LISTEN_BACKLOG)) 
	{
		error(1, errno, "listen failed");
	}

	return s;
}
