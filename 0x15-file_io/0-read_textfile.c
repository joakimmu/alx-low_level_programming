/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: The name of the file to read
 * @letters: The number of letters to read and print
 *
 * Return: The actual number of letters read and printed, or 0 if an error occurs
 */



#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

 
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t T, W;
	char *buffer;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}
	T = read(fd, buffer, letters);
	close(fd);
	if (T == -1)
	{
		free(buffer);
		return (0);
	}
	W = write(STDOUT_FILENO, buffer, T);
	free(buffer);
	if (T != W)
		return (0);
	return (W);
}
