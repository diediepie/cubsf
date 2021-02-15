/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_split.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: am-khant <am-khant@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/14 04:56:47 by am-khant		  #+#	#+#			 */
/*   Updated: 2021/01/19 18:42:29 by am-khant		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static int			count_words(const char *str, char c)
{
	int count;
	int words;
	int test;

	test = 0;
	count = 0;
	words = 0;
	if (!str)
		return (0);
	while (*str !=  '\0')
	{
		if (*str  ==  c)
		{
			test = 1;
			words = 0;
		}
		else if (words  ==  0)
		{
			words = 1;
			count++;
		}
		str++;
	}
	return ((test  ==  0 && count  ==  1) ? -1 : count);
}

static int			words_lenght(const char *str, int i, char c)
{
	int lenght;

	lenght = 0;
	while (str[i] !=  c && str[i] !=  '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static	void	ft_free(char **heap, int j)
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

static	char		**help(const char *str)
{
	char		**heap;
	int			i;
	int			j;

	i = 0;
	j = 1;
	if (!(heap = (char**)malloc(sizeof(char*) * 2)))
		return (NULL);
	if (!(heap[0] = (char*)malloc(1 * ft_strlen(str) + 1)))
		ft_free(heap, j);
	while (str[i])
	{
		heap[0][i] = str[i];
		i++;
	}
	heap[0][i] = '\0';
	heap[1] = NULL;
	return (heap);
}

char				**ft_split(const char *str, char c)
{
	char		**heap;
	int			i;
	int			k;
	int			j;

	i = 0;
	j = 0;
	if (count_words(str, c)  ==  -1 || !str)
		return ((count_words(str, c)  ==  -1) ? help(str) : NULL);
	if (!(heap = (char**)malloc(sizeof(char*) * (count_words(str, c) + 1))))
		return (NULL);
	while (str[i] !=  '\0' && j < count_words(str, c))
	{
		k = 0;
		while (str[i]  ==  c)
			i++;
		if (!(heap[j] = (char*)malloc(1 * words_lenght(str, i, c) + 1)))
			ft_free(heap, j);
		while (str[i] !=  c && str[i] !=  '\0')
			heap[j][k++] = str[i++];
		heap[j++][k] = '\0';
	}
	heap[j] = NULL;
	return (heap);
}
