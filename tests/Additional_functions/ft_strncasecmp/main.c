/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:07:32 by jtoty             #+#    #+#             */
/*   Updated: 2017/04/14 17:04:44 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

void	ft_print_result(int n)
{
	if (n > 0)
		write(1, "1", 1);
	else if (n < 0)
		write(1, "-1", 2);
	else
		write(1, "0", 1);
}

int		main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_print_result(ft_strncasecmp("salut", "salut", 5));
	else if (arg == 2)
		ft_print_result(ft_strncasecmp("test", "testss", 7));
	else if (arg == 3)
		ft_print_result(ft_strncasecmp("testss", "test", 7));
	else if (arg == 4)
		ft_print_result(ft_strncasecmp("test", "tEst", 4));
	else if (arg == 5)
		ft_print_result(ft_strncasecmp("", "test", 4));
	else if (arg == 6)
		ft_print_result(ft_strncasecmp("test", "", 4));
	else if (arg == 7)
		ft_print_result(ft_strncasecmp("abcdefghij", "abcdefgxyz", 3));
	else if (arg == 8)
		ft_print_result(ft_strncasecmp("abcdefgh", "abcdwxyz", 4));
	else if (arg == 9)
		ft_print_result(ft_strncasecmp("zyxbcdefgh", "abcdwxyz", 0));
	else if (arg == 10)
		ft_print_result(ft_strncasecmp("abcdefgh", "", 0));
	else if (arg == 11)
		ft_print_result(ft_strncasecmp("test\200", "test\0", 6));
	return (0);
}
