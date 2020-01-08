/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_di.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 21:18:57 by jlensing       #+#    #+#                */
/*   Updated: 2019/12/10 15:08:25 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft_func.h"

char	*flag_di(signed int value)
{
	char *str;

	if (value < 0)
		value *= -1;
	str = ft_itoa(value);
	return (str);
}
