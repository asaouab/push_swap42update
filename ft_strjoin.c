/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:21:51 by asaouab           #+#    #+#             */
/*   Updated: 2023/08/10 19:30:26 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;
	int		j;
	int		c;

	c = strlen(sep);
	j = 0;
	while (strs[j])
	{
		i = i + strlen(strs[j]);
		j++;
	}
	i += (c * (j - 1));
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	c = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			s[c] = strs[i][j];
			c++;
			j++;
		}
		j = 0;
		while (sep[j] != '\0' && i < size - 1)
		{
			s[c] = sep[j];
			c++;
			j++;
		}
		i++;
	}
	s[c] = '\0';
	return (s);
}
