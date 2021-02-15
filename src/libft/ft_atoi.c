/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_atoi.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: am-khant <am-khant@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/09 15:37:17 by nbjaghou		  #+#	#+#			 */
/*   Updated: 2021/01/30 15:01:23 by am-khant		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static int	atoi_spaces(const char *s)
{
	int	i;

	i = 0;
	while (s[i] == '\t' ||
				s[i] == '\n' ||
				s[i] == '\v' ||
				s[i] == '\f' ||
				s[i] == '\r' ||
				s[i] == ' ')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	long	result;
	int		i;
	int		sign;

	sign = 1;
	i = atoi_spaces(str);
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if (result > INT16_MAX && sign == 1)
			return (INT16_MAX);
		if (result > INT16_MAX && sign == -1)
			return (-1 * INT16_MAX);
		i++;
	}
	return (result * sign);
}
