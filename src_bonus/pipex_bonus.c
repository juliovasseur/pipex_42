

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

char	**add_cmd_slash(char **paths)
{
	int 	i;
	char *tmp;

	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(tmp, "/");
		free(tmp);
		i++;
	}
	return (paths);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (argc < here_doc_or_not(argv[1], pipex))
	{
		return (msg("ERR_INPUT"));
		free(pipex);
	}
	get_fd_infile(argv, pipex);
	get_fd_outfile(argv[argc - 1], pipex);
	pipex->nb_cmd = argc - 3 - pipex->here_doc;
	pipex->env_path = find_path(envp);
	pipex->tab_paths = ft_split(pipex->env_path, ':');
	if (!pipex->tab_paths)
		pipe_free(pipex);
	pipex->tab_paths = add_cmd_slash(pipex->tab_paths);
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
