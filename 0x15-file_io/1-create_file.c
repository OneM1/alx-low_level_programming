#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int create_file(const char *filename, char *text_content) {
    int fd;
    ssize_t n_written;

    if (filename == NULL)
        return (-1);

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (fd == -1)
        return (-1);

   
    if (text_content != NULL) {
        n_written = write(fd, text_content, strlen(text_content));
        if (n_written == -1) {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}

