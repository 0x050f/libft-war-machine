/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:01:23 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:39:32 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(int argc, const char *argv[])
{
	void	*mem;
	void	*membis;
	int		arg;

	alarm(5);
	if (!(mem = malloc(sizeof(*mem) * 30)) || argc == 1)
		return (0);
	memset(mem, 'j', 29);
	((char*)mem)[29] = '\0';
	membis = mem;
	if ((arg = atoi(argv[1])) == 1)
	{
		if (!(mem = ft_memccpy(mem, "zyxwvutsrqponmlkjihgfedcba", 'r', 20)))
			ft_print_result("NULL");
		else
		{
			ft_print_result(mem);
			write(1, "\n", 1);
			ft_print_result(membis);
		}
	}
	else if (arg == 2)
	{
		if (!(mem = ft_memccpy(mem, "zyxwvutsrqponmlkjihgfedcba", 'r', 3)))
			ft_print_result("NULL");
		else
		{
			ft_print_result(mem);
			write(1, "\n", 1);
			ft_print_result(membis);
		}
	}
	else if (arg == 3)
	{
		if (!(mem = ft_memccpy(mem, "zyxwvutsrqponmlkjihgfedcba", 'a', 26)))
			ft_print_result("NULL");
		else
		{
			ft_print_result(mem);
			write(1, "\n", 1);
			ft_print_result(membis);
		}
	}
	else if (arg == 4)
	{
		if (!(mem = ft_memccpy(mem, "zyxwvuzyxwvu", 'x', 20)))
			ft_print_result("NULL");
		else
		{
			ft_print_result(mem);
			write(1, "\n", 1);
			ft_print_result(membis);
		}
	}
	return (0);
}
