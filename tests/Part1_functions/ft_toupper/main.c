/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:09:27 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:49:20 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	int		i;
	int		c;
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		i = 0;
		while (i <= 47)
		{
			c = ft_toupper(i);
			write(1, &c, 1);
			i++;
		}
	}
	else if (arg == 2)
	{
		i = '0';
		while (i <= '9')
		{
			c = ft_toupper(i);
			write(1, &c, 1);
			i++;
		}
	}
	else if (arg == 3)
	{
		i = 58;
		while (i <= 64)
		{
			c = ft_toupper(i);
			write(1, &c, 1);
			i++;
		}
	}
	else if (arg == 4)
	{
		i = 'A';
		while (i <= 'Z')
		{
			c = ft_toupper(i);
			write(1, &c, 1);
			i++;
		}
	}
	else if (arg == 5)
	{
		i = 91;
		while (i <= 96)
		{
			c = ft_toupper(i);
			write(1, &c, 1);
			i++;
		}
	}
	else if (arg == 6)
	{
		i = 'a';
		while (i <= 'z')
		{
			c = ft_toupper(i);
			write(1, &c, 1);
			i++;
		}
	}
	else if (arg == 7)
	{
		i = 123;
		while (i <= 127)
		{
			c = ft_toupper(i);
			write(1, &c, 1);
			i++;
		}
	}
	return (0);
}
