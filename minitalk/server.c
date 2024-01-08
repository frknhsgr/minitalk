/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:28:35 by fhosgor           #+#    #+#             */
/*   Updated: 2023/12/15 16:16:22 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signalprocesser(int signal)
{
	static char	c;
	static int	i;

	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	(void)av;
	if (ac == 1)
	{
		pid = getpid();
		ft_printf("%d\n", pid);
		signal(SIGUSR1, ft_signalprocesser);
		signal(SIGUSR2, ft_signalprocesser);
		while (1)
		{
			pause();
		}
	}
	else
		write(1, "ERROR!", 6);
}
