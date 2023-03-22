/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 04:32:59 by jules             #+#    #+#             */
/*   Updated: 2023/03/12 03:20:47 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**add_cmd_slash(char **paths)
{
	int 	i;

	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	return (paths);
}

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	free_all(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->file_input);
	close(pipex->file_output);
	while (pipex->tab_path[i])
	{
		free(pipex->tab_path[i]);
		i++;
	}
	free(pipex->tab_path);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

int main(int argc, char **argv, char **envp)
{
    pid_t pid1;
    pid_t pid2;
    t_pipex *pipex;

    if (argc != 5)
        return (msg_write_error("Error input, number arguments invalid"));
    pipex = malloc(sizeof(t_pipex));
    if (!pipex)
        return (0); 
    pipex->file_input = open(argv[1], O_RDONLY);
    if (pipex->file_input == -1)
        msg_send_error("Error file input");
    pipex->file_output = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
    if (pipex->file_output == -1)
        msg_send_error("Error file output");
    if (pipe(pipex->tube) == -1)
		msg_send_error("Error pipe");
    pipex->path = find_path(envp);
    pipex->tab_path = ft_split(pipex->path, ':');
    pipex->tab_path = add_cmd_slash(pipex->tab_path);
    pid1 = fork();
    if (pid1 == 0)
        child_prog(pipex, argv, envp);
    pid2 = fork();
    if (pid2 == 0)
        second_child_prog(pipex, argv, envp);
    close_pipes(pipex);
    waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
    free_all(pipex);
	return (0);
}