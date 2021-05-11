/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:16:19 by dcavalei          #+#    #+#             */
/*   Updated: 2021/03/31 14:48:16 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_minus(char *buff, t_list *flags)
{
	int	i;

	i = 0;
	while (is_flag(buff[i]))
	{
		if (buff[i] == '-')
			flags->minus = 1;
		i++;
	}
}

void	check_zero(char *buff, t_list *flags)
{
	int	i;

	i = 0;
	while (is_flag(buff[i]))
	{
		if (buff[i] == '0')
			flags->zero = 1;
		i++;
	}
}
