/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:28:29 by roruiz-v          #+#    #+#             */
/*   Updated: 2022/10/01 15:32:45 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	else
	{
		while (*str1 - *str2 == 0 && (*str1 != '\0' && *str2 != '\0')
			&& i < n -1)
		{
			str1++;
			str2++;
			i++;
		}
		if (*str1 - *str2 > 0)
			return (1);
		else if (*str1 - *str2 < 0)
			return (-1);
		else
			return (0);
	}
}
