/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:20:42 by dcavalei          #+#    #+#             */
/*   Updated: 2021/03/31 13:05:38 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	current;
	size_t	real_size;

	real_size = ft_strlen(src);
	if (real_size < len)
		len = real_size;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr || !src)
		return (NULL);
	current = 0;
	if (start < ft_strlen(src))
	{
		while (src[start + current] && current < len)
		{
			ptr[current] = src[start + current];
			current++;
		}
	}
	ptr[current] = '\0';
	return (ptr);
}
