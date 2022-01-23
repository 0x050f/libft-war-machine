# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    diff_test.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:26:48 by jtoty             #+#    #+#              #
#    Updated: 2022/01/22 17:48:18 by fsoares-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

diff_test()
{
	printf "\033[${TEST_COL}G"
	let "k=1"
	cd "${PATH_TEST}"/tests/$(echo ${part}tions)/$(echo $1 | cut -d . -f 1 | sed 's/_bonus//g')
	kmax=$(ls -l *.output | wc -l)
	cd "${PATH_TEST}"
	retvalue=1
	while [ $k -le $kmax ]
	do
		text="= Test $k "
		printf "${text}" >> "${PATH_DEEPTHOUGHT}"/deepthought
		printf "%.s=" $(seq 1 $(( 60 - ${#text} ))) >> "${PATH_DEEPTHOUGHT}"/deepthought
		printf "\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
		if [ $k -lt 10 ]
		then
			text="0"
		else
			text=""
		fi
		printf "$> ./user_exe ${text}$k\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
		if [ $(( $k%2 )) -eq 1 ] && ([ $1 == "ft_putchar_fd.c" ] || [ $1 == "ft_putstr_fd.c" ] || [ $1 == "ft_putendl_fd.c" ] || [ $1 == "ft_putnbr_fd.c" ])
		then
			#"${PATH_TEST}"/user_exe $k > "${PATH_TEST}"/tests/$(echo ${part}tions)/$(echo $1 | cut -d . -f 1)/user_output_test${text}$k 2>&1
			"${PATH_TEST}"/user_exe $k > /dev/null 2> "${PATH_TEST}"/tests/$(echo ${part}tions)/$(echo $1 | cut -d . -f 1 | sed 's/_bonus//g')/user_output_test${text}$k
		else
			"${PATH_TEST}"/user_exe $k > "${PATH_TEST}"/tests/$(echo ${part}tions)/$(echo $1 | cut -d . -f 1 | sed 's/_bonus//g')/user_output_test${text}$k
		fi
		SIG=$?
		if [ $SIG -eq 134 ]
		then
			printf "Command './user_exe ${text}$k' got killed by an Abort\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
			printf "${COLOR_FAIL}A${DEFAULT}"
			retvalue=0
		elif [ $SIG -eq 138 ]
		then
			printf "Command './user_exe ${text}$k' got killed by a Bus error\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
			printf "${COLOR_FAIL}B${DEFAULT}"
			retvalue=0
		elif [ $SIG -eq 139 ]
		then
			printf "Command './user_exe ${text}$k' got killed by a Segmentation fault\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
			printf "${COLOR_FAIL}S${DEFAULT}"
			retvalue=0
		elif [ $SIG -eq 142 ]
		then
			printf "Command './user_exe ${text}$k' got killed by a Timeout\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
			printf "${COLOR_FAIL}T${DEFAULT}"
			retvalue=0
		else
			DIFF=$(diff -U 3 "${PATH_TEST}"/tests/$(echo ${part}tions)/$(echo $1 | cut -d . -f 1 | sed 's/_bonus//g')/user_output_test${text}$k "${PATH_TEST}"/tests/$(echo ${part}tions)/$(echo $1 | cut -d  . -f 1 | sed 's/_bonus//g')/test${text}$k.output)
			printf "$> diff -U 3 user_output_test${text}$k test${text}$k.output\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
			if [ "$DIFF" != "" ] || [ ! -e "${PATH_TEST}"/tests/$(echo ${part}tions)/$(echo $1 | cut -d . -f 1 | sed 's/_bonus//g')/user_output_test${text}$k ]
			then
				#diff -U 3 "${PATH_TEST}"/tests/$(echo ${part}tions)/$(echo $1 | cut -d . -f 1)/user_output_test${text}$k "${PATH_TEST}"/tests/$(echo ${part}tions)/$(echo $1 | cut -d  . -f 1)/test${text}$k.output | cat -e >> "${PATH_DEEPTHOUGHT}"/deepthought
				echo "${DIFF}" | cat -e >> "${PATH_DEEPTHOUGHT}"/deepthought
				printf "\nDiff KO :(\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
				retvalue=0
				printf "${COLOR_FAIL}✗${DEFAULT}"
			else
				printf "\nDiff OK :D\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
				printf "${COLOR_OK}✓${DEFAULT}"
			fi
		fi
		#if [ -e "${PATH_TEST}"/tests/$(echo ${part}tions)/$(echo $1 | cut -d . -f 1)/user_output_test${text}$k ]
		#then
		#	rm -f "${PATH_TEST}"/tests/$(echo ${part}tions)/$(echo $1 | cut -d . -f 1)/user_output_test${text}$k
		#fi
		let "k += 1"
	done
	return $retvalue
}
