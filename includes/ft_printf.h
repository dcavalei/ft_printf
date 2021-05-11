/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:43:18 by dcavalei          #+#    #+#             */
/*   Updated: 2021/03/31 14:33:25 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define FORMAT_ID "cspdiuxX%"
# define FLAGS "-+0 #"
# define NULL_STRING_TEXT "(null)"

typedef struct s_list
{
	int		minus;
	int		zero;
	int		length;
	int		period;
	int		precision;
	char	format;
}				t_list;

int				ft_printf(const char *str, ...);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
void			ft_putchar(char c);
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *str, int c);
char			*ft_substr(char const *src, unsigned int start, size_t len);
void			ft_putnbr(long nb);
void			putnbr_base_unsigned(unsigned long long nbr, char *base);
t_list			*get_flags(char *str, int i, va_list args);
t_list			*default_flags(void);
int				format_id_index(char *str, int i);
int				is_format(char c);
int				is_flag(char c);
void			check_minus(char *buf, t_list *flags);
void			check_zero(char *buf, t_list *flags);
void			check_length(char *buf, t_list *flags, va_list args);
void			check_period(char *buf, t_list *flags);
void			check_precision(char *buf, t_list *flags, va_list args);
void			check_format(char *buf, t_list *flags);
void			set_prio_flags(t_list *flags);
void			print_spaces_or_zeros(int used_space, t_list *flags);
void			print_zeros_precision(int digits, t_list *flags);
int				ret_int(int neg, int digits, long num, t_list *flags);
int				count_digits(long num);
int				count_digits_hex(unsigned long long num);
void			negative_handle(long *num, int *neg);
void			print_left_string(int *i, char *str, t_list *flags);
void			print_right_string(int *i, char *str, t_list *flags);
void			print_left_pointer(unsigned long long *digits,
					unsigned long long num, t_list *flags);
void			print_right_pointer(unsigned long long *digits,
					unsigned long long num, t_list *flags);
void			print_left_int(int neg, int digits, long num, t_list *flags);
void			print_right_int(int neg, int digits, long num, t_list *flags);
void			print_left_hex(unsigned long long digits,
					unsigned long long num, t_list *flags);
void			print_right_hex(unsigned long long digits,
					unsigned long long num, t_list *flags);
int				print_args(va_list args, t_list *flags);
int				print_char(va_list args, t_list *flags);
int				print_string(va_list args, t_list *flags);
int				print_pointer(va_list args, t_list *flags);
int				print_signed_int(va_list args, t_list *flags);
int				print_unsigned_int(va_list args, t_list *flags);
int				print_hex_int(va_list args, t_list *flags);
int				print_percentual(t_list *flags);

#endif
