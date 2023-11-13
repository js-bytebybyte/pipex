/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:39:13 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/11/13 16:49:22 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	if (argc != 5)
	{
		ft_putendl_fd("incorrect number of arguments", 2);
		exit (1);
	}
	p.fd1 = open(argv[1], O_RDONLY); // adjusted
	if (p.fd1 < 0)
		perror(argv[1]); // adjusted
	p.fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (p.fd2 < 0)
		perror(argv[4]); // adjusted
	p.envp = envp;
	init_pipex(&p, argv);
	return (WEXITSTATUS(p.status)); // adjusted
}