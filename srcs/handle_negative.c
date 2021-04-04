/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_negative.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 17:27:48 by jlensing      #+#    #+#                 */
/*   Updated: 2020/10/24 01:24:55 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/utils.h"

struct s_info	handle_negative(struct s_info info)
{
	if (info.negative_flag == e_true)
	{
		info = ft_putchar_fd_util(info.fd, '-', info);
		info.amount += 1;
	}
	return (info);
}
