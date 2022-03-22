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

int main(int argc, char **argv)
{
	int		spid;
	int		i;
	t_client client;

	if (argc != 3)
		return (0);
	spid = atoi(argv[1]);
	printf("Sending to : %i\n", spid);
	i = 0;
	while (argv[2][i])
	{
		client.numbers = ascii_byte(argv[2][i]);
		send_byte(client.numbers, spid);
		i++;
	}
}