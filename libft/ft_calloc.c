/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:57:33 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/28 19:02:57 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		i;
	void	*str;

	if (size > SIZE_MAX / nmemb)
		return (NULL);
	if (size == 0 || nmemb == 0)
		return (malloc(0));
	i = nmemb * size;
	str = malloc(i);
	if (!str)
		return (NULL);
	ft_bzero (str, i);
	return (str);
}
