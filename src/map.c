/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:04:07 by mtayama           #+#    #+#             */
/*   Updated: 2024/01/12 20:05:26 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_images(t_game *game)
{
	int	width;
	int	height;

	width = 50;
	height = 50;
	game->data.player_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/bear.xpm", &width, &height);
	if (game->data.player_ptr == NULL)
		free_game(game, "Error\nFailed to create image of bear.");
	game->data.malloc_player_ptr = true;
	game->data.exit_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/igloo.xpm", &width, &height);
	if (game->data.exit_ptr == NULL)
		free_game(game, "Error\nFailed to create image of exit.");
	game->data.malloc_exit_ptr = true;
	game->data.wall_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/ocean.xpm", &width, &height);
	if (game->data.wall_ptr == NULL)
		free_game(game, "Error\nFailed to create image of ocean.");
	game->data.malloc_wall_ptr = true;
	game->data.collectible_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/fish.xpm", &width, &height);
	if (game->data.collectible_ptr == NULL)
		free_game(game, "Error\nFailed to create image of collectible.");
	game->data.malloc_collectible_ptr = true;
	game->data.empty_space_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/ice.xpm", &width, &height);
	if (game->data.empty_space_ptr == NULL)
		free_game(game, "Error\nFailed to create image of empty space.");
	game->data.malloc_empty_space_ptr = true;
}

static void	draw_image(char c, size_t x, size_t y, t_data *data)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall_ptr, 50 * x, 50 * y);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->empty_space_ptr, 50 * x, 50 * y);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->collectible_ptr, 50 * x, 50 * y);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit_ptr, 50 * x, 50 * y);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_ptr, 50 * x, 50 * y);
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
}

static int	expose_hook_func(void *game)
{
	draw_map(game);
	return (0);
}

void	display_window(t_game *game)
{
	game->data.win_ptr = mlx_new_window(game->data.mlx_ptr,
			50 * game->width, 50 * game->height, "so_long");
	if (game->data.win_ptr == NULL)
		free_game(game, "Error\nmlx_new_window() failed.");
	game->data.malloc_win_ptr = true;
	init_images(game);
	draw_map(game);
	mlx_key_hook(game->data.win_ptr, deal_key, game);
	mlx_hook(game->data.win_ptr, 17, 1L << 0, exit_hook, game);
	mlx_expose_hook(game->data.win_ptr, expose_hook_func, game);
	mlx_loop(game->data.mlx_ptr);
}
