/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:46:12 by asimonin          #+#    #+#             */
/*   Updated: 2023/05/10 21:07:58 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
		ft_free((void **)&tab[i]);
	ft_free((void **)&tab);
}

void	free_all(t_data *var)
{
	if (var -> path)
		ft_free_tab(var->path);
	if (var->cmd_flag)
		ft_free_tab(var->cmd_flag);
	ft_free((void **)&var->cmd);
	ft_free((void **)&var -> pid);
	exit(1);
}
