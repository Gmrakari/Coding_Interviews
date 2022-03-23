

/*
 * Date:2022-03-23 09:57
 * filename:m_write_function.cpp
 *
 */

#include <sys/types.h>  //ssize_t
#include <unistd.h>     //read
#include <errno.h>      //errno

ssize_t readn(int fd, void *buff, size_t n) {
	size_t nleft = n;
	ssize_t nread = 0;
	ssize_t readSum = 0; 

	char *ptr = (char*)buff;

	while (nleft > 0) {
		if ((nread = read(fd, ptr, nleft)) < 0) {
			if (errno == EINTR) 
				nread = 0;
			else if (errno == EAGAIN)
				return readSum;
			else 
				return -1;
		}
		else if (nread == 0)
			break;
		readSum += nread;
		nleft -= nread;
		ptr += nread;
	}
	return readSum;
}

ssize_t writen(int fd, void *buff, size_t n) {
	size_t nleft = n;
	ssize_t nwritten = 0;
	ssize_t writeSum = 0;
	char *ptr = (char*)buff;

	while (nleft > 0) {
		if ((nwritten = write(fd, ptr, nleft)) <= 0) {
			if (nwritten < 0) {
				if (errno == EINTR || errno == EAGAIN) {
					nwritten = 0;
					continue;
				}
				else
					return -1;
			}
		}
		writeSum += nwritten;
		nleft -= nwritten;
		ptr += nwritten;
	}
	return writeSum;
}

int write_short_data(short value, char *buf) {
	if (buf == NULL)
		return -1;

	char *ptr = (char*)buf;

	short nleft = value;
	short nwritten = 0;

	while (nleft > 0) {


	}
}
