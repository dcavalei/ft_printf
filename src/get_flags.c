/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:31:23 by dcavalei          #+#    #+#             */
/*   Updated: 2021/03/31 15:57:32 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*get_flags(char *str, int i, va_list args)
{
	int		j;
	char	*buff;
	t_list	*flags;

	flags = default_flags();
	j = i;
	while (!is_format(str[j]))
		j++;
	buff = ft_substr(str, i, j - i + 1);
	check_minus(buff, flags);
	check_zero(buff, flags);
	check_length(buff, flags, args);
	check_period(buff, flags);
	check_precision(buff, flags, args);
	check_format(buff, flags);
	set_prio_flags(flags);
	free(buff);
	return (flags);
}

t_list	*default_flags(void)
{
	t_list	*flags;

	flags = malloc(sizeof(t_list));
	if (!flags)
		return (NULL);
	flags->minus = 0;
	flags->zero = 0;
	flags->length = 0;
	flags->period = 0;
	flags->precision = 0;
	flags->format = 0;
	return (flags);
}

int	is_flag(char c)
{
	int	i;

	i = 0;
	while (FLAGS[i])
	{
		if (FLAGS[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	set_prio_flags(t_list *flags)
{
	if ((flags->period && flags->precision > -1) || flags->minus)
		flags->zero = 0;
	if (flags->format == 'c')
	{
		flags->zero = 0;
		flags->period = 0;
		flags->precision = 0;
	}
	if (flags->format == 's')
		flags->zero = 0;
	if (flags->format == 'p')
	{
		flags->zero = 0;
		flags->period = 0;
		flags->precision = 0;
	}
}
