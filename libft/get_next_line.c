#include "libft.h"


char	*start_next_stash(char *stash)
{
    char	*next_line;
    int		i;
    int		j;

    i = 0;
    j = 0;
    while (stash[i] != '\n' && stash[i])
        i++;
    if (!stash[i])
        return (free(stash), NULL);
    next_line = (char *)malloc(sizeof(char) * ((ft_strlen(stash) - i + 1)));
    if (!next_line)
        return (NULL);
    i++;
    while (stash[i])
    {
        next_line[j] = stash[i];
        j++;
        i++;
    }
    next_line[j] = '\0';
    free(stash);
    return (next_line);
}

static char	*print_line(char *stash)
{
	char	*str;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	str = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		str[i] = '\n';
	return (str);
}

static char	*ft_free(char *stash, char *temp)
{
	char	*final;

	final = ft_strjoin(stash, temp);
	free (stash);
	return (final);
}

static char	*find_line(char *stash, int fd)
{
	char	*temp;
	int		count_char;

	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	temp = ft_calloc ((BUFFER_SIZE + 1), sizeof(char));
	count_char = 1;
	while (!ft_strchr(stash, '\n') && count_char != 0)
	{
		count_char = read(fd, temp, BUFFER_SIZE);
		if (count_char == -1)
		{
			free (temp);
			free (stash);
			return (NULL);
		}
		temp [count_char] = '\0';
		stash = ft_free(stash, temp);
	}
	free (temp);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = find_line(stash, fd);
	if (!stash)
		return (NULL);
	line = print_line(stash);
	stash = start_next_stash(stash);
	return (line);
}

