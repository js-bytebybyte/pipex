/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:41:35 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/11/13 16:49:50 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* ------------------------ extra libs --------------------------------*/

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include "libft/libft.h"

/* ------------------------ pipe fds var ----------------------------------*/

# define WRITE_END 1
# define READ_END 0

/* ------------------------ pipex structure --------------------------*/

typedef struct s_pipex
{
	int		fd1;
	int		fd2;
	int		pfd[2];
	char	**paths;
	char	**cmds1;
	char	**cmds2;
	char	**envp;
	int		status;
	pid_t	child1;
	pid_t	child2;
}	t_pipex;

/* ------------------------ main pipex functions --------------------------*/

void	init_pipex(t_pipex *p, char **argv);
void	child1_process(t_pipex *process);
void	child2_process(t_pipex *process);

/* --------------------------- pipex utils --------------------------------*/

char	**find_binary_paths(char **envp);
void	execute_cmd(char **cmd_args, t_pipex *process);

/* -------------------------------- utils ----------------------------------*/

void	free_array(char **array);
void	free_struct(t_pipex *p);
void	close_pipe(t_pipex *p);
void	close_fds(t_pipex *p);
int		ft_perror(char *s);
#endif
