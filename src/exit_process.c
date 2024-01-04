#include "so_long.h"

void	free_2d_array(char **strs, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static void	destroy_images(t_data *data)
{
	if (data->player_ptr != NULL)
		mlx_destroy_image(data->mlx_ptr, data->player_ptr);
	if (data->exit_ptr != NULL)
		mlx_destroy_image(data->mlx_ptr, data->exit_ptr);
	if (data->wall_ptr != NULL)
		mlx_destroy_image(data->mlx_ptr, data->wall_ptr);
	if (data->collectible_ptr != NULL)
		mlx_destroy_image(data->mlx_ptr, data->collectible_ptr);
	if (data->empty_space_ptr != NULL)
		mlx_destroy_image(data->mlx_ptr, data->empty_space_ptr);
}

void	exit_game(t_game *game, char *message)
{
	perror(message);
	if (game->data != NULL)
	{
		destroy_images(game->data);
		if (game->data->mlx_ptr != NULL && game->data->win_ptr != NULL)
			mlx_destroy_window(game->data->mlx_ptr, game->data->win_ptr);
		if (game->data->mlx_ptr != NULL)
			mlx_destroy_display(game->data->mlx_ptr);
		free(game->data->mlx_ptr);
	}
	if (game != NULL)
	{
		if (game->map != NULL)
			free_2d_array(game->map, game->height);
		if (game->data != NULL)
			free(game->data);
		free(game);
	}
	exit(1);
}
