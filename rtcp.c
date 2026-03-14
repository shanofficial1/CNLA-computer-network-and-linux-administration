#include <stdio.h>          // printf(), perror()
#include <stdlib.h>         // exit()
#include <unistd.h>         // fork(), close(), sleep()
#include <sys/socket.h>     // socket(), bind(), listen(), accept(), connect(), send(), recv()
#include <netinet/in.h>     // sockaddr_in
#include <arpa/inet.h>      // inet_addr(), htons()

#define PORT 5000           // Port number

int main() {
    int server_fd, client_fd;            // For server socket and accepted client socket
    struct sockaddr_in server_addr;      // Server address structure
    socklen_t addr_len = sizeof(server_addr);
    pid_t pid;
    int i;

    // ---------- SERVER SETUP (done before fork) ----------

    // 1. Create TCP socket for server
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(1);
    }

    // 2. Fill server address details
    server_addr.sin_family = AF_INET;           // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY;   // Listen on all interfaces
    server_addr.sin_port = htons(PORT);         // Port in network byte order

    // 3. Bind socket to IP and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // 4. Put socket into listening mode
    if (listen(server_fd, 1) == -1) {
        perror("listen");
        exit(1);
    }

    // ---------- CREATE CHILD PROCESS ----------

    pid = fork();                      // Create child
    if (pid == -1) {                   // Error in fork
        perror("fork");
        exit(1);
    }

    // ---------- CHILD PROCESS (acts as CLIENT) ----------
    if (pid == 0) {
        int sock_fd, num;
        struct sockaddr_in serv_addr;

        // Small delay to ensure parent is listening
        sleep(1);

        // a) Create client socket
        sock_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (sock_fd == -1) {
            perror("socket (client)");
            exit(1);
        }

        // b) Set server (parent) address to connect to
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);
        serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // connect to localhost

        // c) Connect to the server socket
        if (connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
            perror("connect");
            exit(1);
        }

        printf("Child (client): odd numbers are: ");

        // d) Receive 10 numbers and print only odd ones
        for (i = 0; i < 10; i++) {
            if (recv(sock_fd, &num, sizeof(num), 0) == -1) {
                perror("recv");
                exit(1);
            }

            if (num % 2 != 0) {        // check if odd
                printf("%d ", num);
            }
        }

        printf("\nChild (client): done.\n");

        // e) Close client socket
        close(sock_fd);
        return 0;                      // Child exits
    }

    // ---------- PARENT PROCESS (acts as SERVER) ----------
    else {
        printf("Parent (server): waiting for child to connect...\n");

        // a) Accept connection from child client
        client_fd = accept(server_fd, (struct sockaddr *)&server_addr, &addr_len);
        if (client_fd == -1) {
            perror("accept");
            exit(1);
        }

        printf("Parent (server): sending numbers 1 to 10...\n");

        // b) Send numbers 1..10 to child
        for (i = 1; i <= 10; i++) {
            if (send(client_fd, &i, sizeof(i), 0) == -1) {
                perror("send");
                exit(1);
            }
        }

        printf("Parent (server): done sending.\n");

        // c) Close sockets
        close(client_fd);
        close(server_fd);

        // d) Optionally wait for child to finish
        // wait(NULL);   // you can include <sys/wait.h> and uncomment this if needed

        return 0;       // Parent exits
    }
}
