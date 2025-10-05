/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:25:25 by maeskhai          #+#    #+#             */
/*   Updated: 2025/09/25 01:10:48 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing/cub3d.h"

int	main(int ac, char **av)
{
	t_data	dt;

	if (ac != 2)
		ft_print_error("Error\nInvalid args!\n", NULL, NULL);
	ft_parsing(av[1], &dt);
}
