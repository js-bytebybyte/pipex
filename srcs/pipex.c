/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:28:10 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/11/14 13:44:14 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	run_pipe(t_pipex *p)
{
	if (pipe(p->pfd) == -1)
		return (ft_perror("pipe error"));
	p->child1 = fork();
	if (p->child1 == -1)
	{
		close_pipe(p);
		return (ft_perror("fork error"));
	}
	if (p->child1 == 0)
		child1_process(p);
	p->child2 = fork();
	if (p->child2 == -1)
	{
		close_pipe(p);
		return (ft_perror("fork error"));
	}
	if (p->child2 == 0)
		child2_process(p);
	close_pipe(p);
	close_fds(p);
	waitpid(p->child1, NULL, 0);
	waitpid(p->child2, &p->status, 0); 
	return (0);
}

void	init_pipex(t_pipex *p, char **argv)
{
	p->cmds1 = ft_split(argv[2], ' ');
	if (!p->cmds1)
	{
		close_fds(p);
		exit (1);
	}
	p->cmds2 = ft_split(argv[3], ' ');
	if (!p->cmds2)
	{
		free_array(p->cmds1);
		close_fds(p);
		exit (1);
	}
	p->paths = find_binary_paths(p->envp);
	if (!p->paths || run_pipe(p))
	{
		free_struct(p);
		close_fds(p);
		exit (1);
	}
	free_struct(p);
}
