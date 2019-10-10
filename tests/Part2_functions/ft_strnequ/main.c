/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:34:37 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:53:57 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

void	ft_print_result(int n)
{
	if (n == 0)
		write(1, "0", 1);
	else
		write(1, "1", 1);
}

int		main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_print_result(ft_strnequ("salut", "salut", 50));
	else if (arg == 2)
		ft_print_result(ft_strnequ("test", "tests", 6));
	else if (arg == 3)
		ft_print_result(ft_strnequ("tests", "test", 6));
	else if (arg == 4)
		ft_print_result(ft_strnequ("test", "tEst", 6));
	else if (arg == 5)
		ft_print_result(ft_strnequ("", "test", 6));
	else if (arg == 6)
		ft_print_result(ft_strnequ("test", "", 6));
	else if (arg == 7)
		ft_print_result(ft_strnequ("", "", 6));
	else if (arg == 8)
		ft_print_result(ft_strnequ("test", "test", 2));
	else if (arg == 9)
		ft_print_result(ft_strnequ("tew", "tez", 2));
	else if (arg == 10)
		ft_print_result(ft_strnequ("", "", 0));
	else if (arg == 11)
		ft_print_result(ft_strnequ("abcd", "zxyw", 0));
	return (0);
}
