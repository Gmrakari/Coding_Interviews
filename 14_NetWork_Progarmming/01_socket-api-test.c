

/*
 * Date:2021-12-06 09:35
 * filename:01_socket-api-test.c
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <ctype.h>

int socket(int domain, int type, int protocol);

int bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen);

void bzero(void *s, size_t n);

int inet_pton(int af, const char *src, void *dst);

uint32_t htonl(uint32_t hostlong);

uint16_t htons(uint16_t hostshort);

uint32_t ntohl(uint32_t netlong);

uint16_t ntohs(uint16_t netshort);

int listen(int sockfd, int backlog);

int accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen);

int connect(int sockfd, const struct sockaddr* addr, socklen_t addrlen);

ssize_t read(int fd, void *buf, size_t count);

ssize_t write(int fd, const void *buf, size_t count);

ssize_t send(int sockfd, const void *buf, size_t len, int flags);

ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,const struct sockaddr *dest_addr, socklen_t addrlen);

ssize_t sendmsg(int sockfd, const struct msghdr *msg, int flags);

ssize_t recv(int sockfd, void *buf, size_t len, int flags);

ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,

struct sockaddr *src_addr, socklen_t *addrlen);

ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags);

char *fgets(char *s, int size, FILE *stream);

int close(int fd);



