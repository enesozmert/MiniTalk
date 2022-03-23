#include "header.h"

void idx_end(int *numbers, int *i)
{
	if (*i == 8)
	{
		print_byte(numbers);
		*i = 0;
	}
}

void print_byte(int *numbers)
{
	int ascii;

	ascii = byte_ascii(numbers);
	ft_putchar_fd(ascii, 1);
}

void sig_handler(int sig_num)
{
	static int	idx = 0;
	static int	count[8];

	if (sig_num == SIGUSR2)
	{
		count[idx++] = 1;
		idx_end(count, &idx);
	}
	else if (sig_num == SIGUSR1)
	{
		count[idx++] = 0;
		idx_end(count, &idx);
	}
}

int main()
{
	struct sigaction	act;
	int p_id;

	p_id = getpid();
	bzero(&act, sizeof(act));
	act.sa_handler = &sig_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	if ((sigaction(SIGUSR1, &act, 0)) == -1)
		ft_putstr_fd("Error sigaction \n", -1);
	if ((sigaction(SIGUSR2, &act, 0)) == -1)
		ft_putstr_fd("Error sigaction \n", -1);
	ft_putnbr_fd(p_id,1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		pause();
	}
	ft_putchar_fd('\n', 1);
}