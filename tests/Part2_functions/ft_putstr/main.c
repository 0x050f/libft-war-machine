/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:31:08 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:52:18 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_putstr("lorem ipsum dolor sit amet");
	else if (arg == 2)
		ft_putstr("  lorem\nipsum\rdolor\tsit amet  ");
	else if (arg == 3)
		ft_putstr("");
	else if (arg == 4)
		ft_putstr("lorem ipsum do\0lor sit amet");
	return (0);
}
