/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:34:34 by asimonin          #+#    #+#             */
/*   Updated: 2023/10/06 16:31:18 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_(int *fd)
{
	if (*fd == -1)
		return ;
	close(*fd);
	*fd = -1;
}

void	init(int ac, char **av, t_data *var)
{
	ft_memset(var, 0, sizeof(t_data));
	var -> nbr_cmd = ac - 3;
	var -> pid = malloc(sizeof(int) * (var -> nbr_cmd));
	var -> in = av[1];
	var -> out = av[ac - 1];
	var -> prev_pipe = -1;
}

/*check which argument it is, get the path using the env, 
split to only get the command without the flags (ex ls 	-l)
then verify if this command exist				cmd_flag[0] cmd_flag[1]
use execve to execute the command*/

void	child_process(t_data *var, int i, char *cmd, char **env)
{
	redirect(var, i);
	var->cmd_flag = ft_split(cmd, ' ');
	if (!ft_strrchr(cmd, '/'))
	{
		get_path(var, env);
		var->cmd = find_path(var, var->cmd_flag[0]);
	}
	else
		var->cmd = ft_strdup(var -> cmd_flag[0]);
	if (var->cmd)
		execve(var->cmd, var->cmd_flag, env);
	if (errno == 13 && (ft_strrchr(var->cmd_flag[0], '/')))
		printf("%s: Permission denied\n", var->cmd_flag[0]);
	else if (ft_strrchr(var->cmd_flag[0], '/'))
		printf("%s: No such file or directory\n", var->cmd_flag[0]);
	else
		printf("%s: Command not found\n", var->cmd_flag[0]);
	free_all(var);
}

/*fd[0] is the read end of the pipe
fd[1] is the write end of the pipe
once we read we can close the write end */

void	parent_process(t_data *var)
{
	close_(&var->fd[1]);
	if (var->prev_pipe != -1)
		close_(&var->prev_pipe);
	var->prev_pipe = var->fd[0];
}

int	main(int ac, char **av, char **env)
{
	t_data	var;
	int		i;

	i = -1;
	if (ac != 5)
		return (write(1, "Wrong amount of arguments\n", 27), 1);
	init(ac, av, &var);
	while (++i < var.nbr_cmd)
	{
		if (i != var.nbr_cmd - 1)
			pipe(var.fd);
		var.pid[i] = fork();
		if (var.pid[i] == -1)
			free_all(&var);
		if (var.pid[i] == 0)
			child_process(&var, i, av[i + 2], env);
		else
			parent_process(&var);
	}
	i = 0;
	while (i < var.nbr_cmd)
		waitpid(var.pid[i++], &var.status, 0);
	return (free(var.pid), var.status);
}
