/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_handler.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 16:39:52 by jlensing       #+#    #+#                */
/*   Updated: 2020/01/08 17:57:47 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/libft_func.h"
#include <stdarg.h>
#include <stdlib.h>

t_bool					check_zero_flag(struct s_info info)
{
	if (info.format_type >= 1 || info.format_type <= 3 || info.format_type == 8)
		return (true);
	if ((info.format_type >= 4 && info.format_type <= 7) &&
												info.precision_flag == false)
		return (true);
	return (false);
}

static struct s_info	handle_functions(struct s_info info, char *str,
											void *temp)
{
	info = set_second_info_values(info, str, temp);
	width_true(info, str, 0);
	if (info.negative_flag == true)
	{
		ft_putchar_fd(1, '-');
		info.amount += 1;
	}
	width_zero_true(info, str, 0);
	info = handle_extras(info, temp);
	handle_zeros(info, str);
	print_str(info, str);
	width_dash_true(info, str, 0);
	return (info);
}

struct s_info			flag_handler(struct s_info info, va_list args)
{
	void					*temp;
	char					*str;
	struct s_handler_info	handler_info;

	info = handle_initial_info(info);
	temp = set_temp(info, args);
	str = get_str(info, temp);
	if (info.format_type == 4 && (signed int)temp < 0)
		info.negative_flag = true;
	info = set_info_values(str, temp, info);
	if (temp == NULL && (info.format_type < 4 || info.format_type > 7))
	{
		handler_info = handle_nulls(info, str);
		info = handler_info.info;
		str = handler_info.str;
		if (info.format_type != 3 && info.format_type != 1)
		{
			handler_info = handle_second_nulls(info, str);
			info = handler_info.info;
			str = handler_info.str;
		}
	}
	info = handle_functions(info, str, temp);
	free(str);
	return (info);
}
