/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 19:17:52 by jlensing       #+#    #+#                */
/*   Updated: 2019/12/03 17:21:27 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"

void	ft_putstr_fd(int fd, char *str, int n)
{
	int i;

	i = 0;
	while (str[i] && i < n)
	{
		ft_putchar_fd(fd, str[i]);
		i++;
	}
}
