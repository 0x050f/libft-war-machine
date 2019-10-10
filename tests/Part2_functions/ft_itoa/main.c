/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:19:22 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:50:09 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
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
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_print_result(ft_itoa(0));
	else if (arg == 2)
		ft_print_result(ft_itoa(9));
	else if (arg == 3)
		ft_print_result(ft_itoa(-9));
	else if (arg == 4)
		ft_print_result(ft_itoa(10));
	else if (arg == 5)
		ft_print_result(ft_itoa(-10));
	else if (arg == 6)
		ft_print_result(ft_itoa(8124));
	else if (arg == 7)
		ft_print_result(ft_itoa(-9874));
	else if (arg == 8)
		ft_print_result(ft_itoa(543000));
	else if (arg == 9)
		ft_print_result(ft_itoa(-2147483648LL));
	else if (arg == 10)
		ft_print_result(ft_itoa(2147483647));
	return (0);
}
