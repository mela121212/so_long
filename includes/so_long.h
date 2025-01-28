/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:45:41 by carmelag          #+#    #+#             */
/*   Updated: 2025/01/28 11:45:50 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <fcntl.h>
#include "mlx.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "get_next_line.h"
#include <stdlib.h>


typedef struct t_game
{
    int     fd;
    int     width;
    int     height;
    int     y;                          // Posición Y del jugador
    int     x;                          // Posición X del jugador
    int     count_collectables;         // Contador de coleccionables
    int     step;                       // Contador de pasos
    int     finish;                     // Indicador de si el juego ha terminado

    char    **map;
    void	*mlxpointer;
	void	*winpointer;
    void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
}                t_game; 

void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
void	ft_exit(t_game *game, char *error_msg);
void    free_map(char **map, int height);
int     is_map_rectangular(t_complete *game);
int     is_map_enclosed(t_complete *game);
int     count_elements(t_game *game, char element);
int     validate_map_elements(t_game *game);
int     check_map(t_game *game);
void    check_path(t_game game);
void	move_player(t_game *game, int y_offset, int x_offset);
int	    press_key(int keycode, t_game *game);
void    load_images(t_complete *game);
void    place_image(t_complete *game, char element, int height, int width);
void    render_game(t_complete *game);
int     read_map(t_game *game, char **argv);
int     main(int argc, char **argv);
