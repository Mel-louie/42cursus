/*
 * File: common.hpp
 * Project: sockets
 * Created Date: 24 Jan 2022
 * Author: mel louie
 * -----
 * Last Modified: Fri Dec 10 2021
 * Modified By: mel louie
 * -----
 * Copyright (c) 2021 mel louie
 * -----
 */

#ifndef COMMON_HPP
# define COMMON_HPP

# include <sys/socket.h>
# include <sys/types.h>
# include <signal.h>
// # include <cstdio>
# include <string>
# include <iostream>
# include <arpa/inet.h> /* for inet_pton and the like */
# include <cerrno>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/ioctl.h>
# include <netdb.h>
# include <cstring>

# define SERVER_PORT 18000

# define MAX_LINE 4096
# define	SA struct sockaddr

char	*bin2hex(const unsigned char *input, size_t len);

#endif // COMMON_HPP