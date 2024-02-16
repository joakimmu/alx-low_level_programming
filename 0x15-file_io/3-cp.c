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
int PP, FF;
int TT = 1024, WW = 0;
char buf[1024];

if (diga != 3)
	dprintf(STDERR_FILENO, "Usage: cp PP FF\n"), exit(97);
PP = open(digb[1], O_RDONLY);
if (PP == -1)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", digb[1]);
	exit(98);
}
FF = open(digb[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR
	| S_IRGRP | S_IWGRP | S_IROTH);
if (FF == -1)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", digb[2]);
	close(PP), exit(99);
}
while (TT == 1024)
{
	TT = read(PP, buf, 1024);
	if (TT == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", digb[1]);
		exit(98);
	}
	WW = write(FF, buf, TT);
	if (WW < TT)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", digb[2]), exit(99);
}

if (close(PP) == -1)
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", PP), exit(100);

if (close(FF) == -1)
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", FF), exit(100);

return (0);
}
