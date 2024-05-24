/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:05:36 by mtayama           #+#    #+#             */
/*   Updated: 2024/01/13 00:12:26 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../get_next_line/get_next_line.h"
# include "../printf/inc/ft_printf.h"

# define WALL_IMAGE1 "assets/ocean1.xpm"
# define WALL_IMAGE2 "assets/ocean2.xpm"
# define COLLECTIBLE_IMAGE1 "assets/fish1.xpm"
# define COLLECTIBLE_IMAGE2 "assets/fish2.xpm"
# define EMPTY_SPACE_IMAGE "assets/ice.xpm"
# define PLAYER_IMAGE "assets/bear.xpm"
# define EXIT_IMAGE "assets/igloo.xpm"
# define ENEMY_IMAGE "assets/inuit.xpm"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player_ptr;
	void	*exit_ptr;
	void	*current_wall_ptr;
	void	*wall1_ptr;
	void	*wall2_ptr;
	void	*current_collectible_ptr;
	void	*collectible1_ptr;
	void	*collectible2_ptr;
	void	*empty_space_ptr;
	void	*enemy_ptr;
	bool	malloc_mlx_ptr;
	bool	malloc_win_ptr;
	bool	malloc_player_ptr;
	bool	malloc_exit_ptr;
	bool	malloc_wall1_ptr;
	bool	malloc_wall2_ptr;
	bool	malloc_collectible1_ptr;
	bool	malloc_collectible2_ptr;
	bool	malloc_empty_space_ptr;
	bool	malloc_enemy_ptr;
}	t_data;

typedef struct s_nums
{
	void	*zero_ptr;
	void	*one_ptr;
	void	*two_ptr;
	void	*three_ptr;
	void	*four_ptr;
	void	*five_ptr;
	void	*six_ptr;
	void	*seven_ptr;
	void	*eight_ptr;
	void	*nine_ptr;
	bool	malloc_zero_ptr;
	bool	malloc_one_ptr;
	bool	malloc_two_ptr;
	bool	malloc_three_ptr;
	bool	malloc_four_ptr;
	bool	malloc_five_ptr;
	bool	malloc_six_ptr;
	bool	malloc_seven_ptr;
	bool	malloc_eight_ptr;
	bool	malloc_nine_ptr;
} t_nums;

typedef struct s_game
{
	t_data		data;
	t_nums		nums;
	char		**map;
	bool		malloc_map;
	size_t		height;
	size_t		width;
	size_t		collectibles;
	size_t		player_x;
	size_t		player_y;
	size_t		exit_x;
	size_t		exit_y;
	size_t		enemy_x;
	size_t		enemy_y;
	size_t		frame;
	size_t		moves;
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
size_t	move_up(t_game *game, size_t *collectibles);
size_t	move_down(t_game *game, size_t *collectibles);
size_t	move_left(t_game *game, size_t *collectibles);
size_t	move_right(t_game *game, size_t *collectibles);
void	parse_input(char **argv, t_game *game);
size_t	count_c(char *str, char ch);
size_t	strlen_ignore_new_line(char *str);
void	draw_map(t_game *game);
void	exit_process(char *message);
void	*ft_calloc(size_t number, size_t size);
int		deal_key(int key, t_game *game);
int		exit_hook(void *game);
int		expose_hook_func(void *game);
int		animation(t_game *game);
void	init_images(t_game *game);
void	place_enemy(t_game *game);
void	move_enemy(t_game *game);
void	init_images_nums(t_game *game, int width, int height);
void	print_moves(t_game *game, size_t moves);

#endif
