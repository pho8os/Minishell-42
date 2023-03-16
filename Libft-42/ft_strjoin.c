/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:30:36 by yettabaa          #+#    #+#             */
/*   Updated: 2023/03/16 04:29:31 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_sp(char const *s1, char const *s2, char c)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);		
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i++] = c;
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free((void *)s1);
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		j;
	char	*str;
	int		i;

	i = -1;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);	
	str = malloc(sizeof (char) * ((ft_strlen(s1)) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	j = i;
	i = -1;
	while (s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	free((void *)s1);
	return (str);
}

char	*ft_strjoin_c(const char *s1, const char *s2)
{
	char *str;
	int i;

	if (!s1)
		return(ft_substr(s2, 0, 1));
	if (!s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + 2);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i++] = s2[0];
	str[i] = '\0';
	free((void *)s1);
	return (str);
}
