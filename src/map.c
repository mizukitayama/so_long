/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:04:07 by mtayama           #+#    #+#             */
/*   Updated: 2024/01/13 00:12:59 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_image(char c, size_t x, size_t y, t_data *data)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->current_wall_ptr, 50 * x, 50 * y);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->empty_space_ptr, 50 * x, 50 * y);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->current_collectible_ptr, 50 * x, 50 * y);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit_ptr, 50 * x, 50 * y);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_ptr, 50 * x, 50 * y);
	else if (c == 'X')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy_ptr, 50 * x, 50 * y);
}

void	draw_map(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_image(game->map[y][x], x, y, &game->data);
			x++;
		}
		y++;
	}
	print_moves(game, game->moves);
}

void	display_window(t_game *game)
{
	game->data.win_ptr = mlx_new_window(game->data.mlx_ptr,
			50 * game->width, 50 * (game->height) + 32, "so_long");
	if (game->data.win_ptr == NULL)
		free_game(game, "Error\nmlx_new_window() failed.");
	game->data.malloc_win_ptr = true;
	init_images(game);
	game->data.current_wall_ptr = game->data.wall1_ptr;
	game->data.current_collectible_ptr = game->data.collectible1_ptr;
	game->frame = 0;
	draw_map(game);
	mlx_key_hook(game->data.win_ptr, deal_key, game);
	mlx_hook(game->data.win_ptr, 17, 1L << 0, exit_hook, game);
	mlx_expose_hook(game->data.win_ptr, expose_hook_func, game);
	mlx_loop_hook(game->data.mlx_ptr, animation, game);
	mlx_loop(game->data.mlx_ptr);
}
