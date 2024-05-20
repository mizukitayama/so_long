#include "so_long.h"

int	animation(t_game *game)
{
	if (game->frame == 40000)
	{
		game->data.current_wall_ptr = game->data.wall1_ptr;
		draw_map(game);
	}
	if (game->frame == 70000)
	{
		game->data.current_collectible_ptr = game->data.collectible2_ptr;
		draw_map(game);
	}
	if (game->frame > 100000)
	{
		game->data.current_wall_ptr = game->data.wall2_ptr;
		game->data.current_collectible_ptr = game->data.collectible1_ptr;
		draw_map(game);
		game->frame = 0;
	}
	game->frame++;
	return (0);
}
