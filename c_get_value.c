/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_get_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am-khant <am-khant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:43:38 by am-khant          #+#    #+#             */
/*   Updated: 2021/02/13 15:09:17 by am-khant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	take_s(char *line)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (g_path_s != NULL)
		return (ft_error("Duplicated S config"));
	if (line[0] != 'S')
		return (ft_error("Something wrong Before S"));
	if (!check_file(line, ".xpm"))
		return (ft_error("WRONG IN Sprite FILE"));
	i += 1;
	if (!trimexist(line, i - 1))
		return (ft_error("Something wrong after S"));
	while (line[i] && line[i] == ' ')
		i++;
	g_path_s = (char*)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	while (line[i++])
		g_path_s[j++] = line[i - 1];
	g_path_s[j--] = '\0';
	while (g_path_s[j] && g_path_s[j] == ' ')
		g_path_s[j--] = '\0';
	if (open(g_path_s, O_RDONLY) < 0)
		return (ft_error("S FILE Not Exist"));
	g_info++;
}

void	str_digit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		ft_error("number is empty");
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			ft_error("Wrong number in R,G,B Code");
		i++;
	}
}

void	take_f(char *line)
{
	char	**info;
	char	**tmp;
	int		i;

	checkduplicat('F', line);
	tmp = ft_split(line, ' ');
	i = skipnull(tmp);
	if (i != 2)
		return (ft_error("Wrong color F declaration"));
	info = ft_split(tmp[1], ',');
	i = skipnull(info);
	if (i != 3 || count_char(tmp[1], ',') != 2)
		return (ft_error("Wrong color F (R,G,B) code"));
	i = -1;
	while (++i <= 2)
	{
		str_digit(info[i]);
		if (ft_atoi(info[i]) >= 0 && ft_atoi(info[i]) <= 255)
			g_clr_f[i] = ft_atoi(info[i]);
		else
			return (ft_error("Wrong color F (R,G,B) code"));
	}
	g_info++;
	freetake(tmp, info, line[0], 'F');
}

void	take_c(char *line)
{
	char	**info;
	char	**tmp;
	int		i;

	checkduplicat('C', line);
	tmp = ft_split(line, ' ');
	i = skipnull(tmp);
	if (i != 2)
		return (ft_error("Wrong color C declaration"));
	info = ft_split(tmp[1], ',');
	i = skipnull(info);
	if (i != 3 || count_char(tmp[1], ',') != 2)
		return (ft_error("Wrong color C (R,G,B) code"));
	i = -1;
	while (++i <= 2)
	{
		str_digit(info[i]);
		if (ft_atoi(info[i]) >= 0 && ft_atoi(info[i]) <= 255)
			g_clr_c[i] = ft_atoi(info[i]);
		else
			return (ft_error("Wrong color C (R,G,B) code"));
	}
	g_info++;
	freetake(tmp, info, line[0], 'C');
}
