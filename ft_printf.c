/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:35:40 by dcavalei          #+#    #+#             */
/*   Updated: 2021/03/31 13:15:00 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		r;
	va_list	args;
	t_list	*flags;

	if (!str)
		return (-1);
	va_start(args, str);
	i = -1;
	r = 0;
	while (str[++i])
	{
		if (str[i] == '%' && ++i)
		{
			flags = get_flags((char *)str, i, args);
			i = format_id_index((char *)str, i);
			r += print_args(args, flags) - 1;
			free(flags);
		}
		else
			ft_putchar(str[i]);
		r++;
	}
	va_end(args);
	return (r);
}

int	format_id_index(char *str, int i)
{
	while (!is_format(str[i]))
		i++;
	return (i);
}
