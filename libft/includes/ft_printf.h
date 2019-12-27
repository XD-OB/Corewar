/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 03:31:40 by ishaimou          #+#    #+#             */
/*   Updated: 2019/07/24 05:32:44 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <inttypes.h>
# include "libft.h"
# include "structs.h"

# define ABS(x) (x < 0) ? -x : x

# define D_BIAS 1023
# define LD_BIAS 16383
# define MAX_D 	2047
# define MAX_LD 32767

# define GREEN  "\x1b[0;32m"
# define RED    "\x1b[0;31m"
# define YELLOW "\x1b[0;33m"
# define BLUE   "\x1b[0;34m"
# define PURPLE "\x1b[0;35m"
# define CYAN   "\x1b[0;36m"
# define B_GREEN  "\x1b[1;32m"
# define B_RED    "\x1b[1;31m"
# define B_YELLOW "\x1b[1;33m"
# define B_BLUE   "\x1b[1;34m"
# define B_PURPLE "\x1b[1;35m"
# define B_CYAN   "\x1b[1;36m"
# define EOC    "\x1b[0m"

typedef struct		s_64
{
	size_t			mantissa:52;
	long			exponent:11;
	long			sign:1;
}					t_64;

typedef struct		s_80
{
	size_t			mantissa:63;
	long			int_b:1;
	long			exponent:15;
	long			sign:1;
}					t_80;

typedef union		u_double
{
	t_64			zone;
	double			d;
}					t_double;

typedef union		u_ldouble
{
	t_80			zone;
	long double		ld;
}					t_ldouble;

typedef struct		s_format
{
	char			convers;
	char			*flag;
	long			precis;
	long			width;
	int				pos;
	int				argn;
}					t_format;

typedef struct		s_lst
{
	t_format		*format;
	va_list			*arglist;
	struct s_lst	*next;
}					t_lst;

int					is_format(char c);
int					is_postflag(char c);
int					is_preflag(char c);
int					is_valid(char *str);
int					lstlen(t_lst *lst);
void				sumstr(char **s1, char *s2, int base);
void				multstr(char **s1, char *s2, int base);
void				foisdix(char **str, int *len);
int					check_fill(va_list tmp, char *str, int pos, t_lst *curr);
int					put_spstr(char *str);
int					put_spstrn(char *str, size_t n);
void				print_lst(t_lst *lst);
void				free_lst(t_lst **lst);
t_lst				*parse_format(va_list ap, char *str, int *pflag);
t_lst				*add_node(t_lst *head, t_lst *node);
unsigned long long	cast_xxoub(va_list ap, t_format *format);
long long int		cast_di(va_list ap, char *flag);
char				*add_sign(char *str, int sign);
void				conv_k(t_chr **mychr, va_list ap);
void				conv_color(t_lst *lst, t_chr **mychr);
void				conv_c(t_lst *lst, t_chr **mychr, va_list ap);
void				conv_s(t_lst *lst, t_chr **mychr, va_list ap);
void				conv_p(t_lst *lst, t_chr **mychr, va_list ap);
void				conv_o(t_lst *lst, t_chr **mychr, va_list ap);
void				conv_b(t_lst *lst, t_chr **mychr, va_list ap);
void				conv_di(t_lst *lst, t_chr **mychr, va_list ap);
void				conv_xx(t_lst *lst, t_chr **mychr, va_list ap);
void				conv_lfh(t_lst *lst, t_chr **mychr, t_double db, int is_g);
void				conv_ee(t_lst *lst, t_chr **mychr, t_double db, int is_g);
void				conv_d_efgh(t_lst *lst, t_chr **mychr, va_list ap);
void				conv_llf(t_lst *lst, t_chr **mychr, va_list ap, int is_g);
void				conv_lee(t_lst *lst, t_chr **mychr, va_list ap, int is_g);
void				conv_percent(t_chr **mychr, t_lst *lst, va_list ap);
void				conv_di(t_lst *lst, t_chr **mychr, va_list ap);
void				conv_u(t_lst *lst, t_chr **mychr, va_list ap);
char				*xx_zero(t_format *fmt);
void				eprecis(char **str, long precis, long *carry, long *len_s);
void				precis_u(char **str, t_format *fmt, int nbr_len);
char				*all_zero_u(char *nbr, int precis);
void				conv_invalid(t_chr **mychr, t_format *format, va_list ap);
char				*ejoin(t_format *fmt, char *entier, char *fract, long *len);
char				*eprefix(t_format *fmt, long *len);
char				*o_n(t_format *fmt, char *num, int len_num);
char				*flag_r(char c);
void				flag_star(t_format *format, va_list ap);
void				flag_dash(char **nbr, int base);
void				flag_apostrophe(char **str, t_format *fmt);
int					flag_dollar(t_lst *lst);
char				*ft_dollar_cs(t_format *fmt);
int					ft_countnp(char *s);
char				*cut_str(char *str, int p1, int p2);
void				init_chr(t_chr **chr);
void				free_chr(t_chr **chr);
t_chr				*load_chr(char *format, t_lst *lst);
void				fill_chr(t_lst *lst, t_chr *chr, va_list ap);
int					put_chr(t_lst *lst, t_chr *chr);
int					put_chr_fd(int fd, t_lst *lst, t_chr *chr);
int					put_chr_nfd(int fd, size_t n, t_chr *chr);
char				*ft_strcolor(char *str);
int					adv_freeflag(char **str);
int					pre_d_calc(t_double db, t_chr **mychr, t_lst *lst, int g);
int					pre_ld_calc(t_ldouble db, t_chr **mychr, t_lst *lst, int g);
long				int_exp(long bin_exp, int bias);
long long			int_mants(long bin_mants, int bias);
char				*get_entierld(long exp, t_ldouble db, t_format *format);
char				*get_entier(long exp, long bin_mantis,
		int bias, t_format *format);
char				*get_fractld(long exp, t_ldouble db, t_format *format);
char				*get_fract(long exp, long bin_mantis,
		int bias, t_format *format);
void				int_add(char **tab, unsigned int *oldsize, int data);
char				*ft_pointjoin(t_format *fmt, char *s1, char *s2, long *len);
void				customize_f(t_format *fmt, char **str, long *len, int sign);
void				add_sign_f(t_format *fmt, char **str, long *len, int sign);
void				fprecis(char **str, long precis, long *carry, long base);
char				*width_di(t_format *fmt, char *nbr, int len_nbr, int sign);
char				*calcul_entier(char *tab, int size, t_format *format);
char				*calcul_fract(char *bat, int size, t_format *format);
void				custom_nanf(t_format *fmt, char **str, long *len);
void				custom_inff(t_format *fmt, char **str, long *len, int sign);
int					ft_printf(const char *format, ...);
int					ft_sprintf(char **str, const char *format, ...);
int					ft_vprintf(const char *format, va_list ap);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_dnprintf(int fd, size_t n, const char *format, ...);
int					ft_snprintf(char **str, size_t n, const char *format, ...);

#endif
