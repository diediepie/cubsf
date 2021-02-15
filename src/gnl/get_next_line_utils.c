// /* ************************************************************************** */
// /*																			*/
// /*														:::	  ::::::::   */
// /*   get_next_line_utils.c							  :+:	  :+:	:+:   */
// /*													+:+ +:+		 +:+	 */
// /*   By: am-khant <am-khant@student.42.fr>		  +#+  +:+	   +#+		*/
// /*												+#+#+#+#+#+   +#+		   */
// /*   Created: 2019/10/30 14:24:46 by nbjaghou		  #+#	#+#			 */
// /*   Updated: 2021/01/25 09:39:10 by am-khant		 ###   ########.fr	   */
// /*																			*/
// /* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	long	*d;
	char	*smll;
	int		i;
	int		j;

	if (n > 0)
	{
		i = 0;
		if (n  >=  8)
		{
			d = (long *)s;
			while (n > 8)
			{
				d[i++] = '\0';
				n -=  8;
			}
		}
		if (n < 8)
		{
			smll = s + (i * 8);
			j = 0;
			while (n--)
				smll[j++] = '\0';
		}
	}
}
char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] !=  '\0')
	{
		if (s[i]  ==  c)
			return ((char*)(s + i));
		i++;
	}
	if (c  ==  '\0')
		return ((char*)(s + i));
	return (0);
}

char	*ft_strjoin(char  *s1, char  *s2)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i] !=  '\0')
		i++;
	while (s2[j] !=  '\0')
		j++;
	if (!(tab = malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i] !=  '\0')
		tab[i] = s1[i];
	while (s2[++j] !=  '\0')
		tab[i + j] = s2[j];
	tab[i + j] = '\0';
	free (s1);
	return (tab);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if(!s)
		return (0);
	while (s[i] !=  '\0')
		i++;
	return (i);
}