/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 01:07:24 by maeskhai          #+#    #+#             */
/*   Updated: 2025/09/25 13:23:03 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_var_dt(t_data *dt)
{
	dt->nb_no = 0;
	dt->nb_ea = 0;
	dt->nb_so = 0;
	dt->nb_we = 0;
	dt->nb_f = 0;
	dt->nb_c = 0;
}

void	ft_init_vars(t_data *dt)
{
	int i;

	i = 0;
	while (dt->fd_lines[i])
	{
		if (ft_strncmp(dt->fd_lines[i], "NO ", 3) == 0)
		{
			if (dt->nb_no == 0)
				dt->no = ft_get_texture(dt->fd_lines[i] + 3);
			dt->nb_no++;
		}
		if (ft_strncmp(dt->fd_lines[i], "SO ", 3) == 0)
		{
			if (dt->nb_so == 0)
				dt->so = ft_get_texture(dt->fd_lines[i] + 3);
			dt->nb_so++;
		}
		if (ft_strncmp(dt->fd_lines[i], "WE ", 3) == 0)
		{
			if (dt->nb_we == 0)
				dt->we = ft_get_texture(dt->fd_lines[i] + 3);
			dt->nb_we++;
		}
		if (ft_strncmp(dt->fd_lines[i], "EA ", 3) == 0)
		{
			if (dt->nb_ea == 0)
				dt->ea = ft_get_texture(dt->fd_lines[i] + 3);
			dt->nb_ea++;
		}
		i++;
	}
	if (dt->nb_no != 1 || dt->nb_so != 1 || dt->nb_we != 1 || dt->nb_ea != 1)
		ft_print_error("Error\nInvalid Texture Info!\n", NULL, NULL);
}

void	ft_init_color(t_data *dt)
{
	int i;

	i = 0;
	while (dt->fd_lines[i])
	{
		if (ft_strncmp(dt->fd_lines[i], "F ", 2) == 0)
		{
			if (dt->nb_f == 0)
				dt->f_color = ft_get_color(dt->fd_lines[i] + 2);
			dt->nb_f++;
		}
		if (ft_strncmp(dt->fd_lines[i], "C ", 2) == 0)
		{
			if (dt->nb_c == 0)
				dt->c_color = ft_get_color(dt->fd_lines[i] + 2);
			dt->nb_c++;
		}
		i++;
	}
	if (dt->nb_f != 1 || dt->nb_c != 1)
		ft_print_error("Error\nInvalid args!\n", NULL, NULL);
}

void	ft_extract_color(t_data *dt)
{
	char	**arr;
	
	arr = ft_split(dt->f_color, ',');
	if (!arr[0] || !arr[1] || !arr[2] || arr[3])
		ft_print_error("Error\nInvalid F_color Info!\n", NULL, NULL);
	dt->f.r = atoi(arr[0]);
	dt->f.g = atoi(arr[1]);
	dt->f.b = atoi(arr[2]);
	ft_free_map(arr);
	arr = ft_split(dt->c_color, ',');
	if (!arr[0] || !arr[1] || !arr[2] || arr[3])
		ft_print_error("Error\nInvalid C_color Info!\n", NULL, NULL);
	dt->c.r = atoi(arr[0]);
	dt->c.g = atoi(arr[1]);
	dt->c.b = atoi(arr[2]);
	ft_free_map(arr);
	if ((dt->c.r < 0 || dt->c.r > 255) || (dt->c.g < 0 || dt->c.g > 255)
		|| (dt->c.b < 0 || dt->c.b > 255) || (dt->f.r < 0 || dt->f.r > 255)
		|| (dt->f.g < 0 || dt->f.g > 255) || (dt->f.b < 0 || dt->f.b > 255))
		ft_print_error("Error\nInvalid Color Info <0-255>!\n", NULL, NULL);
}

void	ft_init_map(t_data *dt)
{
	int i;
	int j;
	int max;

	i = 0;
	while (dt->fd_lines[i] && (ft_strncmp(dt->fd_lines[i], "NO ", 3) == 0
			|| ft_strncmp(dt->fd_lines[i], "SO ", 3) == 0
			|| ft_strncmp(dt->fd_lines[i], "WE ", 3) == 0
			|| ft_strncmp(dt->fd_lines[i], "EA ", 3) == 0
			|| ft_strncmp(dt->fd_lines[i], "F ", 2) == 0
			|| ft_strncmp(dt->fd_lines[i], "C ", 2) == 0))
		i++;
	dt->map_height = 0;
	j = i;
	max = 0;
	while (dt->fd_lines[j])
	{
		if (ft_strlen(dt->fd_lines[j]) > max)
			max = ft_strlen(dt->fd_lines[j]);
		dt->map_height++;
		j++;
	}
	dt->map_width = max;
	dt->map = malloc(sizeof(char *) * (dt->map_height + 1));
	if (!dt->map)
		ft_print_error("Error\nMalloc failed!\n", NULL, NULL);
	j = 0;
	while (j < dt->map_height)
	{
		dt->map[j] = malloc(sizeof(char) * (dt->map_width + 1));
		if (!dt->map[j])
			ft_print_error("Error\nMalloc failed!\n", NULL, NULL);
		ft_memset(dt->map[j], ' ', dt->map_width);
		dt->map[j][dt->map_width] = '\0';
		ft_memcpy(dt->map[j], dt->fd_lines[i + j], ft_strlen(dt->fd_lines[i + j]));
		j++;
	}
	dt->map[j] = NULL;
	i = 0;
	while (dt->map[i])
	{
		printf("|%s|\n", dt->map[i]);
		i++;
	}
}

void	ft_init_fd(t_data *dt)
{
	init_var_dt(dt);
	ft_init_vars(dt);
	ft_init_color(dt);
	ft_extract_color(dt);
	ft_init_map(dt);
}