//
// Created by anisl on 12/27/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>

#define FLAG_FILE "flag.txt"
#define SHOULD_BE_BIGGER_BUF 64
#define MAX_BUF 1024
// Default port number
#define DEFAULT_PORT 2025

#define MSG_BANNER "I only give the flag to those who already have it. Duh!\n"
#define MSGLEN_BANNER (strlen(MSG_BANNER))

#define MSG_ASK_FOR_INPUT "What do you think the flag's value is?\n Enter your guess: "
#define MSGLEN_ASK_FOR_INPUT (strlen(MSG_ASK_FOR_INPUT))

#define MSG_INCORRECT "You obviously don't have the flag, come back in 5 seconds.\n"
#define MSGLEN_INCORRECT (strlen(MSG_INCORRECT))

char flag_value[MAX_BUF];

int is_valid_port(const char *str);

int ask_for_flag_and_check_if_it_is_correct(int client_fd, int server_fd);

int main(int argc, char *argv[]) {

    int server_fd, client_fd, port;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    FILE *flag_file;

    // Check if a port is provided in argv[1]
    if (argc > 1) {
        // Validate the port argument
        if (!is_valid_port(argv[1])) {
            fprintf(stderr, "Error: Invalid port number\n");
            exit(EXIT_FAILURE);
        }
        port = atoi(argv[1]);
    } else {
        port = DEFAULT_PORT;  // Use default port if not provided
    }

    // Open the file containing the flag_value string
    flag_file = fopen(FLAG_FILE, "r");
    if (flag_file == NULL) {
        perror("Could not open flag.txt");
        exit(EXIT_FAILURE);
    }

    // Read the flag_value string from the first line of the file
    if (fgets(flag_value, MAX_BUF, flag_file) == NULL) {
        perror("Could not read from flag.txt");
        fclose(flag_file);
        exit(EXIT_FAILURE);
    }

    // Remove trailing newline character if it exists
    flag_value[strcspn(flag_value, "\n")] = '\0';

    fclose(flag_file); // Close the flag.txt file

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) == -1) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", port);

    // Accept a connection from a client
    if ((client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &addr_len)) == -1) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Client connected!\n");

    send(client_fd, MSG_BANNER, MSGLEN_BANNER, 0);
    while (1) {
        // Compare the received string with the flag_value from the file
        printf("Asking for flag value.\n");
        if (ask_for_flag_and_check_if_it_is_correct(client_fd, server_fd) == 0) {
            printf("Flag value is correct!\n");
            // Spitting out the flag's value
            send(client_fd, flag_value, strlen(flag_value), 0);
            break; // Exit the loop if the correct string is entered
        } else {
            printf("Flag value is incorrect.\n");
            send(client_fd, MSG_INCORRECT, MSGLEN_INCORRECT, 0);
            sleep(5);
        }
    }

    // Close the client and server sockets
    close(client_fd);
    close(server_fd);
    printf("Server shutting down.\n");

    return 0;
}


// Function to check if a string is a valid integer
int is_valid_port(const char *str) {
    // Check if the string is empty
    if (*str == '\0') {
        return 0;  // Empty string is not a valid port number
    }

    // Check if every character in the string is a digit
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit((unsigned char) str[i])) {
            return 0;  // Contains non-digit character, so it's not a valid port
        }
    }

    // Convert the string to an integer
    int port = atoi(str);

    // Check if the port is within the valid range (1-65535)
    if (port >= 1 && port <= 65535) {
        return 1;  // Valid port
    }

    return 0;  // Port is out of range
}

int ask_for_flag_and_check_if_it_is_correct(int client_fd, int server_fd) {
    ssize_t bytes_read;
    char small_buffer[SHOULD_BE_BIGGER_BUF];
    // Ask for a string input
    send(client_fd, MSG_ASK_FOR_INPUT, MSGLEN_ASK_FOR_INPUT, 0);
    // Receive the string from the client
    printf("Reading data...\n");
    bytes_read = recv(client_fd, small_buffer, MAX_BUF, 0);
    if (bytes_read == -1) {
        perror("Recv failed");
        close(client_fd);
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    // Remove trailing newline if present
    small_buffer[bytes_read - 1] = '\0';

    printf("Comparing strings and returning the difference...\n");
    return strcmp(small_buffer, flag_value);
}


