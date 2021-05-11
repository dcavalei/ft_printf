/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:51:14 by dcavalei          #+#    #+#             */
/*   Updated: 2021/03/31 12:55:57 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_signed_int(va_list args, t_list *flags)
{
	long		num;
	int			digits;
	int			neg;

	num = (long)va_arg(args, int);
	neg = 0;
	negative_handle(&num, &neg);
	digits = count_digits(num);
	if (flags->period && flags->precision == 0 && num == 0)
		print_spaces_or_zeros(0, flags);
	else if (flags->minus)
		print_left_int(neg, digits, num, flags);
	else
		print_right_int(neg, digits, num, flags);
	return (ret_int(neg, digits, num, flags));
}

void	print_left_int(int neg, int digits, long num, t_list *flags)
{
	if (neg)
		ft_putchar('-');
	print_zeros_precision(digits, flags);
	ft_putnbr(num);
	if (digits < flags->precision)
		print_spaces_or_zeros(flags->precision + neg, flags);
	else
		print_spaces_or_zeros(digits + neg, flags);
}

void	print_right_int(int neg, int digits, long num, t_list *flags)
{
	if (neg && flags->zero)
		ft_putchar('-');
	if (digits < flags->precision)
		print_spaces_or_zeros(flags->precision + neg, flags);
	else
		print_spaces_or_zeros(digits + neg, flags);
	if (neg && !flags->zero)
		ft_putchar('-');
	print_zeros_precision(digits, flags);
	ft_putnbr(num);
}

int	print_unsigned_int(va_list args, t_list *flags)
{
	long	num;
	int		digits;
	int		neg;

	num = (long)va_arg(args, unsigned int);
	neg = 0;
	digits = count_digits(num);
	if (flags->period && flags->precision == 0 && num == 0)
		print_spaces_or_zeros(0, flags);
	else if (flags->minus)
		print_left_int(neg, digits, num, flags);
	else
		print_right_int(neg, digits, num, flags);
	return (ret_int(neg, digits, num, flags));
}

int	ret_int(int neg, int digits, long num, t_list *flags)
{
	if (flags->period)
		if (flags->precision == 0 && num == 0)
			return (flags->length);
	if (digits < flags->precision)
		digits = flags->precision;
	if (digits + neg < flags->length)
		return (flags->length);
	return (digits + neg);
}
