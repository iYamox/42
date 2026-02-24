/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:34:06 by amary             #+#    #+#             */
/*   Updated: 2026/02/24 13:38:26 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	int	n = argc - 2;
	int	target = atoi(argv[1]);

	for (int mask = 0; mask < (1 << n); mask++)
	{
		int sum = 0;
		int	first = 0;
		
		for (int i = 0; i < n; i++)
		{
			if ((mask >> i) & 1)
				sum += atoi(argv[2 + i]);
		}
		if (sum == target)
		{
			for (int i = 0; i < n; i++)
			{
				if ((mask >> i) & 1)
				{
					if (first)
						printf(" ");
					printf("%d", atoi(argv[2 + i]));
					first = 3;
				}
			}
			printf("\n");
		}
	}
	return (0);
}
