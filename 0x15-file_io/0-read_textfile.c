#include "main.h"
#include <stdlib.h>

/**
 * read_textfile -  reads a text file and prints it to the POSIX standard output
 * @filename: The name of the text file to be read.
 * @bytes_to_read: The number of bytes to read from the file.
 *
 * Return: The actual number of bytes read and printed (bytes_written),
 *         0 when the function fails or `filename` is NULL.
 */
ssize_t read_textfile(const char *filename, size_t bytes_to_read)
{
    char *buffer;
    ssize_t file_descriptor;
    ssize_t bytes_written;
    ssize_t bytes_read;

    if (filename == NULL)
        return (0);

    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1)
        return (0);

    buffer = malloc(sizeof(char) * bytes_to_read);
    if (buffer == NULL)
    {
        close(file_descriptor);
        return (0);
    }

    bytes_read = read(file_descriptor, buffer, bytes_to_read);
    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

    free(buffer);
    close(file_descriptor);

    return (bytes_written);
}

