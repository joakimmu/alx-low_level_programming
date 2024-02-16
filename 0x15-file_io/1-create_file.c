#include "main.h"
/**
 * create_file - Creates a file with specified filename and writes text content
 * @filename: The name of the file to create
 * @text_content: The NULL-terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 *         (file can not be created, file can not be written, write "fails", etc...)
 *
 * Description: The created file must have permissions rw-------.
 *              If the file already exists, truncate it.
 *              If filename is NULL, return -1.
 *              If text_content is NULL, create an empty file.
 */
int create_file(const char *filename, char *text_content)
{
	int ac;
	int Z;
	int H;

	if (!filename)
		return (-1);

	ac = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (ac == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (Z = 0; text_content[Z]; Z++)
		;

	H = write(ac, text_content, Z);

	if (H == -1)
		return (-1);

	close(ac);

	return (1);
}
