/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:58:17 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/08 18:32:39 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

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
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_print_result(ft_strlen("Hello !"));
	else if (arg == 2)
		ft_print_result(ft_strlen("1"));
	else if (arg == 3)
		ft_print_result(ft_strlen("lorem\tipsum\tdolor\nsit\namet\n"));
	else if (arg == 4)
		ft_print_result(ft_strlen(""));
	else if (arg == 5)
		ft_print_result(ft_strlen("\n\n\f\r\t"));
	else if (arg == 6)
		ft_print_result(ft_strlen("   "));
	return (0);
}
