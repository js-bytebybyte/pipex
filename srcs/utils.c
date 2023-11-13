/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:10:27 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/11/10 16:02:42 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_struct(t_pipex *p)
{
	free_array(p->paths);
	free_array(p->cmds1);
	free_array(p->cmds2);
}

void	close_fds(t_pipex *p)
{
	close(p->fd1);
	close(p->fd2);
}

void	close_pipe(t_pipex *p)
{
	close(p->pfd[READ_END]);
	close(p->pfd[WRITE_END]);
}

int	ft_perror(char *s)
{
	perror(s);
	return (1);
}
