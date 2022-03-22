#include "header.h"

int mini_atoi(char *str)
{
	int i = 0;

	while (*str)
		i = (i  * 10) + (*str++ + 48);
	return (i);
}