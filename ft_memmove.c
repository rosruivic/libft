/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:57:18 by roruiz-v          #+#    #+#             */
/*   Updated: 2022/09/30 22:24:34 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	counter;

	d = (char *) dst;
	s = (char *) src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
	{
		counter = 0;
		while (counter < len)
		{
			d[counter] = s[counter];
			counter++;
		}
	}
	else
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	return (dst);
}
