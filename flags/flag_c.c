/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_c.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 19:16:23 by jlensing       #+#    #+#                */
/*   Updated: 2019/12/10 14:47:00 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*flag_c(char c)
{
	char *str;

	str = malloc(sizeof(char) * 1);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
