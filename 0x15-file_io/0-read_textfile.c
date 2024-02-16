#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile -  prints it to the POSIX standard output
 * @filename: to be read
 * @letters: output
 *
 * Return: actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int ac;
	ssize_t A, B;
	char *buffer;

	if (filename == NULL)
		return (0);
	ac = open(filename, O_RDONLY);
	if (ac == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(ac);
		return (0);
	}
	A = read(ac, buffer, letters);
	close(ac);
	if (A == -1)
	{
		free(buffer);
		return (0);
	}
	B = write(STDOUT_FILENO, buffer, A);
	free(buffer);
	if (A != B)
		return (0);
	return (B);
}
