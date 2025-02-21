/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobytrap <bobytrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:08:43 by bobytrap          #+#    #+#             */
/*   Updated: 2025/02/20 17:08:43 by bobytrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO count lines (will need GNL)
// int	count_lines(char *av){}


// is an strlen but in the context for these project i prefer to call it count_cols 
// TODO we will use strlen for these one babe
int	count_cols(char *line)
{
	int	count;

	count = 0;
	while (line[i] != '\0')
		count++;
	return (count);
}

