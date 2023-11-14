/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:49:21 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/05/08 10:13:39 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str_new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str_new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str_new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str_new[i + j] = s2[j];
		j++;
	}
	str_new[i + j] = '\0';
	return (str_new);
}
