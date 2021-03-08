/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:31:29 by anclarma          #+#    #+#             */
/*   Updated: 2021/03/08 13:00:11 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define PRINTF_BUFFER	1024
# define GNL_BUFFER		1024
# define LONGFLAG		0x00000001
# define LONGLONGFLAG	0x00000002
# define HALFFLAG		0x00000004
# define HALFHALFFLAG	0x00000008
# define SIZETFLAG		0x00000010
# define ALTFLAG		0x00000020
# define CAPSFLAG		0x00000040
# define SHOWSIGNFLAG	0x00000080
# define SIGNEDFLAG		0x00000100
# define LEFTFORMATFLAG	0x00000200
# define LEADZEROFLAG	0x00000400
# define POINTFLAG		0x00000800
# define BLANKFLAG		0x00001000
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_out
{
	char			str[PRINTF_BUFFER];
	int				current_size;
	int				final_size;
}					t_out;

typedef struct		s_flag
{
	int				flag;
	int				width;
	int				precision;
}					t_flag;

typedef struct		s_all
{
	t_out			*out;
	t_flag			*flag;
	char			*cpy_format;
	char			*cpy_format_init;
}					t_all;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strnlen(const char *s, size_t maxlen);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_atoi(const char *str);
double				ft_atof(const char *str);
void				*ft_calloc(size_t count, size_t size);
void				ft_free(void *ptr);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(long long int n);
char				*ft_itoa_base(long long int nb, char *base);
char				*ft_utoa(unsigned long long int n);
char				*ft_utoa_base(unsigned long long int nb, char *base);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new_lst);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new_lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_printf(const char *format, ...);
void				ft_ifforest(t_all *all, va_list ap);
void				ft_outputchar(t_all *all, int c);
void				ft_outputstring(t_all *all, const char *str);
void				ft_outputinteger(t_all *all, va_list ap);
void				ft_outputunsigned(t_all *all, va_list ap);
void				ft_outputhex(t_all *all, va_list ap);
void				ft_outputwritten(t_all *all, int *ptr);
void				ft_outputnumber(t_all *all, char *nbr);
int					ft_checkbufferprintf(t_out *out);
int					ft_cleanbufferprintf(t_out *out);
void				ft_padding(t_all *all, int size, char c);
char				*ft_printf_itoa(t_all *all, va_list ap);
char				*ft_printf_utoa(t_all *all, va_list ap);
char				*ft_printf_utoa_base(t_all *all, va_list ap,
						char *base);
void				ft_calculation_size_nbr(int *size_nbr, char *nbr,
						t_all *all);
void				ft_calculation_nb_space1(int *size_nbr, int *nb_space1,
						t_all *all);
void				ft_calculation_nb_space2(int *nb_space1, int *nb_space2,
						t_all *all);
int					get_next_line(int fd, char **line);
#endif
