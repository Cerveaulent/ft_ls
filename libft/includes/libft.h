/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/21 17:25:54 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/21 13:02:51 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifdef __LP64__
#  define _ARCH_ __LP64__
# endif

# ifdef _ARCH_
#  define _SHIFT(x1, sh1, x2, sh2) (((x1) << (sh1)) | ((x2) >> (sh2)))
# else
#  define _SHIFT(x1, sh1, x2, sh2) (((x1) >> (sh1)) | ((x2) << (sh2)))
# endif

# define QWORD_LBITS 0x101010101010101L
# define QWORD_HBITS 0x8080808080808080L
# define ABS(x) ((x < 0) ? x * -1 : x)
# include <limits.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include "ft_printf.h"
# include "arraylist.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

# define BUFF_SIZE 1000

typedef struct		s_gnline
{
	int				fd;
	char			*tmp;
	struct s_gnline	*next;
}					t_gnline;

/*
** ctype functions
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isdigit(int c);
int					ft_isgraph(int c);
int					ft_isgreater(float x, float y);
int					ft_isgreaterequal(float x, float y);
int					ft_isinf(double x);
int					ft_isless(float x, float y);
int					ft_islessequal(float x, float y);
int					ft_islower(int c);
int					ft_isnan(double x);
int					ft_isprint(int c);
int					ft_ispunct(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);
int					ft_isxdigit(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
** lst functions
*/
void				ft_lstadd(t_list **alst, t_list *new);
size_t				ft_lstcount(t_list *lst);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				*ft_lstfold(t_list *lst,
								void *(*f)(void *, void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstrev(t_list **alst);

/*
** math functions
*/
int					ft_abs(int i);
int					ft_atoi(const char *str);
char				*ft_lltoa(long long n);
char				*ft_itoa(int n);
char				*ft_itoh(int n);
double				ft_pow(double x, int y);
int					ft_sqrt(int nb);
void				ft_swap(int *a, int *b);

/*
** memory functions
*/
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t s);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memfrob(void *s, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memrcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_realloc(void *ptr, size_t size);
void				ft_printbits(size_t const size, void const *const ptr);

/*
** print functions
*/
int					ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_putstr(char const *s);
void				ft_putstr_bs(char const *s);
void				ft_putstr_bs_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);

/*
** string functions
*/
char				*ft_basename(const char *path);
void				ft_bcopy(const void *src, void *dst, size_t len);
int					ft_endswith(char *end, char *haystack);
int					ft_startswith(char *start, char *haystack);
char				*ft_stpcpy(char *dst, const char *src);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strccat(char *dest, const char *src, int c);
size_t				ft_strccount(const char *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strcjoin(char const *s1, char const *s2, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strcspn(const char *s, const char *charset);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strisalnum(const char *s);
int					ft_strisalpha(const char *s);
int					ft_strisascii(const char *s);
int					ft_strisblank(const char *s);
int					ft_striscntrl(const char *s);
int					ft_strisdigit(const char *s);
int					ft_strisgraph(const char *s);
int					ft_strislower(const char *s);
int					ft_strisprint(const char *s);
int					ft_strispunct(const char *s);
int					ft_strisspace(const char *s);
int					ft_strisupper(const char *s);
int					ft_strisxdigit(const char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(char *s1, char *s2, int a, int b);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strndup(const char *s, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
size_t				ft_strnlen(const char *s, int c);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
char				*ft_strpbrk(const char *s, const char *charset);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *s);
char				*ft_strsep(char **stringp, const char *delim);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strspn(const char *s, const char *charset);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				ft_lstrev(t_list **alst);
int					get_next_line(const int fd, char **line);

int					ft_printf(const char *format, ...);
#endif
