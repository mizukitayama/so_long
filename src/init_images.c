#include "so_long.h"

static void	init_images_3(t_game *game)
{
	int	width;
	int	height;

	width = 50;
	height = 50;
	game->data.wall2_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			WALL_IMAGE2, &width, &height);
	if (game->data.wall2_ptr == NULL)
		free_game(game, "Error\nFailed to create image of ocean.");
	game->data.malloc_wall2_ptr = true;
	game->data.collectible2_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			COLLECTIBLE_IMAGE2, &width, &height);
	if (game->data.collectible2_ptr == NULL)
		free_game(game, "Error\nFailed to create image of collectible.");
	game->data.malloc_collectible2_ptr = true;
	game->data.enemy_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			ENEMY_IMAGE, &width, &height);
	if (game->data.enemy_ptr == NULL)
		free_game(game, "Error\nFailed to create image of enemy.");
	game->data.malloc_enemy_ptr = true;
}

static void	init_images_2(t_game *game)
{
	int	width;
	int	height;

	width = 50;
	height = 50;
	game->data.wall1_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			WALL_IMAGE1, &width, &height);
	if (game->data.wall1_ptr == NULL)
		free_game(game, "Error\nFailed to create image of ocean.");
	game->data.malloc_wall1_ptr = true;
	game->data.collectible1_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			COLLECTIBLE_IMAGE1, &width, &height);
	if (game->data.collectible1_ptr == NULL)
		free_game(game, "Error\nFailed to create image of collectible.");
	game->data.malloc_collectible1_ptr = true;
	game->data.empty_space_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			EMPTY_SPACE_IMAGE, &width, &height);
	if (game->data.empty_space_ptr == NULL)
		free_game(game, "Error\nFailed to create image of empty space.");
	game->data.malloc_empty_space_ptr = true;
}

void	init_images(t_game *game)
{
	int	width;
	int	height;

	width = 50;
	height = 50;
	game->data.player_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			PLAYER_IMAGE, &width, &height);
	if (game->data.player_ptr == NULL)
		free_game(game, "Error\nFailed to create image of bear.");
	game->data.malloc_player_ptr = true;
	game->data.exit_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			EXIT_IMAGE, &width, &height);
	if (game->data.exit_ptr == NULL)
		free_game(game, "Error\nFailed to create image of exit.");
	game->data.malloc_exit_ptr = true;
	init_images_2(game);
	init_images_3(game);
	init_images_nums(game, width, height);
}
