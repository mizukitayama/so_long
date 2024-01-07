#include "so_long.h"

void free_2d_array(char **strs, size_t height)
{
	size_t i;

	i = 0;
	while (i < height)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void free_2d_map(t_game *game)
{
	size_t	i;

	i = 0;
	if (game->malloc_map)
	{
		while (i < game->height)
		{
			if (game->map[i] != NULL)
			{
				free(game->map[i]);
				i++;
			}
		}
		free(game->map);
	}
}

static void destroy_images(t_data *data)
{
	if (data->malloc_player_ptr == true)
		mlx_destroy_image(data->mlx_ptr, data->player_ptr);
	if (data->malloc_exit_ptr == true)
		mlx_destroy_image(data->mlx_ptr, data->exit_ptr);
	if (data->malloc_wall_ptr == true)
		mlx_destroy_image(data->mlx_ptr, data->wall_ptr);
	if (data->malloc_collectible_ptr == true)
		mlx_destroy_image(data->mlx_ptr, data->collectible_ptr);
	if (data->malloc_empty_space_ptr == true)
		mlx_destroy_image(data->mlx_ptr, data->empty_space_ptr);
}

void	free_game(t_game *game, char *message)
{
	destroy_images(&game->data);
	// if (game->data.mlx_ptr != NULL && game->data.win_ptr != NULL)
	// 	mlx_destroy_window(game->data.mlx_ptr, game->data.win_ptr);
	// if (game->data.mlx_ptr != NULL)
	// 	mlx_destroy_display(game->data.mlx_ptr);
	// free(game->data.mlx_ptr);
	free_2d_map(game);
	exit_process(message);
}

void	exit_process(char *message)
{
	perror(message);
	exit(1);
}
