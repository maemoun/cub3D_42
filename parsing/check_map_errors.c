/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:29:26 by maeskhai          #+#    #+#             */
/*   Updated: 2025/09/21 12:29:27 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map_sides(t_data *dt)
{
	int	i;

	i = 0;
	while (dt->map[0][i])
	{
		if (dt->map[0][i] != '1')
			ft_print_error("Error\nInvalid Map Sides!\n", dt->map, NULL);
		i++;
	}
	i = 0;
	while (dt->map[dt->map_height - 1][i])
	{
		if (dt->map[dt->map_height - 1][i] != '1')
			ft_print_error("Error\nInvalid Map Sides!\n", dt->map, NULL);
		i++;
	}
	i = 1;
	while (i < dt->map_height - 1)
	{
		if (dt->map[i][0] != '1'
			|| dt->map[i][dt->map_width - 1] != '1')
			ft_print_error("Error\nInvalid Map Sides!\n", dt->map, NULL);
		i++;
	}
}

void	ft_check_map_errors(t_data *dt)
{
	if (!dt->map)
		ft_print_error("Error\nMap not initialized!\n", NULL, NULL);
	if (dt->map_width <= 0 || dt->map_height <= 0)
		ft_print_error("Error\nInvalid map dimensions!\n", NULL, NULL);
	ft_map_sides(dt);
}
