#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* main - program that copies the content of a file to another file
* @argc: integer
* @argv: string 
* Return: if it succeeds return 0
*/

int main(int argc, char *argv[])
{
int file_from, file_to;
int Q = 1024, W = 0;
char buf[1024];

if (argc != 3)
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
file_from = open(argv[1], O_RDONLY);
if (file_from == -1)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
	exit(98);
}
file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR
	| S_IRGRP | S_IWGRP | S_IROTH);
if (file_to == -1)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
	close(file_from), exit(99);
}
while (Q == 1024)
{
	Q = read(file_from, buf, 1024);
	if (Q == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	W = write(file_to, buf, W);
	if (W < Q)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
}

if (close(file_from) == -1)
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from), exit(100);

if (close(file_to) == -1)
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to), exit(100);

return (0);
}
