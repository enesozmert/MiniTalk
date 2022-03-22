#include "header.h"

void print_byte(int *numbers)
{
	int ascii;

	ascii = byte_ascii(numbers);
	write(1, &ascii, 1);
}


void sig_handler(int sig_num)
{
	static int	idx = 0;
	static int	count[8] = {0};

	//count = (int *)malloc(sizeof(int) * 8);
	if (sig_num == SIGUSR2)
	{
		count[idx++] = 1;
		if (idx == 8)
		{
			print_byte(count);
			idx = 0;
		}
	}
	else if (sig_num == SIGUSR1)
	{
		count[idx++] = 0;
		if (idx == 8)
		{
			print_byte(count);
			idx = 0;
		}
	}
	//printf("\n i : %d client num : %d \n", idx ,count[idx]);
}

int main()
{
	struct sigaction	act;

	bzero(&act, sizeof(act));
	//bzero(&client.numbers, sizeof(client.numbers));
	act.sa_handler = &sig_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	printf("%i\n", getpid());
	while (1)
	{
		pause();
	}
}