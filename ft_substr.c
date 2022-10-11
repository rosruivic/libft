/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:40:24 by roruiz-v          #+#    #+#             */
/*   Updated: 2022/10/11 19:06:24 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	j;
	size_t			sub_len;

	i = 0;
	j = start;
	if (len > ft_strlen(s + start))
		sub_len = len - ft_strlen(s + start);
	else
		sub_len = len;
	sub = (char *)malloc((sub_len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	if (start >= sub_len || len == 0 || s[start] == '\0')
	{
		sub[i] = '\0';
		return (sub);
	}
	while (i < sub_len)
	{
		sub[i] = s[j];
		i++;
		j++;
	}
	sub[i] = '\0';
	return (sub);
}
//	sub = ft_strdup(s + start);
// reservar sólo la memoria estrictamente necesaria; para ello,
// calcular primero la longitud que tendrá la subcadena (SUB_LEN)
// &s[start] es otra manera más elegante de (s + start)