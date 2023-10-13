/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:46:12 by asimonin          #+#    #+#             */
/*   Updated: 2023/05/10 21:07:58 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
