/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:48:18 by carmelag          #+#    #+#             */
/*   Updated: 2025/01/28 11:48:21 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_images(t_complete *game)
{
    int i, j;

    game->floor = mlx_xpm_file_to_image(game->mlxpointer, "game_images/floor.xpm", &i, &j);
    game->barrier = mlx_xpm_file_to_image(game->mlxpointer, "game_images/wall.xpm", &i, &j);
    game->player = mlx_xpm_file_to_image(game->mlxpointer, "game_images/player.xpm", &i, &j);
    game->exit = mlx_xpm_file_to_image(game->mlxpointer, "game_images/exit.xpm", &i, &j);
    game->collectable = mlx_xpm_file_to_image(game->mlxpointer, "game_images/collectable.xpm", &i, &j);
}

void place_image(t_complete *game, char element, int height, int width)
{
    void *image = NULL;

    if (element == '1')
        image = game->barrier;
    else if (element == 'C')
        image = game->collectable;
    else if (element == 'P')
        image = game->player;
    else if (element == 'E')
        image = game->exit;
    else if (element == '0')
        image = game->floor;
    if (image != NULL)
        mlx_put_image_to_window(game->mlxpointer, game->winpointer, image, width * 40, height * 40);
}

void render_game(t_complete *game)
{
    int height = 0;
    int width;

    game->collectables = 0;  // Reinicia el contador de coleccionables
    while (height < game->heightmap)
    {
        width = 0;
        while (game->map[height][width])
        {
            // Llama a place_image para cada elemento del mapa
            place_image(game, game->map[height][width], height, width);
            if (game->map[height][width] == 'C')
                game->collectables++;  // Incrementa el número de coleccionables
            width++;
        }
        height++;
    }
}

