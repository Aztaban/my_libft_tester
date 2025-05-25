#include "../utils/utils.h"

static void run_toupper_test(const char *desc, int c) {
	int std = toupper(c);
	int ft = ft_toupper(c);
	print_result(desc, std == ft);
}

static void run_tolower_test(const char *desc, int c) {
	int std = tolower(c);
	int ft = ft_tolower(c);
	print_result(desc, std == ft);
}

static void run_atoi_test(const char *desc, const char *input) {
	int std = atoi(input);
	int ft = ft_atoi(input);
	print_result(desc, std == ft);
}

static void	test_toupper(void)
{
	run_toupper_test("ft_toupper('a')", 'a');
	run_toupper_test("ft_toupper('Z')", 'Z');
	run_toupper_test("ft_toupper('A')", 'A');
	run_toupper_test("ft_toupper('!')", '!');
	run_toupper_test("ft_toupper('1')", '1');
	run_toupper_test("ft_toupper(130)", 130);
}

static void	test_tolower(void)
{
	run_tolower_test("ft_tolower('a')", 'a');
	run_tolower_test("ft_tolower('Z')", 'Z');
	run_tolower_test("ft_tolower('A')", 'A');
	run_tolower_test("ft_tolower('!')", '!');
	run_tolower_test("ft_tolower('1')", '1');
	run_tolower_test("ft_tolower(130)", 130);
}

static void	test_atoi(void)
{
	run_atoi_test("ft_atoi(\"42\")", "42");
	run_atoi_test("ft_atoi(\"+42\")", "+42");
	run_atoi_test("ft_atoi(\"-42\")", "-42");
	run_atoi_test("ft_atoi(\"   42\")", "   42");
	run_atoi_test("ft_atoi(\"   -42\")", "   -42");
	run_atoi_test("ft_atoi(\"0042\")", "0042");
	run_atoi_test("ft_atoi(\"-0042\")", "-0042");
	run_atoi_test("ft_atoi(\"2147483647\")", "2147483647");
	run_atoi_test("ft_atoi(\"-2147483648\")", "-2147483648");
	run_atoi_test("ft_atoi(\"abc42\")", "abc42");
	run_atoi_test("ft_atoi(\"42abc\")", "42abc");
	run_atoi_test("ft_atoi(\"\")", "");
	run_atoi_test("ft_atoi(\"   -4242 42 42\")", "   -4242 42 42");
	run_atoi_test("ft_atoi(\"   -+-42424242\")", "   -+-42424242");
	run_atoi_test("ft_atoi(\"   214748364788\")", "   214748364788");
	run_atoi_test("ft_atoi(\"   -214748364788\")", "   -214748364788");
	run_atoi_test("ft_atoi(\"\\t\\n\\v\\f\\r +0424242\")", "\t\n\v\f\r +0424242");
	run_atoi_test("ft_atoi(\"   +0 424242\")", "   +0 424242");
}

void    run_conversion_tests(void)
{   
    printf("\n[ Conversion tests ]\n");
    print_line();
	test_toupper();
	print_line();
	test_tolower();
	print_line();
	test_atoi();
	print_line();
}