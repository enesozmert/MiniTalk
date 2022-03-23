#include "header.h"

void idx_end(int *numbers, int *i, siginfo_t *siginfo)
{
	if (*i == 8)
	{
		kill(siginfo->si_pid, SIGUSR2);
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

void sig_handler(int signum, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	static int	idx = 0;
	static int	count[8];

	if (signum == SIGUSR2)
	{
		count[idx++] = 1;
		idx_end(count, &idx, siginfo);
	}
	else if (signum == SIGUSR1)
	{
		count[idx++] = 0;
		idx_end(count, &idx, siginfo);
	}
}

int main()
{
	struct sigaction	act;
	int p_id;

	p_id = getpid();
	bzero(&act, sizeof(act));
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_putnbr_fd(p_id,1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		pause();
	}
	ft_putchar_fd('\n', 1);
}