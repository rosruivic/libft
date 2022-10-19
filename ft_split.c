/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:54:36 by roruiz-v          #+#    #+#             */
/*   Updated: 2022/10/19 18:27:06 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freedom(char **matrix, int word)
{	
	while (word >= 0)
	{
		free(matrix[word]);
		word--;
	}
	free(matrix);
	return (NULL);
}

/** ft_calcrows detecta separadores (cuenta cuántas palabras hay en strim)
strim es la string inicial limpiada de caracteres separadores a inicio y fin */
static size_t	ft_calcrows(char *strim, char c)
{
	int		i;
	size_t	words;

	i = 0;
	words = 0;
	while (strim[i] != '\0')
	{
		while (strim[i] != c && strim[i] != '\0')
		{
			i++;
		}
		if (strim[i] == c)
		{
			if (strim[i + 1] != c)
				words++;
			i++;
		}
	}
	return (words + 1);
}

//static char	**ft_putword(char **matrix, char *strim, size_t word, int wlen)
//{
//	int	j;
//	int	w_ini;
//
//	j = 0;
//	w_ini = 0;
//}

// ***********************************************************************
//
// 	cada vez que encuentro un separador (con STRCHR):
//		- DIMENSIONO y MALLOKEO LAS POSICIONES de ESA fila 
//		- EXTRAIGO con SUBSTR, MUDÁNDOLA a ESA fila de la MATRIX,
//		- Y DESTRUYO CONTENIDO DE PALABRA MUDADA con las tijeras STRTRIM, 
//		- dejando la string preparada para la siguiente vuelta hasta su fin
//	(al final, esta idea no ha sido desarrollada, ha salido otra cosa)
//	
//	***********************************************************************
//	word 	=> para saber en qué fila de la matriz estoy (= num palabra)	
//	i 		=> para saber en qué posición de strim estoy (lo recorro entero)
//	j 		=> para saber en qué posición de cada palabra de la matrix estoy
//	w_ini => para saber la primera posición de la palabra en la que estoy
//	w_len 	=> para saber la longitud de la palabra con la que estoy
//	***********************************************************************
static char	**ft_matrix_posit(char **matrix, char *strim, char c)
{
	size_t	word;
	int		i;	
	int		j;
	int		w_ini;

	word = 0;
	i = 0;
	while (word <= ft_calcrows(strim, c) && strim[i] != '\0')
	{
		j = 0;
		while (strim[i] == c && strim[i] != '\0')
			i++;
		w_ini = i;
		while (strim[i] != c && strim[i] != '\0')
			i++;
		matrix[word] = (char *)ft_calloc(((i - w_ini) + 1), sizeof(char));
		if (!matrix)
		{
			ft_freedom(matrix, word);
			return (NULL);
		}
		while (j < (i - w_ini))
		{
			matrix[word][j] = strim[w_ini + j];
			j++;
		}
		matrix[word][j] = '\0';
		word++;
	}
	return (matrix);
}

// para poder usar strtrim, tengo que mandar c dentro de un array (set)
// que primero mallokeo (y libero tras haber enviado el dato a strtrim)
char	**ft_split(char const *s, char c)
{
	char		*strim;
	char		*set;
	char		**matrix;
	size_t		words;

	words = 0;
	set = (char *)ft_calloc(2, sizeof(char));
	if (!set)
		return (NULL);
	set[0] = c;
	strim = ft_strtrim(s, set);
	free (set);
	set = NULL;
	words = ft_calcrows(strim, c);
	matrix = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	matrix = ft_matrix_posit(matrix, strim, c);
	return (matrix);
}
