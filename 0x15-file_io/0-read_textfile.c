/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: The name of the file to read
 * @letters: The number of letters to read and print
 *
 * Return:  The actual number of letters read and printed, or 0 if an error occurs
 */
#include "main.h"
#include <stdlib.h>


ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t q;
	ssize_t w;
	ssize_t t;

	q = open(filename, O_RDONLY);
	if (q == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(q, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(q);
	return (w);
}

