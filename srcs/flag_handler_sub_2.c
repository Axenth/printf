/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_handler_sub_2.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 20:33:19 by nvan-der       #+#    #+#                */
/*   Updated: 2020/01/08 16:31:46 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/libft_func.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

static void	print_width(struct s_info info, char *str, int type, int i)
{
	while (i < ((info.width - ft_strlen(str)) +
				(ft_strlen(str) - info.toprint)) && type == 0)
	{
		ft_putchar_fd(1, ' ');
		i++;
	}
	while (i < ((info.width - ft_strlen(str)) +
				(ft_strlen(str) - info.toprint)) && type == 1)
	{
		ft_putchar_fd(1, '0');
		i++;
	}
	while (i < (info.width - info.toprint) && type == 2)
	{
		ft_putchar_fd(1, ' ');
		i++;
	}
	while (info.width == info.toprint &&
				i < info.width - ft_strlen(str) && type == 3)
	{
		ft_putchar_fd(1, ' ');
		i++;
	}
}

void		width_true(struct s_info info, char *str, int i)
{
	if (info.width_flag == true)
	{
		if (info.dash_flag == false && info.zero_flag == false)
		{
			if (info.print == true)
			{
				if (ft_strlen(str) - info.toprint < 0)
					print_width(info, str, 2, i);
				else
				{
					print_width(info, str, 0, i);
					print_width(info, str, 3, i);
				}
			}
			else
			{
				while (i < info.width)
				{
					ft_putchar_fd(1, ' ');
					i++;
				}
			}
		}
	}
}

void		width_zero_true(struct s_info info, char *str, int i)
{
	if (info.width_flag == true && info.dash_flag == false
								&& info.zero_flag == true)
	{
		if (check_zero_flag(info) == true)
		{
			if (info.print == true)
			{
				print_width(info, str, 1, i);
			}
			else
			{
				while (i < info.width)
				{
					ft_putchar_fd(1, '0');
					i++;
				}
			}
		}
	}
}

void		width_dash_true(struct s_info info, char *str, int i)
{
	if (info.width_flag == true && info.dash_flag == true)
	{
		if (info.print == true)
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
				print_width(info, str, 0, i);
		}
		else
		{
			while (i < info.width)
			{
				ft_putchar_fd(1, ' ');
				i++;
			}
		}
	}
}