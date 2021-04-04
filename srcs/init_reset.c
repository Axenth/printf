#include "../hdrs/ft_printf.h"
#include <stdlib.h>

struct s_info	reset_struct(struct s_info info)
{
	info.width = 0;
	info.width_flag = e_false;
	info.dash_flag = e_false;
	info.zero_flag = e_false;
	info.precision_flag = e_false;
	info.toprint = 0;
	info.prec = 0;
	info.print = e_true;
	info.negative_flag = e_false;
	info.skip = e_false;
	info.error = e_false;
	return (info);
}

struct s_info	init_struct(int fd)
{
	struct s_info	info;

	info.format_type = 0;
	info.position = 0;
	info.width = 0;
	info.toprint = 0;
	info.amount = 0;
	info.prec = 0;
	info.fd = fd;
	info.width_flag = e_false;
	info.dash_flag = e_false;
	info.zero_flag = e_false;
	info.precision_flag = e_false;
	info.print = e_true;
	info.negative_flag = e_false;
	info.skip = e_false;
	info.error = e_false;
	info.sprintf = e_false;
	if (fd == -1)
	{
		info.sprintf = e_true;
		info.str = malloc(sizeof(char) * 1);
		info.str[0] = '\0';
	}
	return (info);
}
