/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:40:31 by roruiz-v          #+#    #+#             */
/*   Updated: 2022/11/05 22:24:35 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* PRIMERO: hago un clon de la lista (solo los nodos vacíos)
	por cada nodo oldlst voy creando un nodo de newlst
	(sin clonar, se queda sin contenido, y ya le pasaré la función luego)
	*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**ptrnewlst;
	t_list	*newlst;

	*ptrnewlst = NULL;
	newlst = ft_lstnew(lst);
	if (!lst) /* SI NO ME PASAN PUNTERO VÁLIDO, DEVUELVO NODO VACÍO */
		return (newlst);
	*ptrnewlst = newlst; /* EL PRIMER NODO YA ESTÁ CREADO JUSTO ANTES */
	while (lst) /* CON PUNTERO VÁLIDO, CREO EL RESTO NODOS ITERÁNDOLOS */
	{
		newlst = f(lst);
		lst = lst->next;
		newlst = ft_lstnew(newlst);
		if (!newlst)
		{
			ft_lstclear(*ptrnewlst, del);
			return (NULL);
		}
	}
	return (newlst);
}
