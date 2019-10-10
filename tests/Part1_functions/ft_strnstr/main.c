/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:08:05 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:48:32 by jtoty            ###   ########.fr       */
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
	const char *str;
	int			arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "lorem", 15)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 2)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 15)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 3)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit lorem ipsum dolor", "ipsum", 35)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 4)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "", 10)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 5)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 6)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dol", 30)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 7)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "consectetur", 30)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 8)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "sit", 10)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 9)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 10)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 0)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	return (0);
}
