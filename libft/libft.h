/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:24:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/26 10:42:50 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
int					ft_toupper(int ch);
int					ft_tolower(int ch);
char				*ft_strchr(const char *str, int c);
void				ft_bzero(void *str, size_t n);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
int					ft_atoi(const char *str);
char				*ft_strnstr(const char *s, const char *ne, size_t len);
void				*ft_calloc(size_t num, size_t size);
void				*ft_memcpy(void	*dest, void const *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const*s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

int					ft_strlen_gnl(char *s);
char				*ft_strjoin_gnl(char *s, char c);
char				*ft_read_line_gnl(int fd, char *dst);
char				*ft_get_next_line_gnl(int fd);

int					ft_printf(const char *format, ...);
int					ft_print_hex_mayus(unsigned int n);
int					ft_putchar(char c);
int					ft_print_str(char *str);
int					ft_print_unsigned_int(unsigned int n);
int					ft_print_ptr(unsigned long long ptr);
int					ft_print_int(int n);
int					ft_print_hex(unsigned int n);

char				*ft_strtok(char *str, const char *delim);
void				*ft_realloc(void *ptr, size_t size);
int					ft_isspace(int c);
#endif