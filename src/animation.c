/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:23:12 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/24 19:23:13 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animation(t_game *game)
{
	if (game->frame == 4000)
	{
		game->data.current_wall_ptr = game->data.wall1_ptr;
		draw_map(game);
	}
	if (game->frame == 7000)
	{
		game->data.current_collectible_ptr = game->data.collectible2_ptr;
		draw_map(game);
	}
	if (game->frame > 10000)
	{
		game->data.current_wall_ptr = game->data.wall2_ptr;
		game->data.current_collectible_ptr = game->data.collectible1_ptr;
		draw_map(game);
		game->frame = 0;
	}
	game->frame++;
	usleep(50);
	return (0);
}
