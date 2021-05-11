/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:14:40 by dcavalei          #+#    #+#             */
/*   Updated: 2021/03/31 13:02:41 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_args(va_list args, t_list *flags)
{
	if (flags->format == 'c')
		return (print_char(args, flags));
	else if (flags->format == 's')
		return (print_string(args, flags));
	else if (flags->format == 'p')
		return (print_pointer(args, flags));
	else if (flags->format == 'd' || flags->format == 'i')
		return (print_signed_int(args, flags));
	else if (flags->format == 'u')
		return (print_unsigned_int(args, flags));
	else if (flags->format == 'x' || flags->format == 'X')
		return (print_hex_int(args, flags));
	else if (flags->format == '%')
		return (print_percentual(flags));
	return (-1);
}

int	count_digits(long num)
{
	int	digits;

	digits = 1;
	while (num >= 10 || num <= -10)
	{
		digits++;
		num /= 10;
	}
	return (digits);
}

int	count_digits_hex(unsigned long long num)
{
	int	digits;

	digits = 1;
	while (num >= 16)
	{
		digits++;
		num /= 16;
	}
	return (digits);
}

void	negative_handle(long *num, int *neg)
{
	if (*num < 0)
	{
		*num = -(*num);
		*neg = 1;
	}
}
