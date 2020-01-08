/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_handler_sub_1.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 19:53:53 by nvan-der       #+#    #+#                */
/*   Updated: 2020/01/08 15:21:54 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/libft_func.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void			print_str(struct s_info info, char *str)
{
	if (info.print == true)
		ft_putstr_fd(1, str, info.toprint);
}

struct s_info	set_info_values(char *str, void *temp, struct s_info info)
{
	if (info.precision_flag == false && temp != NULL)
		info.toprint = ft_strlen(str);
	if (info.format_type == 1 && temp == NULL)
		info.amount += 1;
	if (info.format_type == 8 || info.format_type == 3)
	{
		info.precision_flag = false;
		info.print = true;
		info.toprint = ft_strlen(str);
	}
	if (info.format_type >= 4 && info.format_type <= 7 &&
						info.toprint < ft_strlen(str) && temp != NULL)
	{
		info.toprint = ft_strlen(str);
		info.print = true;
	}
	if (info.dash_flag == true)
		info.zero_flag = false;
	if (info.precision_flag == true && info.format_type >= 4 &&
														info.format_type <= 7)
		info.zero_flag = false;
	if (temp == NULL && info.precision_flag == false &&
						(info.format_type >= 4 && info.format_type <= 7))
		info.toprint = 1;
	return (info);
}

struct s_info	set_second_info_values(struct s_info info, char *str,
																void *temp)
{
	if (info.precision_flag == true && info.format_type == 2 &&
										(ft_strlen(str) < info.toprint))
		info.toprint = ft_strlen(str);
	if (info.width_flag == true && info.format_type == 3)
	{
		if (ft_strlen(str) != 1)
			info.width -= 2;
	}
	if (info.width_flag == true && info.format_type == 4)
	{
		if (info.negative_flag == true)
			info.width -= 1;
	}
	if (info.format_type == 4 && info.toprint < ft_strlen(str))
		info.toprint = ft_strlen(str);
	if (info.print == true && info.toprint < ft_strlen(str) &&
		(info.format_type >= 4 && info.format_type <= 7))
		info.toprint = ft_strlen(str);
	if (info.format_type == 4 && temp == NULL && info.precision_flag == true &&
		info.prec == 0)
		info.print = false;
	if (info.format_type == 4 && temp == NULL && info.precision_flag == true &&
																info.prec != 0)
		info.print = true;
	return (info);
}

struct s_info	handle_extras(struct s_info info, void *temp)
{
	if (info.format_type == 4 && temp == NULL && info.print == false &&
													info.width == 0)
		info.amount -= 1;
	if (info.format_type == 1 && temp == NULL && info.print == true)
		ft_putchar_fd(1, '\0');
	if (info.format_type == 3)
	{
		ft_putstr_fd(1, "0x", 3);
		info.amount += 2;
	}
	return (info);
}

void			handle_zeros(struct s_info info, char *str)
{
	int i;

	i = 0;
	if (info.precision_flag == true &&
							(info.format_type >= 4 && info.format_type <= 7))
	{
		while (i < info.toprint - ft_strlen(str))
		{
			ft_putchar_fd(1, '0');
			i++;
		}
		i = 0;
	}
}
