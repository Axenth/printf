/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_func.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 16:08:10 by jlensing       #+#    #+#                */
/*   Updated: 2020/01/07 17:16:07 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FUNC_H
# define LIBFT_FUNC_H
# include <stddef.h>

void			ft_putstr_fd(int fd, char *str, int n);
void			ft_putchar_fd(int fd, char c);
void			ft_putnbr_unsigned_fd(unsigned int n, int fd);
char			*convert_to_hex(unsigned long value);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strdup(const char *s1);
int				ft_strlen(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
char			*ft_itoa_unsigned(unsigned int n);
int				ft_atoi(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
