/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:54:13 by roruiz-v          #+#    #+#             */
/*   Updated: 2022/10/24 20:28:08 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calcpositions(int n)
{
	int	posit;

	posit = 1;
	while (n >= 10)
	{
		n = n / 10;
		posit++;		
	}
	return (posit);
}

static char	*ft_fillstr(int n, char * nbr, unsigned int posit, char neg)
{
	while (posit > 0)
	{
		nbr[posit - 1] = 48 + (n % 10);
		n = n / 10;
		posit--;
	}
	if (neg == '-')
		nbr[0] = neg;
	return (nbr);
}

char	*ft_itoa(int n)
{
	char		*nbr;
	unsigned int	posit;	/* numero de posiciones que se reservarán en el string */
	char		neg;	/* chivato de que se trata de un numero negativo */
	
	posit = 0;
	neg = '+';
	if (n < 0 && n != -2147483648) /* si es negativo, ponemos posit a 1 para que callokee una posición extra para el signo negativo */
	{
		neg = '-';	/* la primera posición del string será para esta variable sólo en el caso de ser negativo */
		posit = 1;
		n = n * (-1);	/* y lo ponemos en positivo antes de calcular cuantas posiciones tiene */
	}
	else if (n == -2147483648)
	{
		/* AQUÍ TENGO QUE HACER EL CASO ESPECIAL PARA EL MÍNIMO (NO TIENE RÉPLICA EN LOS POSITIVOS AL MULTIPLICAR POR -1) */
	}
	posit = posit + ft_calcpositions(n);
	nbr = (char *)ft_calloc((size_t)posit + 1, sizeof(char));
	if (!nbr)
		return(NULL);
	nbr = ft_fillstr(n, nbr, posit, neg);
	return (nbr);
}
