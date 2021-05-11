/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_period.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:09:45 by dcavalei          #+#    #+#             */
/*   Updated: 2021/03/31 13:15:23 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_period(char *buff, t_list *flags)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '.')
			flags->period = 1;
		i++;
	}
}

void	check_length(char *buff, t_list *flags, va_list args)
{
	int	i;

	i = 0;
	while (is_flag(buff[i]))
		i++;
	if (buff[i] == '*')
		flags->length = va_arg(args, int);
	else if (ft_isdigit(buff[i]))
		flags->length = ft_atoi(&buff[i]);
	if (flags->length < 0)
	{
		flags->length *= -1;
		flags->minus = 1;
	}
}

void	check_precision(char *buff, t_list *flags, va_list args)
{
	char	*ptr;

	if (flags->period == 1)
	{
		ptr = ft_strchr(buff, '.');
		ptr++;
		if (*ptr == '*')
			flags->precision = va_arg(args, int);
		else if (ft_isdigit(*ptr))
			flags->precision = ft_atoi(ptr);
	}
}

void	check_format(char *buff, t_list *flags)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (is_format(buff[i]))
			flags->format = buff[i];
		i++;
	}
}

int	is_format(char c)
{
	int	i;

	i = 0;
	while (FORMAT_ID[i])
	{
		if (FORMAT_ID[i] == c)
			return (1);
		i++;
	}
	return (0);
}
