/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:54:36 by roruiz-v          #+#    #+#             */
/*   Updated: 2022/10/20 18:03:55 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freedom(char **matrix, size_t word)
{	
	while (word >= 0)
	{
		free(matrix[word]);
		word--;
	}
	free(matrix);
	return (NULL);
}

static size_t	ft_calcrows(const char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			words++;
		i++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}	
	return (words);
}

//	***********************************************************************
//	word 	=> para saber en qué fila de la matriz estoy (= num palabra)	
//	i 		=> para saber en qué posición de s estoy (lo recorro entero)
//	w_ini => para saber la primera posición de la palabra en la que estoy
//	***********************************************************************
//	POR MIS OVARIOS, AQUÍ AHORA VOY A USAR EL SUBSTR, QUE PA ESTO ES
//	***********************************************************************
static char	**ft_matrix_posit(char **matrix, const char *s, char c, size_t words)
{
	size_t	word;
	size_t	i;	
	size_t	w_ini;

	word = 0;
	i = 0;
	while (word <= words && s[i] != '\0')
	{	
		while (s[i] == c && s[i] != '\0')
		{
			i++;
		}
		if (s[i] != c && s[i] != '\0')
		{
			w_ini = i;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		matrix[word] = (char *)ft_calloc(((i - w_ini) + 1), sizeof(char));
		if (!matrix)
		{
			ft_freedom(matrix, word);
			return (NULL);
		}
		matrix[word] = ft_substr(s, (unsigned int)w_ini, (i - w_ini));
		word++;
	}	
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char		**matrix;
	size_t		words;

	words = ft_calcrows(s, c);
	matrix = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!matrix)
			return (NULL);
	if (words > 0)
		matrix = ft_matrix_posit(matrix, s, c, words);
	return (matrix);
}
