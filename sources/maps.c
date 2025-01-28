/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:47:26 by carmelag          #+#    #+#             */
/*   Updated: 2025/01/28 11:47:28 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int add_line_to_map(t_game *game, char *line)
{
    char    **new_map;
    int     i;

    i = 0;
    game->height++;
    new_map = (char*)malloc(sizeof(char) * (game->height + 1));
    new_map[game->height] = NULL; //el ultimo str del char** tiene que ser un NULL
    while(i < (game->height - 1)) //Hay que dejar espacio para la linea nueva
    {
        game->map[i] = new_map[i];
        i++;
    }
    new_map[i] = line; //se añade nueva linea
    if(game->map) //se libera el antiguo para copiar el nuevo (new_map no se libera porque lo necesitas para la siguiente llamada)
        free(game->map);
    game->map = new_map; //se actualiza game->map
    game->width = ft_strlen(game->map[0]); //Le doy el valor de la primera linea y luego ya compruebo
    return (1);
}

int read_map(t_game *game, char **argv)
{
    char    *line;
    int     i;

    i = 0;
    game->fd = open(argv[1], O_RDONLY);
    if(game->fd < 0)
        return(0);
    while(1)
    {
        line = get_next_line(game->fd);
        add_line_to_map(game->map, line);
        if(!add_line_to_map)
            break;
    }
    close(game->fd);
    return (1);
}
