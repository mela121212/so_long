#include "so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *p;

	p = (char *)b;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (b);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while ((s[i] != '\0') || (s[i] != '\n'))
		i++;
	return (i);
}

void	ft_exit(t_game *game, char *error_msg)
{
	destroy(game);
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void free_map(char **map, int height)
{
    int y = 0;

    while (y < height)
    {
        free(map[y]);
        y++;
    }
    free(map);
}