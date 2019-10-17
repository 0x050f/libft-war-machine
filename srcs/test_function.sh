# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_function.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:27:09 by jtoty             #+#    #+#              #
#    Updated: 2019/10/17 20:51:04 by xinwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

check_turned_in_file()
{
	source ${PATH_TEST}/my_config.sh
	text="= $1 "
	printf "\n${text}" >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "%.s=" $(seq 1 $(( 80 - ${#text} ))) >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "\n" >> ${PATH_DEEPTHOUGHT}/deepthought

	if [ -e ${PATH_LIBFT}/${SRC_DIR}/$1 ]
	then
		retvalue=1
		return "$retvalue"
	else
		printf "\033[${NORME_COL}G"
		printf "${COLOR_FAIL}NTI${DEFAULT}"
		printf "\033[${CHEAT_COL}G"
		printf "${COLOR_FAIL}NTI${DEFAULT}"
		printf "\033[${COMPIL_COL}G"
		printf "${COLOR_FAIL}NTI${DEFAULT}"
		printf "\033[${TEST_COL}G"
		printf "${COLOR_FAIL}NTI${DEFAULT}"
		printf "\033[${RESULT_COL}G"
		printf "${COLOR_FAIL}NTI${DEFAULT}\n"
		printf "Nothing turned in\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		retvalue=0
		return "$retvalue"
	fi
}


test_function()
{
	printf "\n${COLOR_PART}$(echo ${part} | cut -d _ -f 1) functions\n\n"
	printf "${COLOR_TITLE}"
	printf "FUNCTION"
	printf "\033[${NORME_COL}GNORME"
	printf "\033[${CHEAT_COL}GFORBIDDEN FUNC."
	printf "\033[${COMPIL_COL}GCOMPIL."
	printf "\033[${TEST_COL}GTESTS"
	printf "\033[${RESULT_COL}GRESULT\n${DEFAULT}"

	let	"i=0"
	let	"success=0"
	let	"total=0"
	for function in ${!1}
	do
		if [ $(( ${part}_activation[$i] )) -eq 1 ]
		then
		let	"total += 1"
			printf "${COLOR_FUNC}"
			func_name=$(echo "$function" | cut -d . -f 1)
			printf "${func_name}"
			check_turned_in_file $function
			file=$?
			if [ $file -eq 1 ]
			then
				result=1
				if [ ${OPT_NO_NORMINETTE} -eq 0 ]
				then
					check_norme $function
					check=$?
					if [ $check -eq 0 ]
					then
						result=0
					fi
				else
					printf "\033[${NORME_COL}G${DEFAULT}disabled"
				fi
				compilation $function
				check_compilation
				check=$?
				if [ $check -eq 1 ]
				then
					if [ ${OPT_NO_FORBIDDEN} -eq 0 ]
					then
						check_cheating $function $(( ${part}_authorized[$i] ))
						check=$?
						if [ $check -eq 1 ]
						then
							result=0
						fi
					else
						printf "\033[${CHEAT_COL}G${DEFAULT}disabled"
					fi
					diff_test $function
				else
					printf "\033[${CHEAT_COL}G"
					printf "${COLOR_FAIL}compil. failed${DEFAULT}"
					printf "\033[${TEST_COL}G"
					printf "${COLOR_FAIL}compil. failed${DEFAULT}"
					result=0
				fi
				check=$?
				if [ $check -eq 0 ]
				then
					result=0
				fi
				printf "\033[${RESULT_COL}G"
				if [ $result -eq 0 ]
				then
					printf "${COLOR_FAIL}KO\n${DEFAULT}"
				else
					printf "${COLOR_OK}OK\n${DEFAULT}"
					let "success += 1"
				fi
			fi
			if [ -e ${PATH_TEST}/user_exe ]
			then
				rm -f ${PATH_TEST}/user_exe
			fi
		fi
		let	"i += 1"
	done
	printf "\n${COLOR_TOTAL}Total : ${success}/${total}${DEFAULT}\n"
}
