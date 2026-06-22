/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 11:38:05 by amary             #+#    #+#             */
/*   Updated: 2026/06/22 15:56:16 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int		j;
	int		i;
	char	c;

	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * " << std::endl, 0);
	else
	{
		j = 1;
		while (argv[j])
		{
			i = 0;
			while (argv[j][i])
			{
				c = std::toupper(argv[j][i]);
				std::cout << c;	
				i++;
			}
			j++;
		}
		std::cout << std::endl;
	}
	return (0);
}
