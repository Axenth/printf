/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   in_set.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 15:32:14 by jlensing       #+#    #+#                */
/*   Updated: 2019/12/10 15:06:27 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"

t_bool	in_set(char c)
{
	int		i;
	char	*set;

	set = "cspdiuxX%";
	i = 0;
	while (i <= 9)
	{
		if (c == set[i])
			return (true);
		i++;
	}
	return (false);
}
