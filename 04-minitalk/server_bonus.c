/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:43:30 by csubires          #+#    #+#             */
/*   Updated: 2024/06/08 08:12:05 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	receive_msg(int sig_usr, siginfo_t *info, void *na)
{
	static unsigned char	bit_buff;
	static int				bit_pos;

	(void) na;
	bit_buff |= (sig_usr == SIGUSR1);
	bit_pos++;
	if (bit_pos == 8)
	{
		if (bit_buff == '\0')
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(bit_buff, 1);
		bit_pos = 0;
		bit_buff = 0;
	}
	else
		bit_buff <<= 1;
	if (sig_usr == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (sig_usr == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

void	set_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = receive_msg;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	set_signals();
	while (1)
		pause();
	return (0);
}
