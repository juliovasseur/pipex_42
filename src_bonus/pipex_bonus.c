/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:59:05 by jules             #+#    #+#             */
/*   Updated: 2023/03/23 15:20:50 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	close_all_pipes(t_pipex *pipex)
{
	close(pipex->pipe[0][0]);
	close(pipex->pipe[0][1]);
	close(pipex->pipe[1][0]);
	close(pipex->pipe[1][1]);
}

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	add_cmd_slash(char **paths)
{
	int		i;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(tmp, "/");
		free(tmp);
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (0);
	if (verif_all_and_get_file(argc, argv, pipex) == 0)
		return (2);
	pipex->nb_cmd = argc - 3 - pipex->here_doc;
	pipex->env_path = find_path(envp);
	pipex->tab_paths = ft_split(pipex->env_path, ':');
	if (!pipex->tab_paths)
		pipe_free(pipex);
	add_cmd_slash(pipex->tab_paths);
	pipe(pipex->pipe[0]);
	pipe(pipex->pipe[1]);
	pipex->idx = 0;
	while ((pipex->idx) < pipex->nb_cmd)
	{
		child(pipex, argv, envp);
		pipex->idx++;
	}
	close_all_pipes(pipex);
	waitpid(-1, NULL, 0);
	parent_free(pipex);
	return (0);
}
