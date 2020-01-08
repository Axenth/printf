/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_negative.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 17:27:48 by jlensing       #+#    #+#                */
/*   Updated: 2020/01/07 18:05:39 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/libft_func.h"

struct s_info	handle_negative(struct s_info info)
{
	if (info.negative_flag == true)
	{
		ft_putchar_fd(1, '-');
		info.amount += 1;
	}
	return (info);
}
