/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:30:30 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/13 16:30:48 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	read_check_map(t_info *info, int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		return (ft_error("PROBLEM IN ARGUMENTS"));
	if (argv[1] && !check_file(argv[1], ".cub"))
		return (ft_error("PROBLEM IN THE FILE NAME"));
	if (argv[2] && argc == 3 && !check_arg_save(argv[2], "--save"))
		g_screenshot = 1;
	else if (argc == 3 && check_arg_save(argv[2], "--save"))
		return (ft_error("PROBLEM IN ARG SAVE"));
	initialise_map();
	read_map(argv[1]);
	get_map(argv[1]);
	fill_with_wall(info);
}
