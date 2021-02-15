/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:46:55 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/12 14:35:05 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

int		check_arg_save(char *str, char *found)
{
	int	i;

	i = 0;
	while (str[i] && found[i] && str[i] == found[i])
		i++;
	return (str[i] - found[i]);
}
