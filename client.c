/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:43:29 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/11/02 18:38:17 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "ft_printf/ft_printf.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
}

void	bit_sender(int pid, char *str, size_t len)
{
	int		bit;
	size_t	c;

	c = 0;
	while (c < len)
	{
		bit = 0;
		while (bit < 7)
		{
			if ((str[c] >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(300);
		}
		c++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		str = argv[2];
		bit_sender(pid, str, ft_strlen(str));
		return (0);
	}
	else if (pid == 0)
	{
		ft_printf("Error: Wrong PID.\n");
		return (1);
	}
	else
		ft_printf("Error: Wrong number of arguments.\n");
	return (1);
}
