/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:16:41 by asimonin          #+#    #+#             */
/*   Updated: 2023/05/10 21:07:28 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# define INT_MIN -2147483648

void	ft_free(void **data);
void	ft_free_tab(char **tab);

void	ft_putstr_fd(char *s, int fd);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t dstsize);

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(const char *s, char c);

#endif