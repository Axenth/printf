/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   in_flag_set.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 15:36:17 by jlensing       #+#    #+#                */
/*   Updated: 2019/12/20 18:15:36 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"

t_bool	in_flag_set(char c)
{
	int		i;
	char	*set;

	set = "-0.*";
	i = 0;
	while (i <= 4)
	{
		if (c == set[i])
			return (true);
		i++;
	}
	return (false);
}
