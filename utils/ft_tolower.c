/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:53:44 by jlensing      #+#    #+#                 */
/*   Updated: 2021/02/24 13:53:38 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower_util(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
