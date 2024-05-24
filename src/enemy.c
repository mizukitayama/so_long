/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:23:29 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/24 19:23:30 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_enemy(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (y <= 1)
	{
		x = -1;
		while (x <= 1)
		{
			if (game->map[game->exit_y + y][game->exit_x + x] == '0')
			{
				game->map[game->exit_y + y][game->exit_x + x] = 'X';
				game->enemy_x = game->exit_x + x;
				game->enemy_y = game->exit_y + y;
				return ;
			}
			x++;
		}
		y++;
	}
	game->enemy_x = 0;
	game->enemy_y = 0;
}

static bool	move_horizontal(t_game *game, int direction)
{
	if (direction == 3 && game->map[game->enemy_y - 1][game->enemy_x] == '0')
	{
		game->map[game->enemy_y - 1][game->enemy_x] = 'X';
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->enemy_y = game->enemy_y - 1;
		return (true);
	}
	else if (direction == 4
		&& game->map[game->enemy_y + 1][game->enemy_x] == '0')
	{
		game->map[game->enemy_y + 1][game->enemy_x] = 'X';
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->enemy_y = game->enemy_y + 1;
		return (true);
	}
	return (false);
}

static bool	move_vertical(t_game *game, int direction)
{
	if (direction == 1 && game->map[game->enemy_y][game->enemy_x - 1] == '0')
	{
		game->map[game->enemy_y][game->enemy_x - 1] = 'X';
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->enemy_x = game->enemy_x - 1;
		return (true);
	}
	else if (direction == 2
		&& game->map[game->enemy_y][game->enemy_x + 1] == '0')
	{
		game->map[game->enemy_y][game->enemy_x + 1] = 'X';
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->enemy_x = game->enemy_x + 1;
		return (true);
	}
	return (false);
}

void	move_enemy(t_game *game)
{
	int		direction;
	bool	moved;
	int		tries;

	moved = false;
	tries = 0;
	if (game->enemy_x == 0 && game->enemy_y == 0)
		return ;
	while (!moved && tries < 100)
	{
		direction = rand() % 4 + 1;
		if (direction <= 2)
			moved = move_vertical(game, direction);
		else
			moved = move_horizontal(game, direction);
		tries ++;
	}
}
