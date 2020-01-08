/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_unsigned_fd.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 16:09:30 by jlensing       #+#    #+#                */
/*   Updated: 2019/12/03 17:29:24 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	if (n > 4294967295)
	{
		ft_putstr_fd(1, "4294967295", 10);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd(fd, '-');
		ft_putnbr_unsigned_fd(-n, fd);
	}
	if (n >= 10)
	{
		ft_putnbr_unsigned_fd(n / 10, fd);
		ft_putchar_fd(fd, (n % 10) + '0');
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd(fd, n + '0');
	}
}
