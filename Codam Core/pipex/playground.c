/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   playground.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 17:00:58 by root          #+#    #+#                 */
/*   Updated: 2025/02/03 16:42:43 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>


#pragma region fork
    // int	main(void)
    // {
    // 	int		pipefd[2]; // 0 = read && 1 = write
    // 	char	*buffer[255] = { 0 };

    // 	pipe(pipefd);
    // 	write(pipefd[1], "msg", 3);
    // 	if (fork() >  0) // parent will continue writing and child will continue  from this line
    // 		return (0);
    // 	else 
    // 		read(pipefd[0], buffer, 3);

    // 	printf("Got from pipe: %s\n", buffer);

    // 	return (0);
    // }

    // int	main(void)
    // {
    // 	int	id;

    // 	id = fork();
    // 	if (id == 0);
    // 		sleep(1);
    // 	printf("Current ID: %d,  Parent ID: %d\n", getpid(), getppid());
    // 	if (id != 0)
    // 		wait (NULL);

    // 	return (0);
    // }
#pragma endregion

#pragma region execve
    // USES A COMMAND ls -l ON THE CHILD
    // int	main(void)
    // {
    // 	int		process_id;
    // 	char	*argv[] = {"/bin/ls", "-l", NULL};

    // 	process_id = fork();
    // 	if (process_id == -1)
    // 		return (perror("Fork failed"),  1);
    // 	printf("%d\n", process_id);

    // 	if (process_id == 0)
    // 	{
    // 		if (execve(argv[0], argv, NULL) == -1)
    // 			return (perror("Could not execute child process"), 1);
    // 	}
    // 	else
    // 		waitpid(process_id, NULL, 0);
    // 		printf("Child process completed.\n");

    // 	return (0);
    // }

    // int	main(void)
    // {
    // 	int		process_id;
    // 	char	*argv[] = {"/bin/echo", "Hello", NULL};

    // 	process_id = fork();
    // 	if (process_id == -1)
    // 		return (perror("Fork failed"),  1);
    // 	printf("%d\n", process_id);

    // 	if (process_id == 0)
    // 	{
    // 		if (execve(argv[0], argv, NULL) == -1)
    // 			return (perror("Could not execute child process"), 1);
    // 	}
    // 	else
    // 		waitpid(process_id, NULL, 0);
    // 		printf("Child process completed.\n");

    // 	return (0);
    // }
#pragma  endregion

