/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:37:24 by dcavalei          #+#    #+#             */
/*   Updated: 2021/03/31 12:46:39 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list args, t_list *flags)
{
	char	c;

	c = va_arg(args, int);
	if (flags->minus)
	{
		ft_putchar(c);
		print_spaces_or_zeros(1, flags);
	}
	else
	{
		print_spaces_or_zeros(1, flags);
		ft_putchar(c);
	}
	if (!(flags->length))
		return (1);
	return (flags->length);
}

int	print_string(va_list args, t_list *flags)
{
	char	*str;
	int		i[1];

	str = va_arg(args, char *);
	if (!str)
		str = NULL_STRING_TEXT;
	*i = 0;
	if (flags->minus)
		print_left_string(i, str, flags);
	else
		print_right_string(i, str, flags);
	if (*i < flags->length)
		return (flags->length);
	return (*i);
}

void	print_left_string(int *i, char *str, t_list *flags)
{
	while (str[*i])
	{
		if (flags->period)
			if (*i == flags->precision)
				break ;
		ft_putchar(str[*i]);
		(*i)++;
	}
	print_spaces_or_zeros(*i, flags);
}

void	print_right_string(int *i, char *str, t_list *flags)
{
	*i = ft_strlen(str);
	if (flags->period)
		if (*i > flags->precision && flags->precision > -1)
			*i = flags->precision;
	print_spaces_or_zeros(*i, flags);
	*i = 0;
	while (str[*i])
	{
		if (flags->period)
			if (*i == flags->precision)
				break ;
		ft_putchar(str[*i]);
		(*i)++;
	}	
}

int	print_percentual(t_list *flags)
{
	if (flags->minus)
	{
		ft_putchar('%');
		print_spaces_or_zeros(1, flags);
	}
	else
	{
		print_spaces_or_zeros(1, flags);
		ft_putchar('%');
	}
	if (!(flags->length))
		return (1);
	return (flags->length);
}
