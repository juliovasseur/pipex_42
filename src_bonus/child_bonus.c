/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:58:41 by jules             #+#    #+#             */
/*   Updated: 2023/03/23 16:26:24 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static char	*get_cmd(char **path, char *command)
{
	int		i;
	char	*cmd;

	i = 0;
	while (path[i])
	{
		cmd = ft_strjoin(path[i], command);
		if (access(cmd, 0) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	return (NULL);
}

static void	sub_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

void	child(t_pipex *pipex, char **argv, char **envp)
{
	pipex->pid = fork();
	if (!pipex->pid)
	{
		if (pipex->idx == 0)
			sub_dup2(pipex->infile, pipex->pipe[0][1]);
		else if (pipex->idx == pipex->nb_cmd - 1)
			sub_dup2(pipex->pipe[(pipex->idx - 1) % 2][0], pipex->outfile);
		else
			sub_dup2(pipex->pipe[(pipex->idx - 1) % 2][0],
				pipex->pipe[pipex->idx % 2][1]);
		close_all_pipes(pipex);
		pipex->tab_cmd = ft_split(argv[2 + pipex->here_doc + pipex->idx], ' ');
		pipex->cmd = get_cmd(pipex->tab_paths, pipex->tab_cmd[0]);
		if (!pipex->cmd)
		{
			msg_pipe(pipex->tab_cmd[0]);
			child_free(pipex);
			free(pipex);
			exit(2);
		}
		execve(pipex->cmd, pipex->tab_cmd, envp);
	}
}
