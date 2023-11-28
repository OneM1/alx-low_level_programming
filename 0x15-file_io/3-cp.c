#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

#define BUF_SIZE 1024

/**
 * close_file - Closes a file descriptor and handles errors.
 * @fd: The file descriptor to close.
 * @filename: The name of the file associated with the file descriptor.
 *
 * Description: Attempts to close a file descriptor. If an error occurs, an
 * error message is printed and the program exits with code 100.
 */
void close_file(int fd, char *filename) {
    if (close(fd) < 0) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d for file %s\n", fd, filename);
        exit(100);
    }
}

/**
 * main - Copies the content of one file to another.
 * @argc: Argument count.
 * @argv: contains the names of the source and destination files.
 *
 * Description: Copies the contents from 'file_from' to 'file_to'. If 'file_to' already exists, it is truncated.
 * Exits with different status codes depending on the type of error encountered (if any).
 * Usage: cp file_from file_to
 * The program exits with code 97 if the number of arguments is incorrect, with code 98 if the source file
 * cannot be read, with code 99 if the destination file cannot be written to, and with code 100 if file descriptors
 * cannot be closed.
 *
 * Return: 0 on success, or the relevant exit code on failure.
 */
int main(int argc, char *argv[]) {
    int fd_from, fd_to, read_bytes, write_bytes;
    char buffer[BUF_SIZE];

    if (argc != 3) {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from < 0) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (fd_to < 0) {
        close_file(fd_from, argv[1]);
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        exit(99);
    }

    while ((read_bytes = read(fd_from, buffer, BUF_SIZE)) > 0) {
        write_bytes = write(fd_to, buffer, read_bytes);
        if (write_bytes != read_bytes) {
            close_file(fd_from, argv[1]);
            close_file(fd_to, argv[2]);
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            exit(99);
        }
    }

    if (read_bytes < 0) {
        close_file(fd_from, argv[1]);
        close_file(fd_to, argv[2]);
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    close_file(fd_from, argv[1]);
    close_file(fd_to, argv[2]);
    return 0;
}

