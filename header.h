#ifndef HEADER_H
#define HEADER_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>

typedef struct c_client
{
	int p_id;
	int *numbers;
} t_client;


int *ascii_byte(int c);
int *convert(char* c);
int	ft_iterative_power(int nb, int power);
int mini_atoi(char *str);
void sig_handler(int sig_num);
void send_byte(int *byte, int pid);
void print_byte(int *numbers);
int byte_ascii(int *numbers);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void idx_end(int *numbers, int *i);

#endif
