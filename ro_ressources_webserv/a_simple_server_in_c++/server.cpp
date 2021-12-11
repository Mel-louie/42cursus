/*
 * File: server.cpp
 * Project: a_simple_server_in_c++
 * Created Date: 10 Dec 2021
 * Author: mel louie
 * -----
 * Last Modified: Fri Dec 10 2021
 * Modified By: mel louie
 * -----
 * Copyright (c) 2021 mel louie
 * -----
 */

// from https://ncona.com/2019/04/building-a-simple-server-with-cpp/
// from https://medium.com/from-the-scratch/http-server-what-do-you-need-to-know-to-build-a-simple-http-server-from-scratch-d1ef8945e4fa

#include <sys/socket.h>
#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

int	main( void )
{
	// 1
	/* Create a socket (IPv4, TCP).
	A socket can be seeen as a file descriptor that can be used for
	communication.
	A socket defines an "entry point" into the TCP/IP stack of the OS.
	The socket is characterized by a TCP/UDP port and when it is created,
	the machine "listens" through this socket to process connection and
	data exchange requests.
	Conceptually, we can say that a socket allows to " canalize " the
	incoming flow relative to a certain TCP/UDP port.*/
	int socketFd = socket(AF_INET, SOCK_STREAM, 0);
	if ( socketFd < 0 )
	{
		std::cout << "Failed to create socket. errno: " << errno << std::endl;
		exit(EXIT_FAILURE);
	}

	// 2
	/* Once we have the socket, we need to use bind to assign an IP address
	and port to the socket.
	int bind(int sockfd, const sockaddr *addr, socklen_t addrlen);
	addr is a struct used to specify the address we want to assign to the socket.
	The exact struct that needs to be used to define the address, varies by
	protocol. Since we are going to use IP for this server, we will use sockaddr_in
	struct sockaddr_in {
		sa_family_t    sin_family; >> address family: AF_INET 
		in_port_t      sin_port;   >> port in network byte order 
  		 struct in_addr sin_addr;  >> internet address
	};
	
	Listen to port 9999 on any address: */
	sockaddr_in	sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = INADDR_ANY;
	sockaddr.sin_port = htons(PORT); // htons is necessary to convert a number to
                                   // network byte order
	if ( bind(socketFd, (struct sockaddr*)&sockaddr, sizeof(sockaddr)) < 0 )
	{
		std::cout << "Failed to bind to port 8080. errno: " << errno << std::endl;
		exit(EXIT_FAILURE);
	}


	// 3
	/* listen marks a socket as passive. i.e. The socket will be used to accept connections.
	int listen(int sockfd, int backlog);
	sockfd is the file descriptor of the socket.
	backlog is the maximum number of connections that will be queued before connections
	start being refused.

	Start listening. Max 10 connexion in the queue */
	if ( listen(socketFd, 10) < 0 )
	{
		std::cout << "Failed to listen on socket. errno: " << errno << std::endl;
    	exit(EXIT_FAILURE);
	}

	// 4
	/*accept extracts an element from a queue of connections (The queue created by listen)
	for a socket.
	int accept(int sockfd, sockaddr *addr, socklen_t *addrlen);
	The argument list is similar to the one for bind, with one difference. addrlen is now
	a value-result argument. It expects a pointer to an int that will be the size of addr.
	After the function is executed, the int refered by addrlen will be set to the size of
	the peer address.

	Grab a connection from the queue
	*/
	
	while (1)
	{
		std::cout << "Waiting for connections" << std::endl;
		int newsocket;
		int addrlen = sizeof(sockaddr);
        if ((newsocket = accept(socketFd, (struct sockaddr *)&sockaddr, (socklen_t*)&addrlen)) < 0)
        {
            std::cout << "Failed to grab connection. errno: " << errno << std::endl;
    		exit(EXIT_FAILURE);
        }
        
	// 5
	/* Communication */
        char buffer[30000] = {0};
		int byteRead;
		char *hello = "Hello from server";
        byteRead = read( newsocket , buffer, 30000);
		std::cout << buffer << std::endl;
        write(newsocket , hello , strlen(hello));
		std::cout << "Hello message sent" << std::endl;
	
		close(newsocket);
	}

	// Close the connections
	close(socketFd);

	return ( 0 );
}

