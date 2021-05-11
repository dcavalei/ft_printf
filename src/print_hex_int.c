/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:56:46 by dcavalei          #+#    #+#             */
/*   Updated: 2021/03/31 15:22:44 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_int(va_list args, t_list *flags)
{
	unsigned long long	num;
	int					digits;
	int					neg;
	int					i;

	num = (unsigned int)va_arg(args, int);
	neg = 0;
	i = 0;
	digits = count_digits_hex(num);
	if (flags->period && flags->precision == 0 && num == 0)
		print_spaces_or_zeros(0, flags);
	else if (flags->minus)
		print_left_hex(digits, num, flags);
	else
		print_right_hex(digits, num, flags);
	return (ret_int(neg, digits, num, flags));
}

void	print_left_hex(unsigned long long digits,
							unsigned long long num, t_list *flags)
{
	print_zeros_precision(digits, flags);
	if (flags->format == 'x')
		putnbr_base_unsigned(num, "0123456789abcdef");
	else if (flags->format == 'X')
		putnbr_base_unsigned(num, "0123456789ABCDEF");
	if (flags->precision > -1 && digits < (unsigned long long)flags->precision)
		print_spaces_or_zeros(flags->precision, flags);
	else
		print_spaces_or_zeros(digits, flags);
}

void	print_right_hex(unsigned long long digits,
							unsigned long long num, t_list *flags)
{
	if (flags->precision > -1 && digits < (unsigned long long)flags->precision)
		print_spaces_or_zeros(flags->precision, flags);
	else
		print_spaces_or_zeros(digits, flags);
	print_zeros_precision(digits, flags);
	if (flags->format == 'x')
		putnbr_base_unsigned(num, "0123456789abcdef");
	else if (flags->format == 'X')
		putnbr_base_unsigned(num, "0123456789ABCDEF");
}

void	print_zeros_precision(int digits, t_list *flags)
{
	while (digits < flags->precision)
	{
		ft_putchar('0');
		digits++;
	}
}

void	print_spaces_or_zeros(int used_space, t_list *flags)
{
	while (used_space < flags->length)
	{
		if (flags->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		used_space++;
	}
}
