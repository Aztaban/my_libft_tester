#ifndef UTILS_H
# define UTILS_H
# define _GNU_SOURCE

#include <stdio.h>
#include "../../libft/libft.h"
#include <ctype.h>
#include <string.h>
#include <bsd/string.h>
#include <unistd.h>

typedef struct {
	const char *name;
	void (*func)(void);
} TestCategory;

void	print_result(const char *desc, int passed);
void	print_line(void);
void	run_char_tests(void);
void	run_string_tests(void);
void	run_memory_tests(void);
void	run_conversion_tests(void);
void	run_fd_tests(void);

#endif