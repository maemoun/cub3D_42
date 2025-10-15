/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:07:16 by maeskhai          #+#    #+#             */
/*   Updated: 2025/09/25 12:44:35 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_parsing(char *fd_in, t_data *dt)
{
    int i = 0;
	ft_check_file_name(fd_in);
	ft_read_fd(fd_in, dt);
    ft_init_fd(dt);
	ft_check_map_errors(dt);
    // if (!dt->fd_lines)
    //     ft_print_error("Error\nMap reading failed!\n", NULL, NULL);
    // while (dt->fd_lines[i])
    // {
    //     printf("%s\n", dt->fd_lines[i]);
    //     i++;
    // }
}
