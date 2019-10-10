/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:06:12 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:44:51 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"
#include <string.h>

void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

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
		ft_print_result(ft_strlcat(dest, "lorem", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 2)
	{
		ft_print_result(ft_strlcat(dest, "", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 3)
	{
		dest[0] = '\0';
		dest[11] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 4)
	{
		dest[14] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 5)
	{
		dest[10] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 0));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 6)
	{
		dest[10] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 1));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 7)
	{
		memset(dest, 'r', 15);
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 8)
	{
		dest[10] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 6));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 9)
	{
		memset(dest, 'r', 14);
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	return (0);
}
