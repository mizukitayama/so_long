#include "so_long.h"

void	destroy_images_nums(t_game *game)
{
	if (game->nums.malloc_zero_ptr == true)
		mlx_destroy_image(game->data.mlx_ptr, game->nums.zero_ptr);
	if (game->nums.malloc_one_ptr == true)
		mlx_destroy_image(game->data.mlx_ptr, game->nums.one_ptr);
	if (game->nums.malloc_two_ptr == true)
		mlx_destroy_image(game->data.mlx_ptr, game->nums.two_ptr);
	if (game->nums.malloc_three_ptr == true)
		mlx_destroy_image(game->data.mlx_ptr, game->nums.three_ptr);
	if (game->nums.malloc_four_ptr == true)
		mlx_destroy_image(game->data.mlx_ptr, game->nums.four_ptr);
	if (game->nums.malloc_five_ptr == true)
		mlx_destroy_image(game->data.mlx_ptr, game->nums.five_ptr);
	if (game->nums.malloc_six_ptr == true)
		mlx_destroy_image(game->data.mlx_ptr, game->nums.six_ptr);
	if (game->nums.malloc_seven_ptr == true)
		mlx_destroy_image(game->data.mlx_ptr, game->nums.seven_ptr);
	if (game->nums.malloc_eight_ptr == true)
		mlx_destroy_image(game->data.mlx_ptr, game->nums.eight_ptr);
	if (game->nums.malloc_nine_ptr == true)
		mlx_destroy_image(game->data.mlx_ptr, game->nums.nine_ptr);
}

void	destroy_images(t_data *data)
{
	if (data->malloc_player_ptr == true)
		mlx_destroy_image(data->mlx_ptr, data->player_ptr);
	if (data->malloc_exit_ptr == true)
		mlx_destroy_image(data->mlx_ptr, data->exit_ptr);
	if (data->malloc_wall1_ptr == true)
		mlx_destroy_image(data->mlx_ptr, data->wall1_ptr);
	if (data->malloc_wall2_ptr == true)
		mlx_destroy_image(data->mlx_ptr, data->wall2_ptr);
	if (data->malloc_collectible1_ptr == true)
		mlx_destroy_image(data->mlx_ptr, data->collectible1_ptr);
	if (data->malloc_collectible2_ptr == true)
		mlx_destroy_image(data->mlx_ptr, data->collectible2_ptr);
	if (data->malloc_empty_space_ptr == true)
		mlx_destroy_image(data->mlx_ptr, data->empty_space_ptr);
	if (data->malloc_enemy_ptr == true)
		mlx_destroy_image(data->mlx_ptr, data->enemy_ptr);
}
