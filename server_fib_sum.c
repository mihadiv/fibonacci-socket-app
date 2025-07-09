#include <stdio.h>      // for input/output
#include <stdlib.h>     // for functions like atoi()
#include <string.h>     // for string manipulation functions (strcat, sprintf)
#include <unistd.h>     // for read, write, close
#include <arpa/inet.h>  // for working with IP addresses and sockets

#define PORT 8822       // TCP port the server listens on
#define MAX 1024        // maximum buffer size

// Function that computes the first n Fibonacci terms and their sum
void compute_fibonacci(int n, int* seq, int* sum) {
    seq[0] = 0;
    if (n > 1) seq[1] = 1;
    *sum = seq[0] + (n > 1 ? seq[1] : 0);

    for (int i = 2; i < n; i++) {
        seq[i] = seq[i-1] + seq[i-2];  // each term is the sum of the previous two
        *sum += seq[i];                // accumulate the total sum
    }
}

int main() {

    int sockfd, newsockfd, len, n, sum;
    struct sockaddr_in servaddr, client;
    char buffer[MAX];      // buffer for reading from client
    int fib[100];          // array for Fibonacci sequence

    // Create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set IP address and port
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("37.120.249.45");
    servaddr.sin_port = htons(PORT);

    // Bind socket to IP and port
    bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    // Put socket into listening mode
    listen(sockfd, 1);
    printf("\n[SERVER] Listening on 37.120.249.45:%d...\n", PORT);

    // Accept a connection from a client
    len = sizeof(client);
    newsockfd = accept(sockfd, (struct sockaddr*)&client, &len);
    
    // Receive number n from client
    read(newsockfd, buffer, sizeof(buffer));
    n = atoi(buffer);  // convert input string to integer

    // Compute Fibonacci sequence and sum
    compute_fibonacci(n, fib, &sum);

    // Create response message
    char response[MAX] = "The Fibonacci sequence with ";
    char num[10];
    sprintf(num, "%d", n);
    strcat(response, num);
    strcat(response, " element/s is: ");

    for (int i = 0; i < n; i++) {
        char temp[20];
        sprintf(temp, "%d ", fib[i]);  // append each term to the message
        strcat(response, temp);
    }

    // Append the sum
    char temp[50];
    sprintf(temp, "| SUM = %d", sum);
    strcat(response, temp);

    response[MAX - 1] = '\0';  // ensure the message is null-terminated

    // Send message back to client
    write(newsockfd, response, strlen(response));
    printf("[SERVER] Sent to c_fib_sum - by Divoiu Mihaela gr1088:\n%s\n", response);

    // Close connection
    close(newsockfd);
    close(sockfd);
    return 0;
}
