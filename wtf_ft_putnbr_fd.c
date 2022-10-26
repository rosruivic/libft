/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:01:54 by roruiz-v          #+#    #+#             */
/*   Updated: 2022/10/26 21:51:20 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_itoa(n);
	if (s)
	{	
		write(fd, s, ft_strlen(s));
		free(s);
	}
}
