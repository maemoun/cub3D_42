/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:29:32 by maeskhai          #+#    #+#             */
/*   Updated: 2025/09/25 01:25:43 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_read_fd(char *fd_in, t_data *dt)
{
	int		fd;
	char	*line;
	char	*line_join;
	char	*tmp;

	fd = open(fd_in, O_RDONLY);
	if (fd < 0)
		ft_print_error("Eroor\nCan't Open File fd_in!\n", NULL, NULL);
	line = get_next_line(fd);
	if (!line)
		ft_print_error("Error\nEmpty file / Nothing..!\n", NULL, NULL);
	line_join = ft_strdup("");
	while (line)
	{
		tmp = ft_strjoin(line_join, line);
		free(line);
		line_join = tmp;
		line = get_next_line(fd);
	}
	dt->fd_lines = ft_split(line_join, '\n');
	int i = 0;
	while (dt->fd_lines[i])
	{
		printf("%s\n", dt->fd_lines[i]);
		i++;
	}
	free(line_join);
	free(line);
	close(fd);
}
