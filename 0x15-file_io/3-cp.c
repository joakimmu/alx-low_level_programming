#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* main - program that copies the content of a file to another file
* @diga: num argument
* @digb: string argument
* Return: 0
*/

int main(int diga, char *digb[])
{
int file_from, file_to;
int TT = 1024, WW = 0;
char buf[1024];

if (diga != 3)
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
file_from = open(digb[1], O_RDONLY);
if (file_from == -1)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", digb[1]);
	exit(98);
}
file_to = open(digb[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR
	| S_IRGRP | S_IWGRP | S_IROTH);
if (file_to == -1)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", digb[2]);
	close(file_from), exit(99);
}
while (TT == 1024)
{
	TT = read(file_from, buf, 1024);
	if (TT == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", digb[1]);
		exit(98);
	}
	WW = write(file_to, buf, TT);
	if (WW < TT)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", digb[2]), exit(99);
}

if (close(file_from) == -1)
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from), exit(100);

if (close(file_to) == -1)
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to), exit(100);

return (0);
}
