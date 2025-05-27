/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:14:16 by mjusta            #+#    #+#             */
/*   Updated: 2025/05/27 19:14:45 by mjusta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils/utils.h"

void	print_usage(void)
{
	printf("Usage: ./libftester [category]\n");
	printf("Available categories:\n");
	printf("  char        - Character-related functions\n");
	printf("  string      - String manipulation functions\n");
	printf("  memory      - Memory manipulation functions\n");
	printf("  conversion  - Type conversion functions\n");
	printf("  fd          - File descriptor output functions\n");
	printf("  string++    - Additional string manipulation functions\n");
	printf("No argument runs all tests.\n");
}

int	main(int argc, char **argv)
{
	TestCategory categories[] = {
		{"use", print_usage},
		{"char", run_char_tests},
		{"string", run_string_tests},
		{"memory", run_memory_tests},
		{"conversion", run_conversion_tests},
		{"fd", run_fd_tests},
		{"string++", run_string_extra_tests}
	};
	const int num_categories = sizeof(categories) / sizeof(TestCategory);

	printf("\n---------------- libft Functions Tester ----------------\n");
	print_line();

	if (argc > 1)
	{
		int i = 1;
		while (i < argc)
		{
			int matched = 0;
			int j = 0;
			while (j < num_categories)
			{
				if (strcmp(argv[i], categories[j].name) == 0)
				{
					categories[j].func();
					matched = 1;
					break;
				}
				j++;
			}
			if (!matched)
			{
				printf("Warning: Unknown category '%s'\n", argv[i]);
				print_usage();
			}
			i++;
		}
	}
	else
	{
		int i = 0;
		while (i < num_categories)
		{
			categories[i].func();
			i++;
		}
	}

	printf("\n");
	print_line();
	return (0);
}
