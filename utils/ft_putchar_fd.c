/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 19:17:00 by jlensing      #+#    #+#                 */
/*   Updated: 2020/01/10 16:58:34 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/utils.h"
#include <unistd.h>
#include <stdlib.h>

static char	*return_char_as_string(char c)
{
	char	*temp;

	temp = malloc(sizeof(char) * 2);
	temp[0] = c;
	temp[1] = '\0';
	return (temp);
}

struct s_info	ft_putchar_fd_util(int fd, char c, struct s_info info)
{
	ssize_t	i;
	char	*temp;
	char	*temp2;

	if (info.sprintf == e_false)
	{
		i = write(fd, &c, sizeof(char));
		if (i < 0)
			info.error = e_true;
	}
	else
	{
		temp = ft_strdup_util(info.str);
		temp2 = return_char_as_string(c);
		free(info.str);
		info.str = ft_strjoin_util(temp, temp2);
		free(temp);
		free(temp2);
	}
	return (info);
}
