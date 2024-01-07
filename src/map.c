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

static int	deal_key(int key, t_game *game)
{
	static size_t	moves = 0;
	static size_t	collectibles = 0;

	if (moves == 0)
		collectibles = game->collectibles;
	if (key == 13 || key == 126 || key == 119 || key == 65362)
		moves += move_up(game, moves, &collectibles);
	else if (key == 1 || key == 125 || key == 115 || key == 65364)
		moves += move_down(game, moves, &collectibles);
	else if (key == 0 || key == 123 || key == 97 || key == 65361)
		moves += move_left(game, moves, &collectibles);
	else if (key == 2 || key == 124 || key == 100 || key == 65363)
		moves += move_right(game, moves, &collectibles);
	else if (key == 53 || key == 65307)
		free_game(game, "Exiting prgram.");
	if (!(game->exit_x == game->player_x && game->exit_y == game->player_y))
		game->map[game->exit_y][game->exit_x] = 'E';
	draw_map(game);
	return (0);
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

void	display_window(t_game *game)
{
	game->data.win_ptr = mlx_new_window(game->data.mlx_ptr,
			50 * game->width, 50 * game->height, "so_long");
	if (game->data.win_ptr == NULL)
		free_game(game, "Error\nmlx_new_window() failed.");
	init_images(game);
	draw_map(game);
	mlx_key_hook(game->data.win_ptr, deal_key, game);
	mlx_loop(game->data.mlx_ptr);
}
