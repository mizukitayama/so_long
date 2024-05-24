/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:05:23 by mtayama           #+#    #+#             */
/*   Updated: 2024/01/12 22:59:36 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(void *game)
{
	free_game(game, "Exiting prgram.");
	return (0);
}

int	deal_key(int key, t_game *game)
{
	static size_t	collectibles = 0;

	if (game->moves == 0)
		collectibles = game->collectibles;
	if (key == 13 || key == 126 || key == 119 || key == 65362)
		game->moves += move_up(game, &collectibles);
	else if (key == 1 || key == 125 || key == 115 || key == 65364)
		game->moves += move_down(game, &collectibles);
	else if (key == 0 || key == 123 || key == 97 || key == 65361)
		game->moves += move_left(game, &collectibles);
	else if (key == 2 || key == 124 || key == 100 || key == 65363)
		game->moves += move_right(game, &collectibles);
	else if (key == 53 || key == 65307)
		free_game(game, "Exiting prgram.");
	if (!(game->exit_x == game->player_x && game->exit_y == game->player_y))
		game->map[game->exit_y][game->exit_x] = 'E';
	draw_map(game);
	return (0);
}

int	expose_hook_func(void *game)
{
	draw_map(game);
	return (0);
}
