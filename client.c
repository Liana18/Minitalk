/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:24:08 by lter-zak          #+#    #+#             */
/*   Updated: 2022/09/27 21:22:14 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res);
}

void	ft_send_text(int pid, char *str)
{
	int	i;
	int	n;

	i = 0;
	while (str[i])
	{
		n = 7;
		while (n >= 0)
		{
			if (str[i] >> n & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			n--;
		}
		i++;
	}
}

int	main(int nb, char *str[])
{
	if (nb == 3)
		ft_send_text(ft_atoi(str[1]), str[2]);
	return (0);
}
