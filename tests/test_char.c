#include "../utils/utils.h"

static void	run_char_test(const char *desc, int (*ft_func)(int), int (*std_func)(int), int input)
{
	int result = ft_func(input) == !!std_func(input); // normalize std_func result
	print_result(desc, result);
}

static void	test_isalpha(void)
{
	run_char_test("ft_isalpha('a')", ft_isalpha, isalpha, 'a');
	run_char_test("ft_isalpha('Z')", ft_isalpha, isalpha, 'Z');
	run_char_test("ft_isalpha('1')", ft_isalpha, isalpha, '1');
	run_char_test("ft_isalpha('%')", ft_isalpha, isalpha, '%');
}

static void	test_isdigit(void)
{
	run_char_test("ft_isdigit('0')", ft_isdigit, isdigit, '0');
	run_char_test("ft_isdigit('5')", ft_isdigit, isdigit, '5');
	run_char_test("ft_isdigit('a')", ft_isdigit, isdigit, 'a');
	run_char_test("ft_isdigit('@')", ft_isdigit, isdigit, '@');
}

static void	test_isalnum(void)
{
	run_char_test("ft_isalnum('0')", ft_isalnum, isalnum, '0');
	run_char_test("ft_isalnum('C')", ft_isalnum, isalnum, 'C');
	run_char_test("ft_isalnum(' ')", ft_isalnum, isalnum, ' ');
	run_char_test("ft_isalnum('@')", ft_isalnum, isalnum, '@');
}

static void	test_isascii(void)
{
	run_char_test("ft_isascii(48)", ft_isascii, isascii, 48);
	run_char_test("ft_isascii(200)", ft_isascii, isascii, 200);
	run_char_test("ft_isascii(0)", ft_isascii, isascii, 0);
	run_char_test("ft_isascii(127)", ft_isascii, isascii, 127);
}

static void	test_isprint(void)
{
	run_char_test("ft_isprint('a')", ft_isprint, isprint, 'a');
	run_char_test("ft_isprint(' ')", ft_isprint, isprint, ' ');
	run_char_test("ft_isprint('0')", ft_isprint, isprint, '0');
	run_char_test("ft_isprint('\\n')", ft_isprint, isprint, '\n');
}

void    run_char_tests(void)
{   
    printf("\n[ Character tests ]\n");
    print_line();
	test_isalpha();
	print_line();
	test_isdigit();
	print_line();
	test_isalnum();
	print_line();
	test_isascii();	
	print_line();
	test_isprint();
	print_line();
}