/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:37:32 by asimonin          #+#    #+#             */
/*   Updated: 2023/05/09 23:27:24 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_fd(t_data *var, int fd)
{
	if (fd < 0)
	{
		perror("pipex");
		close_fd(var);
		free_all(var);
		exit(1);
	}
}

void	here_doc(t_data *var)
{
	char	*str;

	if (pipe(var->fd) == -1)
		free_all(var);
	while (1)
	{
		ft_putstr_fd("heredoc>: ", 1);
		str = get_next_line(0, 0);
		if (! str || !ft_strcmp(str, var->limiter))
			break ;
		ft_putstr_fd(str, var->fd[1]);
		free(str);
	}
	free(str);
	get_next_line(0, 1);
	close_(&var->fd[1]);
	free(var->limiter);
	var->here_docfd = var->fd[0];
}
