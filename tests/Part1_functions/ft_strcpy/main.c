/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:04:46 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:44:13 by jtoty            ###   ########.fr       */
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
	memset(dest, 'f', 9);
	if ((arg = atoi(argv[1])) == 1)
	{
		if (dest != ft_strcpy(dest, "lorem"))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 15);
	}
	else if (arg == 2)
	{
		if (dest != ft_strcpy(dest, "lorem ipsum"))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 15);
	}
	else if (arg == 3)
	{
		if (dest != ft_strcpy(dest, ""))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 15);
	}
	return (0);
}
