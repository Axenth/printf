# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jlensing <jlensing@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/20 16:04:04 by jlensing       #+#    #+#                 #
#    Updated: 2020/01/08 17:35:24 by jlensing      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c flag_checker.c flag_handler.c in_set.c in_flag_set.c \
		handle_precision.c handle_width.c handle_negative.c \
		flag_handler_sub_1.c flag_handler_sub_2.c flag_handler_sub_3.c

SRC_MAP = srcs/

LIB_SRC = ft_putchar_fd.c ft_putstr_fd.c ft_tolower.c \
 		ft_convert_to_hex.c ft_strdup.c ft_strlen.c ft_toupper.c ft_itoa.c \
		 ft_atoi.c ft_substr.c ft_strncmp.c ft_strlcat.c \
		 ft_strlcpy.c ft_itoa_unsigned.c ft_strjoin.c

LIB_MAP = libft/

FLG = flag_c.c flag_p.c flag_s.c flag_di.c flag_u.c flag_x.c flag_procent.c \
		flag_width.c

FLG_MAP = flags/

HDR = ft_printf.h

HDR_MAP = hdrs/

SRCS = $(addprefix $(SRC_MAP), $(SRC))

LIBFT = $(addprefix $(LIB_MAP), $(LIB_SRC))

HDRS = $(addprefix $(HDR_MAP), $(HDR))

FLGS = $(addprefix $(FLG_MAP), $(FLG))

OBJS = $(SRCS:.c=.o) $(FLGS:.c=.o) $(LIBFT:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $^
	$(RM) *.o

%.o: %.c $(HDRS)
	clang -o $@ -c $< $(FLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
