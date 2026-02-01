/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:05:36 by amary             #+#    #+#             */
/*   Updated: 2026/01/10 23:16:20 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	load_texture(t_game *game, int init)
{
	if (init == 1)
		ft_init_texture(game);
	ft_load_top(game);
	ft_load_mid(game);
	ft_load_down(game);
	return ;
}
