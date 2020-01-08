/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 18:29:28 by jlensing       #+#    #+#                */
/*   Updated: 2019/11/26 15:08:52 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dstl;
	size_t srcl;

	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	if (!dstsize || dstsize < dstl)
		return (dstl + srcl - (dstl - dstsize));
	dstsize -= dstl;
	ft_strlcpy(dst + dstl, src, dstsize);
	return (dstl + srcl);
}
