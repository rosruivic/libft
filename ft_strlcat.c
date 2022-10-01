/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:12:10 by roruiz-v          #+#    #+#             */
/*   Updated: 2022/09/30 23:43:54 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	size_t	i;
	size_t	j;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = 0;
	j = d;
	if (dstsize == 0)
		return (s);
	if (dstsize > d)
	{
		while (j < dstsize -1 && src[i] != '\0')
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = '\0';
		return (d + s);
	}
	else
		return (s + dstsize);
}
