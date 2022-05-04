/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_microshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:13:17 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/04 14:19:25 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		write(1, str[i], 1);
		i++;
	}
}

int ft_execute(char **argv, char*env, int tmp, int i)
{
	argv[i] = NULL;
	close(tmp);
	execute(argv[i], argv, env);
	ft_putstr("error: cannot execute ");
	ft_putstr(argv[0]);
	ft_putstr("\n");
	return (1);
}

int main(int argc, char **argv, char **env)
{
/*	int i;
	int fd_tmp;
	int fd[2];
	int pid;

	i = 0;
	pid = 0;
	fd_tmp = dup(STDIN_FILENO);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
		{
			if (i != 2)
				ft_putstr("error: cd: bad arguments\n");
			else if (chdir(argv[1]) != 0)
			{
				ft_putstr("error: cd: cannot execute ");
				ft_putstr(argv[1]);
				ft_putstr("\n");
			}
		}
		
		
	}*/
	int i;
	int tmp_fd;
	int pid;
	int fd[2];

	i = 0;
	pid = 0;
	tmp_fd = dip(STDIN_FILENO);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(argv[1], "cd") == 0)
		{
			if (i != 2)
				ft_putstr("error: cd: bad arguments\n");
			else if (chdir(argv[1]) != 0)
			{
				ft_putstr("error: cd: cannot execute ");
				ft_putstr(argv[1]);
				ft_putstr("\n");
			}
		}
		else if (argv != &argv[i] && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			pid = fork;
			if (pid == 0)
			{
				dup2(tmp_fd, STDIN_FILENO);
				if (ft_execute(argv, env, tmp_fd, i))
					return (1);
			}
			else
			{
				close(tmp_fd);
				waitpid(-1, NULL, WUNTRACED);
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		
	}
}
