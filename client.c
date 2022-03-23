#include "header.h"

void send_byte(int *byte, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (byte[i] == 1)
			kill(pid, SIGUSR2);
		else if (byte[i] == 0)
			kill(pid, SIGUSR1);
		usleep(100);
		i++;
	}
}

void	sig_fback(int pid, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	(void)siginfo;
	(void)pid;
	write(1, "Signal Delivered\n", 17);
}

int main(int argc, char **argv)
{
	int		spid;
	int		i;
	t_client client;
	struct sigaction	act;

	if (argc != 3)
		return (0);
	spid = ft_atoi(argv[1]);
	client.p_id = spid;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sig_fback;
	if ((sigaction(SIGUSR2, &act, 0)) == -1)
		ft_putstr_fd("Signal send error \n", 1);
	ft_putstr_fd("Sending to : ", 1);
	ft_putnbr_fd(spid, 1);
	ft_putchar_fd('\n', 1);
	i = 0;
	while (argv[2][i])
	{
		client.numbers = ascii_byte((unsigned char)argv[2][i]);
		send_byte(client.numbers, spid);
		i++;
	}
}