#include "main.h"

/**
 * append_text_to_file - adds text to the end 
 * @filename: filename of the file text is added.
 * @text_content: modified content.
 *return:0
 * Return: 1 if it is a pass
 * for fail iys -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int ac;
	int jkm;
	int PB;

	if (!filename)
		return (-1);

	ac = open(filename, O_WRONLY | O_APPEND);

	if (ac == -1)
		return (-1);

	if (text_content)
	{
		for (jkm = 0; text_content[jkm]; jkm++)
			;

		PB = write(ac, text_content, jkm);

		if (PB == -1)
			return (-1);
	}

	close(ac);

	return (1);
}
