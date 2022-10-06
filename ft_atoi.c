/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:01:21 by roruiz-v          #+#    #+#             */
/*   Updated: 2022/10/06 12:19:47 by roruiz-v         ###   ########.fr       */
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

static int	ft_getnum(const char *str, size_t i, int sign, int n)
{
	size_t	j;
	int		weight;

	j = i;
	weight = 1;
	while (ft_isdigit(str[i]) && str[i] != '\0')
		i++;
	while (i-- > j)
	{
		n = n + (str[i] - 48) * weight;
		weight = weight * 10;
	}
	if (sign != 0)
		return (n * sign);
	else
		return (n);
}

static int	ft_idsign(const char *str, size_t i, int sign)
{
	if (str[i] == '+')
		sign = +1;
	else if (str[i] == '-')
		sign = -1;
	return (sign);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		num;
	int		sign;

	i = 0;
	num = 0;
	sign = 0;
	while (!ft_isdigit(str[i]) && str[i] != '\0')
	{
		if (ft_isdigit(str[i]) || (str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else if ((str[i] == '+' || str[i] == '-') && sign == 0)
		{
			sign = ft_idsign(str, i, sign);
			i++;
			if (!ft_isdigit(str[i]))
				return (0);
		}
		else
			return (0);
	}
	if (ft_isdigit(str[i]))
		return (ft_getnum(str, i, sign, num));
	return (0);
}
