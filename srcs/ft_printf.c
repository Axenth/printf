/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 16:08:18 by jlensing      #+#    #+#                 */
/*   Updated: 2020/10/23 19:31:42 by axenth        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"
#include "../hdrs/utils.h"
#include <stdarg.h>

static struct s_info	ft_printf_loop(const char *format, int i,
										va_list args, struct s_info info)
{
	int	temp;

	info.format_type = 0;
	if (format[i] == '%')
	{
		info = flag_checker(format, i, info, args);
		if (info.format_type && info.skip == e_false)
		{
			temp = info.position;
			info = flag_handler(info, args);
			if (info.error == e_true)
				return (info);
			if (info.width > info.toprint)
				info.amount += info.width;
			else if (info.width <= info.toprint)
				info.amount += info.toprint;
			i = temp;
		}
		info = reset_struct(info);
	}
	return (info);
}

int	ft_printf(const char *format, ...)
{
	int					i;
	va_list				args;
	struct s_info		info;

	info = init_struct(1);
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			info = ft_printf_loop(format, i, args, info);
			i = info.position;
		}
		else if (format[i] != '%')
		{
			info = ft_putchar_fd_util(info.fd, format[i], info);
			info.amount++;
		}
		if (info.error == e_true)
			return (-1);
		i++;
	}
	va_end(args);
	return (info.amount);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	int					i;
	va_list				args;
	struct s_info		info;

	info = init_struct(fd);
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			info = ft_printf_loop(format, i, args, info);
			i = info.position;
		}
		else if (format[i] != '%')
		{
			info = ft_putchar_fd_util(info.fd, format[i], info);
			info.amount++;
		}
		if (info.error == e_true)
			return (-1);
		i++;
	}
	va_end(args);
	return (info.amount);
}

static int	increment(int *i, struct s_info info)
{
	if (info.error == e_true)
		return (-1);
	*i += 1;
	return (0);
}

int	ft_sprintf(char **s, const char *format, ...)
{
	int					i;
	va_list				args;
	struct s_info		info;

	info = init_struct(-1);
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			info = ft_printf_loop(format, i, args, info);
			i = info.position;
		}
		else if (format[i] != '%')
		{
			info = ft_putchar_fd_util(info.fd, format[i], info);
			info.amount++;
		}
		if (increment(&i, info) == -1)
			return (-1);
	}
	va_end(args);
	*s = ft_strdup_util(info.str);
	return (info.amount);
}
