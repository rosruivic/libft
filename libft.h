/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:42:10 by roruiz-v          #+#    #+#             */
/*   Updated: 2022/10/06 14:50:12 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>

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
void		*ft_calloc(size_t count, size_t size);

#endif
