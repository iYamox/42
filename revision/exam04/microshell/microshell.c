/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:18:45 by amary             #+#    #+#             */
/*   Updated: 2026/06/22 13:28:00 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int err(char *str)
{
	int	i = 0;

	while (str[i])
		write(2, str[i++], 1);
	return (1);
}

int	cd(char **argv, int i)
{
	if (i != 2)
		return (err("error: cd: bad arguments\n"));
	else if (chdir(argv[1] == -1))
		return (err("error: cd: cannot change directory to "), err(argv[1]), err("\n"));
	return (0);
}

