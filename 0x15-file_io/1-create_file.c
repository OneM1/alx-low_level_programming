#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: The name of the file to be created.
 * @text_content: The text to write into the file.
 *
 * Description: This function creates a file with the specified name and writes
 * the provided text into it. If the file already exists, it truncates it. The
 * function returns -1 on failure, 1 on success.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t n_written;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL) {
		n_written = write(fd, text_content, strlen(text_content));
		if (n_written == -1) 
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

