#include "so_long.h"

int	animation(t_game *game)
{
	if (game->frame == 4000)
	{
		game->data.current_wall_ptr = game->data.wall1_ptr;
		draw_map(game);
	}
	if (game->frame == 7000)
	{
		game->data.current_collectible_ptr = game->data.collectible2_ptr;
		draw_map(game);
	}
	if (game->frame > 10000)
	{
		game->data.current_wall_ptr = game->data.wall2_ptr;
		game->data.current_collectible_ptr = game->data.collectible1_ptr;
		draw_map(game);
		game->frame = 0;
	}
	game->frame++;
	usleep(50);
	return (0);
}
