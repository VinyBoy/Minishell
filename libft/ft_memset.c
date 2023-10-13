/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:46:03 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/22 14:21:44 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char str[] = "ffffffffffffffffffffffffffffffffffffffffff";
	printf("%s\n", (char *)ft_memset(str + 5, 'o', 10) - 5);

	printf("\n");
	printf("%s\n", (char *)memset(str + 5, 'o', 10) - 5);
}
*/