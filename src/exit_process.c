/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:05:20 by mtayama           #+#    #+#             */
/*   Updated: 2024/01/13 00:15:08 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	free_2d_map(t_game *game)
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

void	free_game(t_game *game, char *message)
{
	destroy_images(&game->data);
	destroy_images_nums(game);
	if (game->data.malloc_mlx_ptr == true && game->data.malloc_win_ptr == true)
		mlx_destroy_window(game->data.mlx_ptr, game->data.win_ptr);
	if (game->data.malloc_mlx_ptr == true)
		mlx_destroy_display(game->data.mlx_ptr);
	free_2d_map(game);
	exit_process(message);
}

void	exit_process(char *message)
{
	perror(message);
	exit(1);
}
