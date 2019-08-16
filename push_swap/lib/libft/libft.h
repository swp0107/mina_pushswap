/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 23:33:30 by minakim           #+#    #+#             */
/*   Updated: 2019/06/25 23:10:20 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <inttypes.h>
# include <fcntl.h>
# define BUFF_SIZE 1024

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
char				*ft_itoa(int n);
char				*ft_itoa_base(uintmax_t nb, uintmax_t base_nb);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				ft_strupper(char *str);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_nbrlen(int nbr);
void				ft_binary(int nbr);
char				*ft_strrev(char *str);
void				ft_swap(int *a, int *b);
size_t				ft_wstrlen(wchar_t *wstr);
char				*ft_strjoin_mod(char *s1, char **s2);
char				*ft_count_letters(char const *str, char c);
int					ft_count_words(char const *str, char c);
typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					get_next_line(const int fd, char **line);
int					find_new_line(int fd, char **data, char **line);


/*
**	ft_printf
*/
typedef struct	s_args
{
	int								space;
	int								zero;
	int								minus;
	int								plus;
	int								hash;
	int								width;
	int								count;
	enum {null, h, hh, l, ll, j, z}	flag;
	int								precis_dot;
	int								precis;
	char							conversion;
}				t_args;

/*
**	initiation.c
*/

t_args			*initialization(void);
intmax_t		get_number(t_args *format, va_list arg);
uintmax_t		get_u_number(t_args *format, va_list arg);

/*
**	trim.c
*/

char			*cut_left(char *str, int n);
char			*cut_right(char *str, int n);
char			*to_left(char *str, int n, char c);
char			*to_right(char *str, int n, char c);

/*
**	check.c
*/

char			**check_flag(char **argstr, t_args *format);
char			**check_precision(char **argstr, t_args *format, va_list arg);
char			**check_width(char **argstr, t_args *format, va_list arg);
char			**check_extra(char **argstr, t_args *format);
char			**check_conversion(char **argstr, t_args *format);

/*
**	specifier1.c
*/

char			*format_big_s(t_args *format, va_list arg);
char			*format_s(t_args *format, va_list arg);
char			*format_d(t_args *format, va_list arg);
char			*format_p(t_args *format, va_list arg);

/*
**	specifier2.c
*/

char			*format_o(t_args *format, va_list arg);
char			*format_u(t_args *format, va_list arg);
char			*u_with_flag(t_args *format, char *ascii);
char			*format_x(t_args *format, va_list arg);

/*
**	specifier3.c
*/

int				format_c_2(t_args *format);
char			*format_c(t_args *format, va_list arg);
char			*format_percent(t_args *format);

/*
**	printf_format.c
*/

int				print_format(t_args *format, va_list arg, int count);

/*
**	ft_printf.c
*/

int				parsing(va_list arg, char **str, int count);
int				ft_printf(char *string, ...);

#endif
