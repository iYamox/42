/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exo01.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:16:42 by amary             #+#    #+#             */
/*   Updated: 2026/05/26 20:27:24 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return ;
}

void	ft_write_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	ft_putstr(str);
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_write_upper(argv[1]);
	else
		return (write(1, "Argument error\n", 16), 0);
}
