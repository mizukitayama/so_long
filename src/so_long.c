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

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2 || !is_valid_extension(argv[1]))
	{
		perror("Error\nFile name is not valid.");
		return (0);
	}
	game = malloc(sizeof(t_game));
	if (game == NULL)
	{
		perror("Error\nMemory allocation failed: game");
		return (0);
	}
	game->data = malloc(sizeof(t_data));
	if (game->data == NULL)
		exit_game(game, "Error\nMemory allocation failed: game->data");
	game->data->mlx_ptr = mlx_init();
	if (game->data->mlx_ptr == NULL)
		exit_game(game, "error\nmlx_init() failed.");
	parse_input(argv, game);
	get_position(game);
	valid_path_check(game, argv[1]);
	display_window(game);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q so_long");
// }
