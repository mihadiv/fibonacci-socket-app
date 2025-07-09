#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8822
#define MAX 1024

int main() {
    int sockfd;
    struct sockaddr_in servaddr; 
    char buffer[MAX];  // for server response
    char input[10];    // for user input

    // Create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Configure server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("37.120.249.45");
    
    // Connect socket to the server
    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    // Ask user to enter a number
    printf("Enter a number (n) to get Fibonacci + sum: ");
    fgets(input, sizeof(input), stdin);

    // Send number to the server
    write(sockfd, input, strlen(input));
    
    // Receive response from the server
    int bytes = read(sockfd, buffer, sizeof(buffer) - 1);
    if (bytes >= 0) {
        buffer[bytes] = '\0'; // add null terminator
    }    

    // Display result
    printf("\n[CLIENT] Received from server s_fib_sum - by Divoiu Mihaela gr1088:\n%s\n", buffer);

    // Close connection
    close(sockfd);
    return 0;
}
