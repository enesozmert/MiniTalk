/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:12:21 by eozmert           #+#    #+#             */
/*   Updated: 2022/03/29 14:34:39 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	idx_end(int *numbers, int *i, siginfo_t *siginfo)
{
	if (*i == 8)
	{
		kill(siginfo->si_pid, SIGUSR2);
		print_byte(numbers);
		*i = 0;
	}
}

void	print_byte(int *numbers)
{
	int	ascii;

	ascii = byte_ascii(numbers);
	ft_putchar_fd(ascii, 1);
}

void	sig_handler(int signum, siginfo_t *siginfo, void *unused)
{
	static int	idx = 0;
	static int	count[8];

	(void)unused;
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

int	main(void)
{
	struct sigaction	act;
	int					p_id;

	p_id = getpid();
	ft_bzero(&act, sizeof(act));
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sig_handler;
	if ((sigaction(SIGUSR1, &act, NULL)) == -1)
		ft_putstr_fd("Error sigaction\n", 1);
	if ((sigaction(SIGUSR2, &act, NULL)) == -1)
		ft_putstr_fd("Error sigaction\n", 1);
	ft_putnbr_fd(p_id, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		pause();
	}
	ft_putchar_fd('\n', 1);
}
