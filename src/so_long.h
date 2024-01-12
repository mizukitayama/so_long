/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:05:36 by mtayama           #+#    #+#             */
/*   Updated: 2024/01/12 22:59:45 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../get_next_line/get_next_line.h"
# include "../printf/inc/ft_printf.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player_ptr;
	void	*exit_ptr;
	void	*wall_ptr;
	void	*collectible_ptr;
	void	*empty_space_ptr;
	bool	malloc_mlx_ptr;
	bool	malloc_win_ptr;
	bool	malloc_player_ptr;
	bool	malloc_exit_ptr;
	bool	malloc_wall_ptr;
	bool	malloc_collectible_ptr;
	bool	malloc_empty_space_ptr;
}	t_data;

typedef struct s_game
{
	char		**map;
	bool		malloc_map;
	size_t		height;
	size_t		width;
	size_t		collectibles;
	t_data		data;
	size_t		player_x;
	size_t		player_y;
	size_t		exit_x;
	size_t		exit_y;
}	t_game;

typedef struct s_position
{
	size_t	x;
	size_t	y;
}	t_pos;

void	valid_path_check(t_game *game, char *filename);
void	free_2d_array(char **strs, size_t height);
void	free_game(t_game *game, char *message);
void	display_window(t_game *game);
size_t	move_up(t_game *game, size_t moves, size_t *collectibles);
size_t	move_down(t_game *game, size_t moves, size_t *collectibles);
size_t	move_left(t_game *game, size_t moves, size_t *collectibles);
size_t	move_right(t_game *game, size_t moves, size_t *collectibles);
void	parse_input(char **argv, t_game *game);
size_t	count_c(char *str, char ch);
size_t	strlen_ignore_new_line(char *str);
void	draw_map(t_game *game);
void	exit_process(char *message);
void	*ft_calloc(size_t number, size_t size);
int		deal_key(int key, t_game *game);
int		exit_hook(void *game);
int		expose_hook_func(void *game);

#	endif
