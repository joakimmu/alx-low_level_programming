#include "main.h"

ssize_t _strlen(const char *str)
{
	ssize_t len = 0;

	if (!str)
		return (-1);

	while (*str++)
		++len;

	return (len);
}

/**
 * append_text_to_file - append text to the end of a file
 * @filename: the name of the file to append to
 * @text_content: the data to append to filename
 *
 * Return: Upon success, return 1. Otherwise, return -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t b_written = 0;
	int ac;

	if (!filename)
		return (-1);

	ac = open(filename, O_WRONLY | O_APPEND);

	if (ac < 0)
		return (-1);

	if (text_content)
		b_written = write(ac, text_content, _strlen(text_content));

	close(ac);

	if (b_written < 0)
		return (-1);
	return (1);
}
