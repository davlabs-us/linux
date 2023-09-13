#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    const char *hostname = "canhazip.com"; // Replace with the website hostname
    const char *path = "/"; // Replace with the specific path if needed

    // Resolve the hostname to an IP address
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: Cannot resolve hostname.\n");
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Initialize the server_addr structure
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    // Create the HTTP request
    char request[MAX_BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);

    // Send the HTTP request
    if (write(sockfd, request, strlen(request)) < 0) {
        error("Error writing to socket");
    }

    // Receive and display the response
    char buffer[MAX_BUFFER_SIZE];
    bzero(buffer, sizeof(buffer));
    int n;
    while ((n = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        printf("%s", buffer);
        bzero(buffer, sizeof(buffer));
    }

    if (n < 0) {
        error("Error reading from socket");
    }

    // Close the socket
    close(sockfd);

    return 0;
}

