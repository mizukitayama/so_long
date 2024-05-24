/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:05:34 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/24 19:29:27 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_valid_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	if (filename[len - 4] == '.' && filename[len - 3] == 'b'
		&& filename[len - 2] == 'e' && filename[len - 1] == 'r')
		return (true);
	return (false);
}

static void	get_position(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			else if (game->map[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_cpy;

	i = 0;
	s_cpy = (unsigned char *)str;
	while (i < n)
	{
		*s_cpy = (unsigned char)c;
		s_cpy++;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	srand((unsigned int)time(NULL));
	if (argc != 2 || !is_valid_extension(argv[1]))
		exit_process("Error\nFile name is not valid.");
	game.data.mlx_ptr = mlx_init();
	if (game.data.mlx_ptr == NULL)
		return (0);
	game.data.malloc_mlx_ptr = true;
	parse_input(argv, &game);
	get_position(&game);
	valid_path_check(&game, argv[1]);
	place_enemy(&game);
	game.moves = 0;
	display_window(&game);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q so_long");
// }