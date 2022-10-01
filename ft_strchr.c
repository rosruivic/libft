/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 09:51:30 by roruiz-v          #+#    #+#             */
/*   Updated: 2022/10/01 12:49:30 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//La función devuelve la primera ocurrencia del argumento c en el string
char	*ft_strchr(const char *s, int c)
{
	unsigned char	search;

	search = (unsigned char) c;
	while (*s != search && *s != '\0')
		s++;
	if (*s == search)
		return ((char *) s);
	else
		return (NULL);
}
