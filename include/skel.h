#ifndef __SKEL_H__
#define __SKEL_H__

char* program_name;

#define INIT() 		(program_name = strrchr(argv[0], '/') ? program_name++ : (program_name = argv[0]))	

#define EXIT(s) exit( s )

#define CLOSE(s) if ( close(s) ) error(1, errno, "close failed")

#define SET_ERRNO(e) errno = e

#define IS_VALID_SOCKET(s) ( ( s ) >= 0)

typedef int SOCKET;

#define LISTEN_BACKLOG 10

#endif
