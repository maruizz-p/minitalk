/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:58:59 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/11/02 15:51:13 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <signal.h>
# include <unistd.h>

typedef struct s_bit_keeper
{
	int		i;
	char	c;
}			t_bit_keeper;

void		bit_receptor(int bit);
extern int	ft_printf(const char *str, ...);
#endif