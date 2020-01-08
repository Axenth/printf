/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 16:11:24 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/26 15:07:20 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft_func.h"
#include <stdlib.h>

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1);
	size += ft_strlen(s2);
	size++;
	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, size);
	ft_strlcat(str, s2, size);
	return (str);
}
