/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:44:36 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/11/13 16:49:58 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	find_path(char **envp, char *s)
{
	int		i;
	size_t	j;

	if (!envp)
		return (-1);
	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && s[j] == envp[i][j])
			j++;
		if (j == ft_strlen(s))
			return (i);
		i++;
	}
	return (-1);
}

char	**find_binary_paths(char **envp)
{
	char	**paths;
	int		path;
	int		i;

	path = find_path(envp, "PATH=");
	if (path == -1)
		return (NULL);
	paths = ft_split(envp[path] + 5, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		if (!paths[i]) // ajusted??
		{
			free_array(paths);
			return (NULL);
		}
		i++;
	}
	return (paths);
}

void	execute_cmd(char **cmd_args, t_pipex *p)
{
	char	*cmd_path;
	int		i;

	i = 0;
	while (p->paths[i])
	{
		cmd_path = ft_strjoin(p->paths[i], cmd_args[0]);
		if (!cmd_path)
			exit (1);
		if (!access(cmd_path, X_OK))
		{
			execve(cmd_path, cmd_args, p->envp);
			perror(cmd_path);
			exit (1);
		}
		free(cmd_path);
		i++;
	}
	ft_putstr_fd(cmd_args[0], 2); // adjusted
	ft_putstr_fd(": command not found\n", 2); // adjusted
	exit (127); // adjusted
}
