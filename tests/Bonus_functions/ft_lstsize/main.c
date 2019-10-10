/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:26:40 by lmartin           #+#    #+#             */
/*   Updated: 2019/10/09 14:26:42 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../../libft.h"
#include <unistd.h>
#include <string.h>

t_list	*ft_lstnewone(void const *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (!content)
	{
		elem->content = NULL;
	}
	else
	{
		if (!(elem->content = malloc(sizeof(*(elem->content)) * sizeof(content))))
			return (NULL);
		elem->content = memcpy(elem->content, content, sizeof(content));
	}
	elem->next = NULL;
	return (elem);
}

int main(int argc, const char *argv[])
{
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		c;

	char		str [] = "lorem";
	char		str2 [] = "ipsum";
	char		str3 [] = "dolor";
	char		str4 [] = "sit";

	elem = ft_lstnewone(str);
	elem2 = ft_lstnewone(str2);
	elem3 = ft_lstnewone(str3);
	elem4 = ft_lstnewone(str4);
	alarm(5);
	if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		elem->next = elem2;
		elem2->next = elem3;
		elem3->next = elem4;
		c = ft_lstsize(elem) + 48;
		write(1, &c, 1);
		write(1, "\n", 1);
		elem->next = NULL;
		c = ft_lstsize(elem) + 48;
		write(1, &c, 1);
		write(1, "\n", 1);
		elem = NULL;
		c = ft_lstsize(elem) + 48;
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	return (0);
}
