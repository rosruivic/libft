/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:41:54 by roruiz-v          #+#    #+#             */
/*   Updated: 2022/10/06 08:12:04 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  Converts the initial portion of the string pointed (passing spaces until
  	finds a number, and then from there to last until finds a no-number
  	character, where it stops).
	Omite los caracteres en blanco anteriores (como espacios, 
		sangría de tabulación, etc.), no inicia la conversión hasta que encuentra 
		un número o un signo, y luego encuentra un non-number O. 
	La conversión termina cuando la cadena termina ('\0') 
		y se devuelve el resultado.
  RETURN VALUE: the int representation of the string found.

	j va a conservar la posición del primer número que encuentre;
	i-- va a conservar la posición del último número que encuentre.
	(tengo que ir recorriendo en orden inverso: unidades, decenas, centenas...)
*/
#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	j;
	int		num;
	int		weight;
	int		sign;

	i = 0;
	j = 0;
	num = 0;
	sign = 0;
	weight = 1;
	while (!ft_isdigit(str[i]) && str[i] != '\0')
	{
		if (ft_isdigit(str[i]) || (str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else if ((str[i] == '+' || str[i] == '-') && sign == 0)
		{
			if (str[i] == '+')
				sign = +1;
			else if (str[i] == '-')
				sign = -1;
		i++;
			if (!ft_isdigit(str[i]))
				return (0);
		}
		else
			return (0);
	}
	if (ft_isdigit(str[i]))
	{
		j = i;
		while (ft_isdigit(str[i]) && str[i] != '\0')
			i++;
		while (i-- > j)
		{
			num = num + (str[i] - 48) * weight;
			weight = weight * 10;
		}
		if (sign != 0)
			return (num * sign);
		else
			return (num);
	}
	return (0);
}
