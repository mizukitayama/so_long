#include "so_long.h"

static size_t	get_game_height(char *filename, t_game *game)
{
	size_t		height;
	char		*line;
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		free_game(game, "Error\nUnable to open file");
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		height++;
	}
	close(fd);
	return (height);
}

static void	check_char(size_t y, t_game *game)
{
	char		c;
	size_t		x;

	x = 0;
	while (x < game->width)
	{
		c = game->map[y][x];
		if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
			free_game(game, "Error\nInvalid character detected.");
		else if (((y == 0 || y == game->height - 1) && c != '1')
			|| ((x == 0 || x == game->width - 1) && c != '1'))
			free_game(game, "Error\nMap not surrounded by walls.");
		x++;
	}
}

static void	check_content(t_game *game)
{
	size_t	y;
	size_t	map_exit;
	size_t	player;

	y = 0;
	map_exit = 0;
	player = 0;
	game->collectibles = 0;
	while (y < game->height)
	{
		if (strlen_ignore_new_line(game->map[y]) != game->width)
			free_game(game, "Error\nThe map is not rectangular.");
		check_char(y, game);
		map_exit += count_c(game->map[y], 'E');
		player += count_c(game->map[y], 'P');
		game->collectibles += count_c(game->map[y], 'C');
		y++;
	}
	if (map_exit != 1)
		free_game(game, "Error\nInvalid number of exit.");
	if (player != 1)
		free_game(game, "Error\nInvalid number of player.");
	if (game->collectibles < 1)
		free_game(game, "Error\nAt least one collectible required.");
}

void	parse_input(char **argv, t_game *game)
{
	char	*line;
	int		fd;
	size_t	i;

	i = 0;
	game->height = get_game_height(argv[1], game);
	game->map = ft_calloc(sizeof(char *), game->height);
	if (game->map == NULL)
		exit_process("Error\nMemory allocation failed: game->map");
	game->malloc_map = true;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		free_game(game, "Error\nUnable to open file.");
	while (i < game->height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			free_game(game, "Error\nError whlie reading file.");
		game->map[i] = line;
		i++;
	}
	close(fd);
	game->width = strlen_ignore_new_line(game->map[0]);
	check_content(game);
}
