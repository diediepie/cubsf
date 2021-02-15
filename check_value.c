/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:53:19 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/12 15:25:29 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	check_map(char *line)
{
	count_sprite(line);
	g_map[g_row] = ft_strdup2(line);
	g_row++;
}

int		check_player(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (1);
	return (0);
}

int		ck_horizontal(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int		checklastline(int line)
{
	int	i;

	i = 0;
	while (g_map[line][i] || g_map[line][i] == ' ')
		i++;
	if (g_map[line][i] == '1')
	{
		if (ck_horizontal(g_map[line]) == 0)
			ft_error("WRONG IN MAP last Line RC");
	}
	else if (g_map[line][0] == '\n' || spacemap(g_map[line]))
	{
		line--;
		checklastline(line);
	}
	return (0);
}

void	ck_empty_line(int linenumb, t_lnkd *head)
{
	t_lnkd *current_node;

	current_node = head;
	while (current_node != NULL)
	{
		if (current_node->val != 0 && current_node->val == linenumb)
		{
			if (g_map[linenumb][0] == '\0')
				ft_error("emptyline inside the map");
			else if (g_map[linenumb][0] == ' ')
				if (ck_horizontal(g_map[linenumb - 1]) == 0 &&
					ck_horizontal(g_map[linenumb + 1]) == 0)
					ft_error("WRONG IN MAP IN LINES");
		}
		current_node = current_node->next;
	}
}
