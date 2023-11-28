#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * create_file - Creates a file and writes text to it.
 * @filename: Name of the file to create.
 * @text_content: Text to write into the file.
 * Description: This function creates a file with the specified name and writes
 * the provided text into it
 * returns -1 on failure and 1 on success.
 **/
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t n_written;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
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









