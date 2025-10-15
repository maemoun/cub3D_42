/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:29:24 by maeskhai          #+#    #+#             */
/*   Updated: 2025/09/25 13:21:00 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif


# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "./get_next_line/get_next_line.h"

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct	s_data
{
	char	**fd_lines;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f_color;
	char	*c_color;
	int	nb_no;
	int	nb_so;
	int nb_we;
	int nb_ea;
	int nb_f;
	int nb_c;
	t_color	f;
	t_color	c;
	char	**map;
	int	map_height;
	int	map_width;
}	t_data;


//------------//parsing :

void    ft_parsing(char *str, t_data *dt);
void	ft_check_file_name(char *s);
void	ft_print_error(char *s, char **map, char *line);
void	ft_free_map(char **map);
void	ft_read_fd(char *fd_in, t_data *dt);
char	**ft_split(char *s, char c);
void	ft_init_fd(t_data *dt);
char	*ft_get_texture(char *s);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_get_color(char *s);
void	ft_init_color(t_data *dt);
void	ft_check_fd(t_data *dt);
char	*ft_get_texture(char *s);
char	*ft_get_color(char *s);
void	ft_check_map_errors(t_data *dt);

//------------//utils :
char	*ft_strtrim(char *s1, char *set);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif