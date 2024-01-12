/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:05:17 by mtayama           #+#    #+#             */
/*   Updated: 2024/01/12 20:05:18 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(t_game *game, char *filename)
{
	int			fd;
	char		**copy;
	char		*line;
	size_t		i;

	i = 0;
	copy = malloc(sizeof(char *) * game->height);
	if (copy == NULL)
		free_game(game, "Error\nMemory allocation failed: copy");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		free_game(game, "Error\nUnable to open file.");
	while (i < game->height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		copy[i] = line;
		i++;
	}
	close(fd);
	return (copy);
}

static void	path_check(t_game *game, t_pos pos, char **visited, bool *valid)
{
	size_t	height;
	size_t	width;

	height = game->height;
	width = game->width;
	if (*valid == true || pos.x < 0 || pos.y < 0 || pos.x >= width
		|| pos.y >= height || game->map[pos.y][pos.x] == '1'
		|| visited[pos.y][pos.x] == 'F')
		return ;
	if (pos.x == game->exit_x && pos.y == game->exit_y)
	{
		*valid = true;
		return ;
	}
	visited[pos.y][pos.x] = 'F';
	path_check(game, (t_pos){pos.x + 1, pos.y}, visited, valid);
	path_check(game, (t_pos){pos.x - 1, pos.y}, visited, valid);
	path_check(game, (t_pos){pos.x, pos.y + 1}, visited, valid);
	path_check(game, (t_pos){pos.x, pos.y - 1}, visited, valid);
}

static int	check_items(t_game *game, t_pos pos, char **visited,
	int *collectibles)
{
	if (pos.x >= 0 && pos.x < game->width && pos.y >= 0
		&& pos.y < game->height && visited[pos.y][pos.x] != 'F')
	{
		if (visited[pos.y][pos.x] == 'C')
			(*collectibles)--;
		else if (visited[pos.y][pos.x] == '1')
			return (*collectibles);
		visited[pos.y][pos.x] = 'F';
		*collectibles = check_items(game,
				(t_pos){pos.x + 1, pos.y}, visited, collectibles);
		*collectibles = check_items(game,
				(t_pos){pos.x - 1, pos.y}, visited, collectibles);
		*collectibles = check_items(game,
				(t_pos){pos.x, pos.y + 1}, visited, collectibles);
		*collectibles = check_items(game,
				(t_pos){pos.x, pos.y - 1}, visited, collectibles);
	}
	return (*collectibles);
}

static int	check_items_wrapper(t_game *game, t_pos pos, char *filename)
{
	static int		collectibles = -1;
	static char		**visited = NULL;
	size_t			i;
	int				first_call;
	int				result;

	i = 0;
	first_call = 0;
	if (collectibles == -1)
	{
		first_call = 1;
		collectibles = game->collectibles;
		visited = copy_map(game, filename);
	}
	result = check_items(game, pos, visited, &collectibles);
	if (first_call)
	{
		while (++i < game->height)
			free(visited[i]);
	}
	return (result);
}

void	valid_path_check(t_game *game, char *filename)
{
	bool		valid;
	size_t		i;
	char		**visited;
	t_pos		pos;

	valid = false;
	i = 0;
	visited = malloc(sizeof(char *) * game->height);
	if (visited == NULL)
		free_game(game, "Error\nMemory allocation failed: visited");
	while (i < game->height)
	{
		visited[i] = malloc(sizeof(char) * game->width);
		if (visited[i] == NULL)
			free_game(game, "Error\nMemory allocation failed: visited");
		i++;
	}
	pos.x = game->player_x;
	pos.y = game->player_y;
	path_check(game, pos, visited, &valid);
	if (valid == false)
		free_game(game, "Error\nNo valid path to the exit.");
	if (check_items_wrapper(game, pos, filename) != 0)
		free_game(game, "Error\nSome items are unreachable.");
	free_2d_array(visited, game->height);
}
