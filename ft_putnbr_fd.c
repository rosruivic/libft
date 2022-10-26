/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:54:46 by roruiz-v          #+#    #+#             */
/*   Updated: 2022/10/26 22:12:30 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	c = ' ';
	while (n > 0)
	{
		c = 48 + (n % 10);
		write(fd, &c, 1);
		n = n / 10;
	}
}
/* esto manda la cadena al revés
en la piscina lo hice con un vector
que mandaba imprimir dado la vuelta
(mirarlo e intentar entender más maneras de hacerlo)*/