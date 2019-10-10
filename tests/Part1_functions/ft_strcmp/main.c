/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:04:21 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:44:01 by jtoty            ###   ########.fr       */
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
		ft_print_result(ft_strcmp("salut", "salut"));
	else if (arg == 2)
		ft_print_result(ft_strcmp("test", "testss"));
	else if (arg == 3)
		ft_print_result(ft_strcmp("testss", "test"));
	else if (arg == 4)
		ft_print_result(ft_strcmp("test", "tEst"));
	else if (arg == 5)
		ft_print_result(ft_strcmp("", "test"));
	else if (arg == 6)
		ft_print_result(ft_strcmp("test", ""));
	else if (arg == 7)
		ft_print_result(ft_strcmp("test\200", "test\0"));
	return (0);
}
