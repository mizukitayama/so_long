/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:23:34 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/24 19:23:35 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_images_nums_3(t_game *game, int width, int height)
{
	game->nums.zero_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/0.xpm", &width, &height);
	if (game->nums.zero_ptr == NULL)
		free_game(game, "Error\nFailed to create image of 0.");
}

static void	init_images_nums_2(t_game *game, int width, int height)
{
	game->nums.six_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/6.xpm", &width, &height);
	if (game->nums.six_ptr == NULL)
		free_game(game, "Error\nFailed to create image of 6.");
	game->nums.malloc_six_ptr = true;
	game->nums.seven_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/7.xpm", &width, &height);
	if (game->nums.seven_ptr == NULL)
		free_game(game, "Error\nFailed to create image of 7.");
	game->nums.malloc_seven_ptr = true;
	game->nums.eight_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/8.xpm", &width, &height);
	if (game->nums.eight_ptr == NULL)
		free_game(game, "Error\nFailed to create image of 8.");
	game->nums.malloc_eight_ptr = true;
	game->nums.nine_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/9.xpm", &width, &height);
	if (game->nums.nine_ptr == NULL)
		free_game(game, "Error\nFailed to create image of 9.");
	game->nums.malloc_nine_ptr = true;
}

void	init_images_nums(t_game *game, int width, int height)
{
	game->nums.one_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/1.xpm", &width, &height);
	if (game->nums.one_ptr == NULL)
		free_game(game, "Error\nFailed to create image of 1.");
	game->nums.malloc_one_ptr = true;
	game->nums.two_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/2.xpm", &width, &height);
	if (game->nums.two_ptr == NULL)
		free_game(game, "Error\nFailed to create image of 2.");
	game->nums.malloc_two_ptr = true;
	game->nums.three_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/3.xpm", &width, &height);
	if (game->nums.three_ptr == NULL)
		free_game(game, "Error\nFailed to create image of 3.");
	game->nums.malloc_three_ptr = true;
	game->nums.four_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/4.xpm", &width, &height);
	if (game->nums.four_ptr == NULL)
		free_game(game, "Error\nFailed to create image of 4.");
	game->nums.malloc_four_ptr = true;
	game->nums.five_ptr = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/5.xpm", &width, &height);
	game->nums.malloc_five_ptr = true;
	init_images_nums_2(game, width, height);
	init_images_nums_3(game, width, height);
}
