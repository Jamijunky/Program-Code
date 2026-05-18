#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int opt = 1;

    char buffer[1024] = {0};
    char reply[] = "Reply from server";

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket failed");
        return 1;
    }

    // Allow port reuse (IMPORTANT on macOS)
    if (setsockopt(server_fd,
                   SOL_SOCKET,
                   SO_REUSEADDR,
                   &opt,
                   sizeof(opt)) < 0) {
        perror("setsockopt failed");
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;

    // Change port to 9090 (safer than 8080)
    address.sin_port = htons(9090);

    // Bind
    if (::bind(server_fd,
             (struct sockaddr *)&address,
             sizeof(address)) < 0) {
        perror("Bind failed");
        return 1;
    }

    // Listen
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        return 1;
    }

    cout << "Server listening on port 9090..." << endl;

    new_socket = accept(server_fd,
                        (struct sockaddr *)&address,
                        (socklen_t*)&addrlen);

    if (new_socket < 0) {
        perror("Accept failed");
        return 1;
    }

    read(new_socket, buffer, 1024);
    cout << "Client message: " << buffer << endl;

    send(new_socket, reply, strlen(reply), 0);

    close(new_socket);
    close(server_fd);

    return 0;
}