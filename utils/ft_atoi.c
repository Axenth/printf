/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:08:31 by jlensing      #+#    #+#                 */
/*   Updated: 2021/02/24 13:44:00 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	skip(const char *str, int i)
{
	while (str[i] == '\t' || str[i] == '\b' || str[i] == ' ' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		i++;
	return (i);
}

static int	set_sign(char i)
{
	if (i == '-')
		return (-1);
	else
		return (1);
	return (0);
}

static int	check_sign(int sign)
{
	if (sign == -1)
		return (0);
	else
		return (-1);
	return (0);
}

int	ft_atoi_util(const char *str)
{
	int				i;
	int				sign;
	long			res;

	res = 0;
	i = skip(str, 0);
	sign = set_sign(str[i]);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res >= 922337203685477580)
		{
			if ((sign == -1 && str[i] >= '9') || (sign == 1 && str[i] >= '8'))
				return (check_sign(sign));
			res = (res * 10) + (str[i] - '0');
			return ((int)res * sign);
		}
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return ((int)res * sign);
}
