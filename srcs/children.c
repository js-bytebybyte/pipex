/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:50:47 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/11/13 16:55:17 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child1_process(t_pipex *p)
{
	if (p->fd1 < 0)
		exit (1);
	if (dup2(p->pfd[WRITE_END], STDOUT_FILENO) == -1)
	{
		perror("dup2 error");
		exit (1);
	}
	if (dup2(p->fd1, STDIN_FILENO) == -1)
	{
		perror("dup2 error");
		exit (1);
	}
	close_pipe(p);
	close_fds(p);
	execute_cmd(p->cmds1, p);
}


void	child2_process(t_pipex *p)
{
	if (p->fd2 < 0)
		exit (1);
	if (dup2(p->pfd[READ_END], STDIN_FILENO) == -1)
	{
		perror("dup2 error");
		exit (1);
	}
	if (dup2(p->fd2, STDOUT_FILENO) == -1)
	{
		perror("dup2 error");
		exit (1);
	}
	close_pipe(p);
	close_fds(p);
	execute_cmd(p->cmds2, p);
}
