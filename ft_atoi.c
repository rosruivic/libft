/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:00:53 by roruiz-v          #+#    #+#             */
/*   Updated: 2022/10/05 12:14:56 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  Converts the initial portion of the string pointed (passing spaces until
  	finds a number, and then from there to last until finds a no-number
  	character, where it stops).
  RETURN VALUE: the int representation of the string found.
*/
#include "libft.h"

int	ft_strchrtoint(char *str_num)
{
	int	k;
	int	nbr;
	int ascii;

	k = 0;
	nbr = 0;
	while (str_num[k] != '\0')
	{
		if (str_num[k] == 48)
			nbr = nbr + 0;
		k++;
	}
	return (nbr);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	j;
	char	*str_num;

	i = 0;
	j = 0;
	while (!ft_isnumber(str[i]) && str[i] != '\0')
		i++;
	if (ft_isnumber(str[i]))
	{
		while (ft_isnumber(str[i]) && str[i] != '\0')
		{	
			str_num[j] = str[i];
			i++;
			j++;
		}
		str_num[j] = '\0';
// Ahora transformo los char en int uno a uno y los voy sumando en nbr:		
// Llamo a la función que se va a encargar de transformar char en int:
		return (ft_strchrtoint(str_num));
	}
	return (NULL);
}
