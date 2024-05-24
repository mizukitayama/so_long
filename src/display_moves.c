/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:23:25 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/24 19:23:26 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_nums_2(t_game *game, size_t display, size_t width)
{
	if (display == 5)
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->nums.five_ptr, width, 50 * game->height);
	else if (display == 6)
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->nums.six_ptr, width, 50 * game->height);
	else if (display == 7)
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->nums.seven_ptr, width, 50 * game->height);
	else if (display == 8)
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->nums.eight_ptr, width, 50 * game->height);
	else if (display == 9)
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->nums.nine_ptr, width, 50 * game->height);
}

static void	display_nums(t_game *game, size_t display, size_t width)
{
	if (display == 0)
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->nums.zero_ptr, width, 50 * game->height);
	else if (display == 1)
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->nums.one_ptr, width, 50 * game->height);
	else if (display == 2)
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->nums.two_ptr, width, 50 * game->height);
	else if (display == 3)
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->nums.three_ptr, width, 50 * game->height);
	else if (display == 4)
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->nums.four_ptr, width, 50 * game->height);
	display_nums_2(game, display, width);
}

void	print_moves(t_game *game, size_t moves)
{
	size_t	display;
	size_t	count;

	count = 0;
	while (moves > 0)
	{
		count ++;
		if (moves >= 10)
		{
			display = moves % 10;
			moves /= 10;
		}
		else
		{
			display = moves;
			moves = 0;
		}
		display_nums(game, display, (game->width - 1) * 50 - count * 32);
	}
}
