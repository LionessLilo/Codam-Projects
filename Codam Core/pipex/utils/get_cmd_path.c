/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_cmd_path.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 14:13:34 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/05 18:06:06 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*find_cmd_directory(char **directories, char *cmd);
char	*ft_get_env(char **envp);

char	*get_cmd_path(char *cmd, char **env)
{
	char	*path_from_env;
	char	**directories;
	char	*cmd_directory;

	path_from_env = ft_get_env(env);
	if (!path_from_env)
		return (NULL);
	directories = ft_split(path_from_env, ':');
	if (!directories)
		return (NULL);
	cmd_directory = find_cmd_directory(directories, cmd);
	if (!cmd_directory)
		return (NULL);
	return (cmd_directory);
}

char	*ft_get_env(char **envp)
{
	int		pos_in_list;
	char	*path_directories;
	char	*start_copying;

	pos_in_list = 0;
	while (envp[pos_in_list])
	{
		if (ft_strncmp(envp[pos_in_list], "PATH", 4) == 0)
		{
			start_copying = ft_strchr(envp[pos_in_list], '=');
			path_directories = ft_strdup(start_copying + 1);
			return (path_directories);
		}
		pos_in_list++;
	}
	perror("Failed to get path of directories");
	return (NULL);
}

char	*find_cmd_directory(char **directories, char *cmd)
{
	char	*directory_and_slash;
	char	*full_directory;
	int		pos_in_directories;

	pos_in_directories = 0;
	while (directories[pos_in_directories])
	{
		directory_and_slash = ft_strjoin(directories[pos_in_directories], "/");
		if (!directory_and_slash)
			return (NULL);
		full_directory = ft_strjoin(directory_and_slash, cmd);
		if (!full_directory)
			return (NULL);
		free(directory_and_slash);
		if (access(full_directory, X_OK) == 0)
			return (full_directory);
		pos_in_directories++;
	}
	perror("Failed to find cmd directory");
	return (NULL);
}
