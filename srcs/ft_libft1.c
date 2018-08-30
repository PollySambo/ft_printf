/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 08:32:17 by psambo            #+#    #+#             */
/*   Updated: 2018/07/20 08:32:33 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((s1[i] < s2[i]) || (s1[i] > s2[i]))
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strrev(char *str)
{
	char	*rev;
	int		i;
	int		x;

	x = 0;
	i = ft_strlen(str);
	rev = (char *)malloc(sizeof(char) * (i + 1));
	while (--i > -1)
		rev[x++] = str[i];
	rev[x] = '\0';
	free(str);
	return (rev);
}

char	*ft_strnew(size_t size)
{
	char			*tab;
	unsigned int	i;

	i = 0;
	if (!(tab = (char *)malloc(size + 1)))
		return (NULL);
	while (i < size + 1)
		tab[i++] = '\0';
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*f;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	if (!(f = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		f[i] = s1[i];
	while (*s2)
		f[i++] = *s2++;
	f[i] = '\0';
	return (f);
}
