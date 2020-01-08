/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 16:09:30 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/22 14:10:06 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n <= -2147483648)
	{
		ft_putchar_fd(fd, '-');
		ft_putchar_fd(fd, '2');
		ft_putnbr_fd(fd, 147483648);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd(fd, '-');
		ft_putnbr_fd(fd, -n);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(fd, n / 10);
		ft_putchar_fd(fd, (n % 10) + '0');
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd(fd, n + '0');
	}
}
