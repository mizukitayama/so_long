#include "so_long.h"

static bool	is_valid_move(char **map, size_t x, size_t y)
{
	if (map[y][x] == '1')
		return (false);
	return (true);
}

size_t	move_up(t_game *game, size_t moves, size_t *collectibles)
{
	if (!is_valid_move(game->map, game->player_x, game->player_y - 1))
		return (0);
	ft_printf("moves: %u\n", moves + 1);
	if (game->map[game->player_y - 1][game->player_x] == 'E'
			&& *collectibles == 0)
	{
		ft_printf("You've completed the game in %u moves.\n", moves + 1);
		free_game(game, "");
	}
	if (game->map[game->player_y - 1][game->player_x] == 'C')
		(*collectibles)--;
	game->map[game->player_y][game->player_x] = '0';
	game->player_y--;
	game->map[game->player_y][game->player_x] = 'P';
	return (1);
}

size_t	move_down(t_game *game, size_t moves, size_t *collectibles)
{
	if (!is_valid_move(game->map, game->player_x, game->player_y + 1))
		return (0);
	ft_printf("moves: %u\n", moves + 1);
	if (game->map[game->player_y + 1][game->player_x] == 'E'
			&& *collectibles == 0)
	{
		ft_printf("You've completed the game in %u moves.\n", moves + 1);
		free_game(game, "");
	}
	if (game->map[game->player_y + 1][game->player_x] == 'C')
		(*collectibles)--;
	game->map[game->player_y][game->player_x] = '0';
	game->player_y++;
	game->map[game->player_y][game->player_x] = 'P';
	return (1);
}

size_t	move_left(t_game *game, size_t moves, size_t *collectibles)
{
	if (!is_valid_move(game->map, game->player_x - 1, game->player_y))
		return (0);
	ft_printf("moves: %u\n", moves + 1);
	if (game->map[game->player_y][game->player_x - 1] == 'E'
			&& *collectibles == 0)
	{
		ft_printf("You've completed the game in %u moves.\n", moves + 1);
		free_game(game, "");
	}
	if (game->map[game->player_y][game->player_x - 1] == 'C')
		(*collectibles)--;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x--;
	game->map[game->player_y][game->player_x] = 'P';
	return (1);
}

size_t	move_right(t_game *game, size_t moves, size_t *collectibles)
{
	if (is_valid_move(game->map, game->player_x + 1, game->player_y) == false)
		return (0);
	ft_printf("moves: %u\n", moves + 1);
	if (game->map[game->player_y][game->player_x + 1] == 'E'
			&& *collectibles == 0)
	{
		ft_printf("You've completed the game in %u moves.\n", moves + 1);
		free_game(game, "");
	}
	if (game->map[game->player_y][game->player_x + 1] == 'C')
		(*collectibles)--;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x++;
	game->map[game->player_y][game->player_x] = 'P';
	return (1);
}
