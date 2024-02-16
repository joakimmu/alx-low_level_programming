#include "main.h"

/**
 * create_file - creates a file
 * @filename: name of the file.
 * @text_content: text appended .
 *
 * Return: 1  is succesiful.
 */
int create_file(const char *filename, char *text_content)
{
	int ac;
	int jkm;
	int PB;

	if (!filename)
		return (-1);

	ac = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (ac == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (jkm = 0; text_content[jkm]; jkm++)
		;

	PB = write(ac, text_content, jkm);

	if (PB == -1)
		return (-1);

	close(ac);

	return (1);
}
