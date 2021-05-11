/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:29:48 by dcavalei          #+#    #+#             */
/*   Updated: 2021/03/31 14:25:16 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

static int	check_base(char *base)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = get_size(base);
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (i < size)
	{
		while (j < size)
		{
			if (i != j)
			{
				if (base[i] == base[j] || base[i] == '+' || base[i] == '-')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long nb)
{
	char	c;

	c = '8';
	if (nb == -(2147483648))
	{
		ft_putnbr(nb / 10);
		write(1, &c, 1);
	}
	else if (nb <= (-1))
	{
		c = '-';
		write(1, &c, 1);
		nb = -nb;
		ft_putnbr(nb);
	}
	else
	{
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
		}
		c = 48 + nb % 10;
		write(1, &c, 1);
	}
}

void	putnbr_base_unsigned(unsigned long long nbr, char *base)
{
	unsigned long long	size;

	if (!check_base(base))
		return ;
	size = (unsigned long long)get_size(base);
	if (nbr >= size)
	{
		putnbr_base_unsigned(nbr / size, base);
		ft_putchar(base[nbr % size]);
	}
	else
		ft_putchar(base[nbr % size]);
}
