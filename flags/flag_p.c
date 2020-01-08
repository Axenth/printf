/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 20:37:16 by jlensing       #+#    #+#                */
/*   Updated: 2020/01/07 19:46:56 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/libft_func.h"
#include <stdlib.h>

static char	*fill_zero(int n)
{
	int		i;
	char	*hex;

	i = 0;
	hex = malloc(sizeof(char) * n + 1);
	while (i < n)
	{
		hex[i] = '0';
		i++;
	}
	hex[i] = '\0';
	return (hex);
}

char		*flag_p(unsigned long ptr, struct s_info info)
{
	char	*hex;
	int		i;

	i = 15;
	hex = convert_to_hex(ptr);
	if ((ptr == 0) && info.precision_flag == true)
	{
		free(hex);
		hex = fill_zero(info.toprint);
	}
	else if (ptr == 0)
	{
		free(hex);
		hex = malloc(sizeof(char) * 2);
		hex[0] = '0';
		hex[1] = '\0';
	}
	while (i >= 0)
	{
		hex[i] = ft_tolower(hex[i]);
		i--;
	}
	return (hex);
}
