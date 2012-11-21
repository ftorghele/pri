/*
 * main.cpp
 *
 *  Created on: Nov 14, 2012
 *      Author: torghele
 */

#include <iostream>
#include <cmath>

#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/un.h>

using namespace std;

void server()
{
	int s, s2, len;
	socklen_t t;
	struct sockaddr_un local_addr, remote_addr;
	float number;

	if ((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		cerr << strerror(errno) << endl;
		exit(1);
	}

	local_addr.sun_family = AF_UNIX;
	strcpy(local_addr.sun_path, "socket");
	unlink(local_addr.sun_path);
	len = strlen(local_addr.sun_path) + sizeof(local_addr.sun_family);

	if (bind(s, (struct sockaddr *)&local_addr, len) == -1) {
		cerr << strerror(errno) << endl;
		exit(1);
	}

	if (listen(s, 5) == -1) { // max 5 connections in queue
		cerr << strerror(errno) << endl;
		exit(1);
	}

	while(true) {
		int done, n;
		cout << "Waiting for a connection.." << endl;
		t = sizeof(remote_addr);
		if ((s2 = accept(s, (struct sockaddr *)&remote_addr, &t)) == -1) {
			cerr << strerror(errno) << endl;
			exit(1);
		}

		cout << "Connected." << endl;

		done = 0;
		do {
			n = recv(s2, &number, sizeof(number), 0);
			if (n <= 0) {
				if (n < 0) cerr << strerror(errno) << endl;
				done = 1;
			}

			if (!done)
				number = sqrt(number);
				if (send(s2, &number, n, 0) < 0) {
					cerr << strerror(errno) << endl;
					done = 1;
				}
		} while (!done);

		close(s2);
	}
}

void client()
{
	int s, t, len;
	struct sockaddr_un remote_addr;
	float number;

	if ((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		cerr << strerror(errno) << endl;
		exit(1);
	}

	cout << "Trying to connect.." << endl;

	remote_addr.sun_family = AF_UNIX;
	strcpy(remote_addr.sun_path, "socket");
	len = strlen(remote_addr.sun_path) + sizeof(remote_addr.sun_family);

	if (connect(s, (struct sockaddr *)&remote_addr, len) == -1) {
		cerr << strerror(errno) << endl;
		exit(1);
	}

	cout << "connected." << endl;

	while(true) {
		cout << "Enter a number:";
		if (!(cin >> number)) {
		    cout << "You did not enter a correct number!" << endl;
		    exit(1);
		}

		if (send(s, &number, sizeof(number), 0) == -1) {
			cerr << strerror(errno) << endl;
			exit(1);
		}

		if ((t=recv(s, &number, sizeof(number), 0)) > 0) {
			cout << number << endl;
		} else {
			if (t < 0) cerr << strerror(errno) << endl;
			else cout << "Server closed connection." << endl;
			exit(1);
		}
	}

	close(s);
}

int main() {

	int type;

	std::cout << "1: Server" << std::endl;
	std::cout << "2: Client" << std::endl;
	std::cout << "Chose: ";
	std::cin >> type;

	if ( type == 1 ) server();
	else if (type == 2 ) client();
	else std::cout << "wrong input.. aborting" << std::endl;

    return 0;
}
