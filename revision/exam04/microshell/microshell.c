#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	ft_err(char *str)
{
	int	i = 0;

	while (str[i])
		write(2, &str[i++], 1);
	return (1);
}

int	ft_cd(char **argv, int i)
{
	if (i != 2)
		return (ft_err("error: cd: bad arguments\n"));
	if (chdir(argv[1]) == -1)
		return (ft_err("error: cd: cannot change directory to "), ft_err(argv[1]), ft_err("\n"));
	return (0);
}

int	exec(char **argv, char **envp, int i)
{
	int	status;
	int	fd[2];
	int	has_pipe = argv[i] && !strcmp(argv[i], "|");

	if (has_pipe && pipe(fd) == -1)
		return (ft_err("error: fatal\n"));

	int pid = fork();
	if (pid == 0)
	{
		argv[i] = NULL;
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return (ft_err("error: fatal\n"));
		execve(argv[0], argv, envp);
		return (ft_err("error: cannot execute "), ft_err(argv[0]), ft_err("\n"));
	}

	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (ft_err("error: fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	int	i = 0;
	int	status = 0;

	if (argc > 1)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (!strcmp(argv[0], "cd"))
				status = ft_cd(argv, i);
			else if (i)
				status = exec(argv, envp, i);
		}
	}
	return (status);
}
