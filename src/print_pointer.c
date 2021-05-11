/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:47:06 by dcavalei          #+#    #+#             */
/*   Updated: 2021/03/31 12:49:36 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(va_list args, t_list *flags)
{
	unsigned long long	num;
	unsigned long long	cp;
	unsigned long long	digits[1];

	num = va_arg(args, unsigned long long);
	cp = num;
	*digits = 1;
	while (cp >= 16)
	{
		cp /= 16;
		(*digits)++;
	}
	if (flags->minus)
		print_left_pointer(digits, num, flags);
	else
		print_right_pointer(digits, num, flags);
	return (*digits + 2);
}

void	print_left_pointer(unsigned long long *digits,
							unsigned long long num, t_list *flags)
{
	ft_putchar('0');
	ft_putchar('x');
	putnbr_base_unsigned(num, "0123456789abcdef");
	while (*digits + 2 < (unsigned long long)flags->length)
	{
		ft_putchar(' ');
		(*digits)++;
	}
}

void	print_right_pointer(unsigned long long *digits,
							unsigned long long num, t_list *flags)
{
	while (*digits + 2 < (unsigned long long)flags->length)
	{
		ft_putchar(' ');
		(*digits)++;
	}
	ft_putchar('0');
	ft_putchar('x');
	putnbr_base_unsigned(num, "0123456789abcdef");
}
