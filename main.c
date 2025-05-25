/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:14:16 by mjusta            #+#    #+#             */
/*   Updated: 2025/05/25 23:21:20 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils/utils.h"

void	run_char_tests(void);
void	run_string_tests(void);
void	run_memory_tests(void);
void	run_conversion_tests(void);

int	main(int argc, char **argv)
{
	printf("\n---------------- libft Functions Testser ---------------\n");
	print_line();
	
	if (argc > 1)
	{
		if (strcmp(argv[1], "char") == 0)
			run_char_tests();
		else if (strcmp(argv[1], "string") == 0)
			run_string_tests();
		else if (strcmp(argv[1], "memory") == 0)
			run_memory_tests();
		else if (strcmp(argv[1], "conversion") == 0)
			run_conversion_tests();
	}
	else
	{
		run_char_tests();
		run_string_tests();
		run_memory_tests();
		run_conversion_tests();
	}
	printf("\n");
	print_line();
	return (0);
}
