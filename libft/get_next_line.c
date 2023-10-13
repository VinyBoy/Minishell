/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:13:30 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/28 18:57:01 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_only_line(char *stock)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!stock[i])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		str[j] = stock [j];
		j++;
	}
	if (stock[i] == '\n')
	{
		str[i] = stock[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_keep_rest(char *stock)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	str = malloc((strlen_gnl(stock) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	while (stock[i])
		str[j++] = stock[i++];
	str[j] = '\0';
	free(stock);
	return (str);
}

char	*ft_read_join(int fd, char *stock)
{
	char	*buf;
	int		size_read;

	size_read = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (!ft_strchr(stock, '\n') && size_read != 0)
	{
		size_read = read(fd, buf, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[size_read] = '\0';
		stock = ft_strjoin_gnl(stock, buf);
	}
	free(buf);
	return (stock);
}

char	*get_next_line(int fd, int val)
{
	static char	*stock;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (val == 1)
	{
		return (free(stock), NULL);
	}
	stock = ft_read_join(fd, stock);
	if (!stock)
		return (NULL);
	str = ft_only_line(stock);
	stock = ft_keep_rest (stock);
	return (str);
}
