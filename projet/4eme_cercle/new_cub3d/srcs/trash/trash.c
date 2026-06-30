/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:02:25 by amkhelif          #+#    #+#             */
/*   Updated: 2026/06/23 15:12:19 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"
#include <stdio.h>

void	print_double_tab(char **tab)
{
	int i;

	// Sécurité : on vérifie que le tableau existe bien avant de le lire
	if (!tab)
		return ;

	i = 0;
	// On parcourt le tableau jusqu'à rencontrer le pointeur NULL de fin
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
}


void	print_textures(t_info *info)
{
	if (!info)
		return ;
	printf("\n=== DEBUG: TEXTURES EXTRACTED ===\n");
	
	// Utilisation d'une condition ternaire pour éviter les segfaults si c'est NULL
	printf("NO : %s\n", info->config.no_texture ? info->config.no_texture : "(null)");
	printf("SO : %s\n", info->config.so_texture ? info->config.so_texture : "(null)");
	printf("WE : %s\n", info->config.we_texture ? info->config.we_texture : "(null)");
	printf("EA : %s\n", info->config.ea_texture ? info->config.ea_texture : "(null)");
	
	printf("=================================\n\n");
}