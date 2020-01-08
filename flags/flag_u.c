/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_u.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:46:15 by jlensing       #+#    #+#                */
/*   Updated: 2019/12/10 15:41:39 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft_func.h"

char	*flag_u(unsigned int value)
{
	char *str;

	str = ft_itoa_unsigned(value);
	return (str);
}
