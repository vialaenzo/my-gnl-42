/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:26:41 by eviala            #+#    #+#             */
/*   Updated: 2024/06/18 11:26:39 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*cpy;

	cpy = (char *)malloc(ft_strlen(src) + 1 * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char	*ft_strjoin_free(char *stash_c, char *buffer)
{
	size_t	len;
	char	*n_stash_c;

	char *(tmp_line) = stash_c;
	len = (ft_strlen(stash_c) + ft_strlen(buffer));
	size_t (i) = 0;
	n_stash_c = (char *)malloc(len + 1 * sizeof(char));
	if (!n_stash_c)
		return (NULL);
	while (i < len)
	{
		while (*stash_c)
			n_stash_c[i++] = *stash_c++;
		while (*buffer)
			n_stash_c[i++] = *buffer++;
	}
	n_stash_c[i] = '\0';
	free(tmp_line);
	return (n_stash_c);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
