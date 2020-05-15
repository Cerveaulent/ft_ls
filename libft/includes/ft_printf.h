/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/21 04:00:42 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/30 01:12:35 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct			s_printf
{
	char				conv;
	char				*global_ans;
	int					fatal_error;
	int					error;
	char				bad_conv;
	int					size_ans;
	int					ret;
	int					nb_zero;
	int					isneg;
	int					h;
	int					hh;
	int					l;
	int					ll;
	int					lf;
	int					hash;
	int					zero;
	int					minus;
	int					plus;
	int					space;
	int					point;
	int					size;
	int					accu;
}						t_printf;

typedef struct			s_int
{
	long long			nb_long_long;
	long				nb_long;
	int					nb_int;
	short				nb_short;
	char				*ans;
}						t_int;

typedef struct			s_uint
{
	unsigned long long	nb_long_long;
	unsigned long		nb_long;
	unsigned int		nb_int;
	unsigned short		nb_short;
	char				*ans;
}						t_uint;

/*
** TOOLS
*/
char					*add_first_char(char *str, char c, t_printf *d);
char					*ft_strcapitalize(char *str);

/*
** TOOLS 2
*/
int						is_lenght(const char *str, int i);
int						is_flag(const char *str, int i);
int						is_conv(const char *str, int i);
size_t					ft_countdigits(long digit);
int						count_digit(int digit);

/*
** ITOA BASE
*/
char					*ft_itoa_printf_2(long long num, int base, char *str);
char					*ft_itoa_printf(long long value, int base, t_printf *d);
char					*ft_itoa_printf_u_2(
						unsigned long long num, int base, char *str);
char					*ft_itoa_printf_u(
						unsigned long long value, int base, t_printf *d);

/*
** CONV_CSP_PERCENT
*/
char					*op_char(va_list ap, t_printf *d);
char					*op_string(va_list ap, t_printf *d);
char					*op_pointer(va_list ap, t_printf *d);
char					*op_percent(t_printf *d);

/*
** CONV_DIOUXX
*/
char					*op_int(va_list ap, t_printf *d);
char					*op_octal(va_list ap, t_printf *d);
char					*op_u_int(va_list ap, t_printf *d);
char					*op_hexa(va_list ap, t_printf *d);

/*
** FLOAT / DOUBLE
*/
char					*ft_putfloat(long double n, int prec);
char					*op_float(va_list ap, t_printf *d);
void					put_ret(char *ret, int g_ret);
char					*init_ret(char *ret, int g_nblen);

/*
** CONV_B_TAB
*/
char					*op_bin(va_list ap, t_printf *d);
char					*op_tab(va_list ap, t_printf *d);

/*
** ACCURACY AND SIZE
*/
char					*accuracy(char *ans, t_printf *d);
char					*size(char *ans, t_printf *d);
char					*accuracy_and_size(char *str, t_printf *d);

/*
** PLUS SPACE
*/
char					*flag_plus_space2(char *str, t_printf *d, int i);
char					*flag_plus_space1(char *str, t_printf *d, int i);
char					*flag_plus_space(char *str, t_printf *d, int i);

/*
** ZERO MINUS
*/
int						go_to_ans(char *str, int i, t_printf *d);
char					*flag_zero(char *str, int i);
char					*flag_minus(char *str, t_printf *d, int i, int j);
char					*last_flags(char *str, t_printf *d);

/*
** HASH
*/
char					*flag_hash_octale(char *str, t_printf *d, int i);
char					*flag_hash_hexa_2(char *str, int j,
						char *ans, t_printf *d);
char					*flag_hash_hexa(char *str, t_printf *d, int i, int j);

/*
** DATA INITIALISATION
*/
void					init_t_printf_2(t_printf *d);
void					init_t_printf(t_printf *d);
void					init_op_int(t_int *i);
void					init_op_uint(t_uint *i);

/*
** CHECK ERRORS
*/
void					check_flags_error(t_printf *d);
char					*error(char *str, t_printf *d);

/*
** PUSH PARAMS
*/
int						get_params(const char *str, int i, t_printf *d);
int						get_lenght(const char *str, int i, t_printf *d);
size_t					get_size_or_accu(const char *str, int i, t_printf *d,
						int mode);
int						get_flags(const char *str, int i, t_printf *d);

/*
** PARSING
*/
char					*op_dispatch(va_list ap, t_printf *d);
char					*build_ans(t_printf *d, int k, va_list ap);
int						parsing(const char *str, va_list ap,
								int i, t_printf *d);
int						ft_printf(const char *format, ...);

#endif
