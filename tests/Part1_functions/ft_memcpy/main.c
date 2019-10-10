/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:02:06 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:43:04 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	void	*mem;
	int		arg;

	alarm(5);
	if (!(mem = malloc(sizeof(*mem) * 30)) || argc == 1)
		return (0);
	memset(mem, 'j', 30);
	if ((arg = atoi(argv[1])) == 1)
	{
		if (mem != ft_memcpy(mem, "zyxwvutsrqponmlkjihgfedcba", 14))
			write(1, "dest's adress was not returned\n", 31);
		write(1, mem, 30);
	}
	else if (arg == 2)
	{
		if (mem != ft_memcpy(mem, "zyxwvutst", 0))
			write(1, "dest's adress was not returned\n", 31);
		write(1, mem, 30);
	}
	else if (arg == 3)
	{
		if (mem != ft_memcpy(mem, "zy\0xw\0vu\0\0tsr", 11))
			write(1, "dest's adress was not returned\n", 31);
		write(1, mem, 30);
	}
	return (0);
}
