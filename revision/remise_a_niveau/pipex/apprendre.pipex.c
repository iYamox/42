/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apprendre.pipex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:08:18 by amary             #+#    #+#             */
/*   Updated: 2026/02/13 12:47:44 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
 
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void)
{
    int fd[2];
    if (pipe(fd) == -1)
		return 1;
    pid_t pid = fork();
    if (pid == -1)
		return 1;
    if (pid == 0) {
        // ENFANT : lit
        close(fd[1]); // ferme l'écriture
        char buf[128];
        int n = read(fd[0], buf, sizeof(buf) - 1);
        if (n > 0) {
            buf[n] = '\0';
            printf("ENFANT a reçu: \"%s\"\n", buf);
        }
        close(fd[0]);
        return 0;
    } else {
        // PARENT : écrit
        close(fd[0]); // ferme la lecture
        const char *msg = "secret";
        write(fd[1], msg, 6);
        close(fd[1]);
        waitpid(pid, NULL, 0);
        return 0;
    }
}

