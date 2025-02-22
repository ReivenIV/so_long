/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:23:30 by rita              #+#    #+#             */
/*   Updated: 2025/02/11 13:54:41 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char sep)
{
	int		count;
	bool	inside_word;
	int		i;

	count = 0;
	inside_word = false;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep && !inside_word)
		{
			inside_word = true;
			count++;
		}
		else if (str[i] == sep)
			inside_word = false;
		i++;
	}
	return (count);
}

static char	*get_next_word(const char **str, char sep)
{
	int			start;
	char		*word;
	int			len;
	int			i;
	int			j;

	i = 0;
	while ((*str)[i] == sep && (*str)[i])
		i++;
	start = i;
	len = 0;
	while ((*str)[i + len] && (*str)[i + len] != sep)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = (*str)[start + j];
		j++;
	}
	word[len] = '\0';
	*str = *str + i + len;
	return (word);
}

char	**ft_split(const char *str, char sep)
{
	int		words_number;
	char	**dest;
	int		i;

	if (!str)
		return (NULL);
	words_number = count_words(str, sep);
	dest = malloc(sizeof(char *) * (words_number + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < words_number)
	{
		dest[i] = get_next_word(&str, sep);
		if (!dest[i])
		{
			while (i > 0)
				free(dest[--i]);
			free(dest);
			return (NULL);
		}
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

// // #include <stdio.h>
// // int main(void)
// // {
// //     char **result;
// //     int i;
// //     // Test case 1
// //     result = ft_split("Hello,world,this,is,a,test", ',');
// //     if (result)
// //     {
// //         for (i = 0; result[i] != NULL; i++)
// //             printf("result[%d]: %s\n", i, result[i]);
// //         // Free allocated memory
// //         for (i = 0; result[i] != NULL; i++)
// //             free(result[i]);
// //         free(result);
// //     }
// //     // Test case 2
// //     result = ft_split("Another test with different separator", ' ');
// //     if (result)
// //     {
// //         for (i = 0; result[i] != NULL; i++)
// //             printf("result[%d]: %s\n", i, result[i]);
// //         // Free allocated memory
// //         for (i = 0; result[i] != NULL; i++)
// //             free(result[i]);
// //         free(result);
// //     }
// //     return 0;
// // }