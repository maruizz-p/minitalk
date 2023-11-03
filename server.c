/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:43:34 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/11/02 15:53:11 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "server.h"

typedef struct s_bit_keeper	t_bit_keeper;

void	bit_receptor(int bit)
{
	static t_bit_keeper	bit_keeper;

	bit_keeper.c += ((bit & 1) << bit_keeper.i);
	bit_keeper.i++;
	if (bit_keeper.i == 7)
	{
		ft_printf("%c", bit_keeper.c);
		if (!bit_keeper.c)
			ft_printf("\n");
		bit_keeper.i = 0;
		bit_keeper.c = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, bit_receptor);
		signal(SIGUSR2, bit_receptor);
	}
	return (0);
}
