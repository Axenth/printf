/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 19:17:52 by jlensing       #+#    #+#                */
/*   Updated: 2020/01/10 16:58:14 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft_func.h"

struct s_info	ft_putstr_fd(int fd, char *str, int n, struct s_info info)
{
	int i;

	i = 0;
	while (str[i] && i < n)
	{
		info = ft_putchar_fd(fd, str[i], info);
		i++;
	}
	return (info);
}
