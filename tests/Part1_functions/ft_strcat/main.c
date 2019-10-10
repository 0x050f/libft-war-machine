/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:03:07 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:43:38 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	char	*dest;
	int		arg;

	alarm(5);
	if (!(dest = (char *)malloc(sizeof(*dest) * 15)) || argc == 1)
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	if ((arg = atoi(argv[1])) == 1)
	{
		dest[11] = 'a';
		if (dest != ft_strcat(dest, "lorem"))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 15);
	}
	else if (arg == 2)
	{
		if (dest != ft_strcat(dest, ""))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 15);
	}
	else if (arg == 3)
	{
		dest[0] = '\0';
		dest[11] = 'a';
		if (dest != ft_strcat(dest, "lorem ipsum"))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 15);
	}
	return (0);
}
