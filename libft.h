/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:42:10 by roruiz-v          #+#    #+#             */
/*   Updated: 2022/10/19 16:05:47 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>

/**
 * @brief guapa
 * 
 * @param var 
 * @return int 
 */
int			ft_isalpha(int var);
int			ft_isdigit(int var);
int			ft_isalnum(int var);
int			ft_isascii(int var);
int			ft_isprint(int var);
size_t		ft_strlen(char const *str);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * @brief 
 * 
 * @param s 
 * @param c 
 * @param n 
 * @return void* 
 */
void		*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief 
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Locates the first occurrence of the str needle in the str haystack
 * @param len It means the len 1st positions of haystack to search into
 * @return The position of the first occurrence
 */
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

/**
 * @brief Converts the first consecutives numeric representation (after spaces)
 * and stops when find a no-numeric character.
 * 
 * @param str 
 * @return int (the numeric representation of the "number" found in the str)
 */
int			ft_atoi(const char *str);

/**
 * @brief It contiguously allocates enough space for count objects that are 
 		 size bytes of memory each and returns a pointer to the allocated memory
		 The allocated memory is filled with bytes of value zero (ft_bzero).
 * 
 * @param count 
 * @param size 
 * @return void* 
 */
void		*ft_calloc(size_t count, size_t size);

/**
 * @brief The strdup() function allocates sufficient memory for a copy of the
     string s1, does the copy, and returns a pointer to it. The pointer
     may subsequently be used as an argument to the function free.
     If insufficient memory is available, NULL is returned and errno is set
     to ENOMEM
 * 
 * @param s1 
 * @return char* 
 */
char		*ft_strdup(const char *s1);

/**
 * @brief	Reserva (con malloc) y devuelve un substring del string 's'.
 * 			El substring empieza desde el índice 'start' y tiene una
 * 			longitud máxima de 'len'.
 * 
 * @param s :	String desde el que crear el substring
 * @param start : Índice del carácter en 's' desde el que empezar el substring
 * @param len :	Longitud máxima de la substring
 * @return char* : Substring resultante (NULL si falla la reserva de memoria)
 */
char		*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * @brief : Reserva (con malloc) y devuelve una cadena nueva formada por
 * 					la concatenación de 's1' y 's2'
 * 
 * @param s1 Primer string
 * @param s2 Segundo string que se añade al final de 's1'
 * @return char* Devuelve el nuevo string; NULL si falla la reserva de memoria
 */
char		*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates (with malloc) and returns a copy of ’s1’ with the characters
 * specified in ’set’ removed from the beginning and the end of the string.
 * 
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return char* - The trimmed string. NULL if the allocation fails.
 */
char		*ft_strtrim(char const *s1, char const *set);
/**
 * @brief Allocates (with malloc) and returns an array of strings obtained 
 * 				by splitting ’s’ using the character ’c’ as a delimiter. 
 * 				The array must end with a NULL pointer.
 * 
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return char** - The array of new strings resulting from the split.
 * 					NULL if the allocation fails.
 */
char		**ft_split(char const *s, char c);

#endif
