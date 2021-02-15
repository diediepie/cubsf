/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emptyline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:32:05 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/12 15:25:29 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	push(t_lnkd *head, int val)
{
	t_lnkd *current;

	current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = (t_lnkd *)malloc(sizeof(t_lnkd));
	if (current->next == NULL)
		ft_error("Error empty line alocation error");
	current->next->val = val;
	current->next->next = NULL;
}

void	printlink(t_lnkd *head)
{
	t_lnkd *current_node;

	current_node = head;
	while (current_node != NULL)
	{
		printf("%d \n", current_node->val);
		current_node = current_node->next;
	}
}

int		countlnk(t_lnkd *head)
{
	t_lnkd	*current_node;
	int		cnt;

	cnt = -1;
	current_node = head;
	while (current_node != NULL)
	{
		cnt++;
		current_node = current_node->next;
	}
	return (cnt);
}
