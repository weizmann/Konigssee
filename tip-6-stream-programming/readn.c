int readn(int fd, char* buffer, size_t len)
{
	int unread_count, read_count;
	unread_count = len;
	while (unread_count > 0)
	{
		read_count = recv(fd, buffer, count, 0);
		if (read_count < 0)	{
			if (errno == EINTR)
				continue;
			return -1;
		} else if (read_count == 0) {
			return len - unread_count;		
		} else {
			buffer += read_count;
			unread_count -= read_count;
		}
	}
	return len;
}
