/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:52:32 by asimonin          #+#    #+#             */
/*   Updated: 2023/05/09 23:54:22 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(t_data *var)
{
	close_(&var->fd[0]);
	close_(&var->fd[1]);
}

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

/* if i = 0, its the 1st command, we need to redirect
the standard input toward the infile
if i = nbr_cmd - 1 , its the last command*/

void	redirect(t_data *var, int i)
{
	int	fd;

	if (i == 0)
	{
		fd = open(var->in, O_RDONLY);
		check_fd(var, fd);
		dup2(fd, STDIN_FILENO);
		close_(&fd);
	}
	else if (i == var->nbr_cmd - 1)
	{
		fd = open(var->out, O_CREAT | O_TRUNC | O_WRONLY, 0666);
		check_fd(var, fd);
		dup2(fd, STDOUT_FILENO);
		close_(&fd);
	}
	if (i != 0)
	{
		dup2(var->prev_pipe, STDIN_FILENO);
		close_(&var->prev_pipe);
	}
	if (i != var->nbr_cmd - 1)
		dup2(var->fd[1], 1);
	close_fd(var);
}

char	*find_path(t_data *var, char *cmd)
{
	int		i;
	char	*tmp;
	char	*new;

	i = 0;
	if (var->path == NULL)
	{
		new = ft_strdup(cmd);
		if (new == NULL)
			free_all(var);
		return (new);
	}
	while (var->path && var->path[i])
	{
		tmp = ft_strjoin(var->path[i], "/");
		new = ft_strjoin(tmp, cmd);
		if (access(new, F_OK | X_OK) != -1)
			return (new);
		free(tmp);
		free(new);
		i++;
	}
	return (NULL);
}

/*search in the env for the path then split it*/

void	get_path(t_data *var, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			var->path = ft_split(env[i] + 5, ':');
			if (!var->path)
			{
				free(var->path);
				exit(1);
			}
		}
		i++;
	}
}
