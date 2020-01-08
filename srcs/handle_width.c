/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_width.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 18:26:00 by jlensing       #+#    #+#                */
/*   Updated: 2020/01/07 18:05:37 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/libft_func.h"

int		handle_width(struct s_info info, char *str, int i)
{
	if (ft_strlen(str) - info.toprint < 0)
	{
		while (i < (info.width - info.toprint))
		{
			ft_putchar_fd(1, ' ');
			i++;
		}
	}
	else
	{
		while (i < ((info.width - ft_strlen(str)) +
								(ft_strlen(str) - info.toprint)))
		{
			ft_putchar_fd(1, ' ');
			i++;
		}
		while (info.width == info.toprint &&
							i < info.width - ft_strlen(str))
		{
			ft_putchar_fd(1, ' ');
			i++;
		}
	}
	return (i);
}
