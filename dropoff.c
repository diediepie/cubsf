/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropoff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:32:41 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/13 15:10:25 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	ft_error(char *message)
{
	ft_putstr("ERROR :\n");
	ft_putstr(message);
	ft_putchar('\n');
	exit(EXIT_FAILURE);
}

void	ft_free(char **heap, int j)
{
	int i;

	i = 0;
	while (i <= j)
	{
		free(heap[i]);
		heap[i] = NULL;
		i++;
	}
	free(heap);
	heap = NULL;
}

void	free_window(t_info *info)
{
	ft_free(g_map, g_row - 1);
	free(g_path_no);
	free(g_path_so);
	free(g_path_we);
	free(g_path_ea);
	free(g_path_s);
}

void	clear_window(t_info *data)
{
	int i;
	int j;

	i = -1;
	while (++i < g_height)
	{
		j = -1;
		while (++j < g_wid)
		{
			data->img.data[i * g_wid + j] = 0x000000;
		}
	}
}

void	freetake(char **mem2, char **mem3, char line_c, char c)
{
	int	i;

	ft_free(mem2, skipnull(mem2));
	ft_free(mem3, skipnull(mem3));
	if (c == 'F')
		if (line_c != 'F')
			return (ft_error("Something wrong Before F"));
	if (c == 'C')
		if (line_c != 'C')
			return (ft_error("Something wrong Before C"));
}
