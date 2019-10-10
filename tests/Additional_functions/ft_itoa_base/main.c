/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:26:21 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:59:43 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

void	ft_print_result(char *s)
{
	int		len;

	len = 0;
	while (s[len])
	{
		if (s[len] >= 'a' && s[len] <= 'z')
			s[len] -= 32;
		len++;
	}
	write(1, s, len);
	write(1, "\n", 1);
}

int		main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		ft_print_result(ft_itoa_base(0, arg + 1));
		ft_print_result(ft_itoa_base(arg, arg + 1));
		ft_print_result(ft_itoa_base(-arg, arg + 1));
		ft_print_result(ft_itoa_base(arg + 1, arg + 1));
		ft_print_result(ft_itoa_base(-(arg + 1), arg + 1));
		ft_print_result(ft_itoa_base(8124, arg + 1));
		ft_print_result(ft_itoa_base(-9874, arg + 1));
		ft_print_result(ft_itoa_base(543000, arg + 1));
		ft_print_result(ft_itoa_base(-2147483648LL, arg + 1));
		ft_print_result(ft_itoa_base(2147483647, arg + 1));
	}
	else if (arg == 2)
	{
		ft_print_result(ft_itoa_base(0, arg + 1));
		ft_print_result(ft_itoa_base(arg, arg + 1));
		ft_print_result(ft_itoa_base(-arg, arg + 1));
		ft_print_result(ft_itoa_base(arg + 1, arg + 1));
		ft_print_result(ft_itoa_base(-(arg + 1), arg + 1));
		ft_print_result(ft_itoa_base(8124, arg + 1));
		ft_print_result(ft_itoa_base(-9874, arg + 1));
		ft_print_result(ft_itoa_base(543000, arg + 1));
		ft_print_result(ft_itoa_base(-2147483648LL, arg + 1));
		ft_print_result(ft_itoa_base(2147483647, arg + 1));
	}
	else if (arg == 3)
	{
		ft_print_result(ft_itoa_base(0, arg + 1));
		ft_print_result(ft_itoa_base(arg, arg + 1));
		ft_print_result(ft_itoa_base(-arg, arg + 1));
		ft_print_result(ft_itoa_base(arg + 1, arg + 1));
		ft_print_result(ft_itoa_base(-(arg + 1), arg + 1));
		ft_print_result(ft_itoa_base(8124, arg + 1));
		ft_print_result(ft_itoa_base(-9874, arg + 1));
		ft_print_result(ft_itoa_base(543000, arg + 1));
		ft_print_result(ft_itoa_base(-2147483648LL, arg + 1));
		ft_print_result(ft_itoa_base(2147483647, arg + 1));
	}
	else if (arg == 4)
	{
		ft_print_result(ft_itoa_base(0, arg + 1));
		ft_print_result(ft_itoa_base(arg, arg + 1));
		ft_print_result(ft_itoa_base(-arg, arg + 1));
		ft_print_result(ft_itoa_base(arg + 1, arg + 1));
		ft_print_result(ft_itoa_base(-(arg + 1), arg + 1));
		ft_print_result(ft_itoa_base(8124, arg + 1));
		ft_print_result(ft_itoa_base(-9874, arg + 1));
		ft_print_result(ft_itoa_base(543000, arg + 1));
		ft_print_result(ft_itoa_base(-2147483648LL, arg + 1));
		ft_print_result(ft_itoa_base(2147483647, arg + 1));
	}
	else if (arg == 5)
	{
		ft_print_result(ft_itoa_base(0, arg + 1));
		ft_print_result(ft_itoa_base(arg, arg + 1));
		ft_print_result(ft_itoa_base(-arg, arg + 1));
		ft_print_result(ft_itoa_base(arg + 1, arg + 1));
		ft_print_result(ft_itoa_base(-(arg + 1), arg + 1));
		ft_print_result(ft_itoa_base(8124, arg + 1));
		ft_print_result(ft_itoa_base(-9874, arg + 1));
		ft_print_result(ft_itoa_base(543000, arg + 1));
		ft_print_result(ft_itoa_base(-2147483648LL, arg + 1));
		ft_print_result(ft_itoa_base(2147483647, arg + 1));
	}
	else if (arg == 6)
	{
		ft_print_result(ft_itoa_base(0, arg + 1));
		ft_print_result(ft_itoa_base(arg, arg + 1));
		ft_print_result(ft_itoa_base(-arg, arg + 1));
		ft_print_result(ft_itoa_base(arg + 1, arg + 1));
		ft_print_result(ft_itoa_base(-(arg + 1), arg + 1));
		ft_print_result(ft_itoa_base(8124, arg + 1));
		ft_print_result(ft_itoa_base(-9874, arg + 1));
		ft_print_result(ft_itoa_base(543000, arg + 1));
		ft_print_result(ft_itoa_base(-2147483648LL, arg + 1));
		ft_print_result(ft_itoa_base(2147483647, arg + 1));
	}
	else if (arg == 7)
	{
		ft_print_result(ft_itoa_base(0, arg + 1));
		ft_print_result(ft_itoa_base(arg, arg + 1));
		ft_print_result(ft_itoa_base(-arg, arg + 1));
		ft_print_result(ft_itoa_base(arg + 1, arg + 1));
		ft_print_result(ft_itoa_base(-(arg + 1), arg + 1));
		ft_print_result(ft_itoa_base(8124, arg + 1));
		ft_print_result(ft_itoa_base(-9874, arg + 1));
		ft_print_result(ft_itoa_base(543000, arg + 1));
		ft_print_result(ft_itoa_base(-2147483648LL, arg + 1));
		ft_print_result(ft_itoa_base(2147483647, arg + 1));
	}
	else if (arg == 8)
	{
		ft_print_result(ft_itoa_base(0, arg + 1));
		ft_print_result(ft_itoa_base(arg, arg + 1));
		ft_print_result(ft_itoa_base(-arg, arg + 1));
		ft_print_result(ft_itoa_base(arg + 1, arg + 1));
		ft_print_result(ft_itoa_base(-(arg + 1), arg + 1));
		ft_print_result(ft_itoa_base(8124, arg + 1));
		ft_print_result(ft_itoa_base(-9874, arg + 1));
		ft_print_result(ft_itoa_base(543000, arg + 1));
		ft_print_result(ft_itoa_base(-2147483648LL, arg + 1));
		ft_print_result(ft_itoa_base(2147483647, arg + 1));
	}
	else if (arg == 9)
	{
		ft_print_result(ft_itoa_base(0, arg + 1));
		ft_print_result(ft_itoa_base(arg, arg + 1));
		ft_print_result(ft_itoa_base(-arg, arg + 1));
		ft_print_result(ft_itoa_base(arg + 1, arg + 1));
		ft_print_result(ft_itoa_base(-(arg + 1), arg + 1));
		ft_print_result(ft_itoa_base(8124, arg + 1));
		ft_print_result(ft_itoa_base(-9874, arg + 1));
		ft_print_result(ft_itoa_base(543000, arg + 1));
		ft_print_result(ft_itoa_base(-2147483648LL, arg + 1));
		ft_print_result(ft_itoa_base(2147483647, arg + 1));
	}
	else if (arg == 10)
	{
		ft_print_result(ft_itoa_base(0, arg + 1));
		ft_print_result(ft_itoa_base(arg, arg + 1));
		ft_print_result(ft_itoa_base(-arg, arg + 1));
		ft_print_result(ft_itoa_base(arg + 1, arg + 1));
		ft_print_result(ft_itoa_base(-(arg + 1), arg + 1));
		ft_print_result(ft_itoa_base(8124, arg + 1));
		ft_print_result(ft_itoa_base(-9874, arg + 1));
		ft_print_result(ft_itoa_base(543000, arg + 1));
		ft_print_result(ft_itoa_base(-2147483648LL, arg + 1));
		ft_print_result(ft_itoa_base(2147483647, arg + 1));
	}
	else if (arg == 11)
	{
		ft_print_result(ft_itoa_base(0, arg + 1));
		ft_print_result(ft_itoa_base(arg, arg + 1));
		ft_print_result(ft_itoa_base(-arg, arg + 1));
		ft_print_result(ft_itoa_base(arg + 1, arg + 1));
		ft_print_result(ft_itoa_base(-(arg + 1), arg + 1));
		ft_print_result(ft_itoa_base(8124, arg + 1));
		ft_print_result(ft_itoa_base(-9874, arg + 1));
		ft_print_result(ft_itoa_base(543000, arg + 1));
		ft_print_result(ft_itoa_base(-2147483648LL, arg + 1));
		ft_print_result(ft_itoa_base(2147483647, arg + 1));
	}
	else if (arg == 12)
	{
		ft_print_result(ft_itoa_base(0, arg + 1));
		ft_print_result(ft_itoa_base(arg, arg + 1));
		ft_print_result(ft_itoa_base(-arg, arg + 1));
		ft_print_result(ft_itoa_base(arg + 1, arg + 1));
		ft_print_result(ft_itoa_base(-(arg + 1), arg + 1));
		ft_print_result(ft_itoa_base(8124, arg + 1));
		ft_print_result(ft_itoa_base(-9874, arg + 1));
		ft_print_result(ft_itoa_base(543000, arg + 1));
		ft_print_result(ft_itoa_base(-2147483648LL, arg + 1));
		ft_print_result(ft_itoa_base(2147483647, arg + 1));
	}
	else if (arg == 13)
	{
		ft_print_result(ft_itoa_base(0, arg + 1));
		ft_print_result(ft_itoa_base(arg, arg + 1));
		ft_print_result(ft_itoa_base(-arg, arg + 1));
		ft_print_result(ft_itoa_base(arg + 1, arg + 1));
		ft_print_result(ft_itoa_base(-(arg + 1), arg + 1));
		ft_print_result(ft_itoa_base(8124, arg + 1));
		ft_print_result(ft_itoa_base(-9874, arg + 1));
		ft_print_result(ft_itoa_base(543000, arg + 1));
		ft_print_result(ft_itoa_base(-2147483648LL, arg + 1));
		ft_print_result(ft_itoa_base(2147483647, arg + 1));
	}
	else if (arg == 14)
	{
		ft_print_result(ft_itoa_base(0, arg + 1));
		ft_print_result(ft_itoa_base(arg, arg + 1));
		ft_print_result(ft_itoa_base(-arg, arg + 1));
		ft_print_result(ft_itoa_base(arg + 1, arg + 1));
		ft_print_result(ft_itoa_base(-(arg + 1), arg + 1));
		ft_print_result(ft_itoa_base(8124, arg + 1));
		ft_print_result(ft_itoa_base(-9874, arg + 1));
		ft_print_result(ft_itoa_base(543000, arg + 1));
		ft_print_result(ft_itoa_base(-2147483648LL, arg + 1));
		ft_print_result(ft_itoa_base(2147483647, arg + 1));
	}
	else if (arg == 15)
	{
		ft_print_result(ft_itoa_base(0, arg + 1));
		ft_print_result(ft_itoa_base(arg, arg + 1));
		ft_print_result(ft_itoa_base(-arg, arg + 1));
		ft_print_result(ft_itoa_base(arg + 1, arg + 1));
		ft_print_result(ft_itoa_base(-(arg + 1), arg + 1));
		ft_print_result(ft_itoa_base(8124, arg + 1));
		ft_print_result(ft_itoa_base(-9874, arg + 1));
		ft_print_result(ft_itoa_base(543000, arg + 1));
		ft_print_result(ft_itoa_base(-2147483648LL, arg + 1));
		ft_print_result(ft_itoa_base(2147483647, arg + 1));
	}
	return (0);
}
