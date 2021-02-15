/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.h									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: am-khant <am-khant@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/24 22:10:04 by nbjaghou		  #+#	#+#			 */
/*   Updated: 2021/02/08 16:39:33 by am-khant		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include "../libft/libft.h"
# define BUFFER_SIZE 32
int		get_next_line(int fd, char **line);
char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);

#endif