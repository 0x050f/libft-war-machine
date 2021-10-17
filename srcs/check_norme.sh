# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_norme.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:26:23 by jtoty             #+#    #+#              #
#    Updated: 2017/01/23 18:26:24 by jtoty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

check_norme()
{
	printf "$> norminette ${1} | grep -E '(Error|Warning)'\n" >>"${PATH_DEEPTHOUGHT}"/deepthought
 	printf "\033[${NORME_COL}G"
	NORME_VAR=$(norminette "${PATH_LIBFT}"/$1 2>&1)
	if echo "$NORME_VAR" | grep -q command
	then
		printf "${COLOR_WARNING}not found${DEFAULT}"
		printf "\nnorminette : command not found\n\n" >>"${PATH_DEEPTHOUGHT}"/deepthought
		retvalue=1
	elif echo "$NORME_VAR" | grep -qE '(Error|Warning)'
	then
		printf "${COLOR_FAIL}check failed${DEFAULT}"
		echo "$NORME_VAR" | grep -E '(Error|Warning)' >> "${PATH_DEEPTHOUGHT}"/deepthought 2>&1
		printf "Norme check failed\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
		retvalue=0
	else
		printf "${COLOR_OK}ok${DEFAULT}"
		retvalue=1
	fi
	return $retvalue
}
