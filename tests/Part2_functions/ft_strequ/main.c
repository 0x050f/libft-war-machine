/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:32:07 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:52:56 by jtoty            ###   ########.fr       */
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
		ft_print_result(ft_strequ("salut", "salut"));
	else if (arg == 2)
		ft_print_result(ft_strequ("test", "tests"));
	else if (arg == 3)
		ft_print_result(ft_strequ("tests", "test"));
	else if (arg == 4)
		ft_print_result(ft_strequ("test", "tEst"));
	else if (arg == 5)
		ft_print_result(ft_strequ("", "test"));
	else if (arg == 6)
		ft_print_result(ft_strequ("test", ""));
	else if (arg == 7)
		ft_print_result(ft_strequ("", ""));
	return (0);
}
