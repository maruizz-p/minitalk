/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:59:05 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/10/28 17:53:44 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <signal.h>
# include <unistd.h>

static size_t	ft_strlen(char *str);
static int		ft_atoi(const char *str);
void			bit_sender(int pid, char *str, size_t len);
int				main(int argc, char **argv);
extern int		ft_printf(const char *str, ...);
#endif