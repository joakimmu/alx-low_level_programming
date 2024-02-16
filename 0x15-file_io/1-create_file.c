#include "main.h"

/**
 * create
 * @filename:.
 * @text:
 *
 * R
 */
#include "main.h"

int create_file(const char *filename, char *text_content)
{
	int ac;
	int nletters;
	int rwr;

	if (!filename)
		return (-1);

	ac = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (ac == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nletters = 0; text_content[nletters]; nletters++)
		;

	rwr = write(ac, text_content, nletters);

	if (rwr == -1)
		return (-1);

	close(ac);

	return (1);
}
