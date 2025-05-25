#include "../utils/utils.h"

static void	test_strlen(void)
{
	print_result("ft_strlen(\"\")", ft_strlen("") == strlen(""));
	print_result("ft_strlen(\"Hello\")", ft_strlen("Hello") == strlen("Hello"));
	print_result("ft_strlen(\"This is something\")", ft_strlen("This is something") == strlen("This is something"));
	print_result("ft_strlen(\"   \")", ft_strlen("   ") == strlen("   "));
	print_result("ft_strlen(\"\\n\\t\\r\")", ft_strlen("\n\t\r") == strlen("\n\t\r"));
}

static void	run_strlcpy_test(const char *desc, const char *src, size_t dstsize)
{
	char buffer1[100], buffer2[100];
	memset(buffer1, 'X', sizeof(buffer1));
	memset(buffer2, 'X', sizeof(buffer2));

	size_t std_len = strlcpy(buffer1, src, dstsize);
	size_t ft_len = ft_strlcpy(buffer2, src, dstsize);

	int	match_result = (std_len == ft_len);
	int match_buffer = memcmp(buffer1, buffer2, sizeof(buffer1)) == 0;

	print_result(desc, (match_result && match_buffer));
}

static void	test_strlcpy(void)
{
	run_strlcpy_test("Copy fits in buffer", "hello", 10);
	run_strlcpy_test("Exact fit", "hello", 6);
	run_strlcpy_test("Truncate 1 char", "hello", 5);
	run_strlcpy_test("Zero size buffer", "hello", 0);
	run_strlcpy_test("Empty string", "", 5);
	run_strlcpy_test("Single char copy", "a", 2);
	run_strlcpy_test("Truncate long string", "longer test string", 8);
}

static void	run_strlcat_test(const char *desc, const char *init_dst, const char *src, size_t dstsize)
{
	char buffer1[100], buffer2[100];
	memset(buffer1, 'X', sizeof(buffer1));
	memset(buffer2, 'X', sizeof(buffer2));

	strlcpy(buffer1, init_dst, sizeof(buffer1));
	strlcpy(buffer2, init_dst, sizeof(buffer2));

	size_t std_len = strlcat(buffer1, src, dstsize);
	size_t ft_len = ft_strlcat(buffer2, src, dstsize);

	int	match_result = (std_len == ft_len);
	int match_buffer = memcmp(buffer1, buffer2, sizeof(buffer1)) == 0;

	print_result(desc, (match_result && match_buffer));
}

static void	test_strlcat(void)
{
	run_strlcat_test("Basic append", "Hello, ", "world!", 20);
	run_strlcat_test("Exact fit", "Hello", "World", 11);
	run_strlcat_test("Truncate src", "12345", "67890", 9);
	run_strlcat_test("Zero size", "", "nope", 0);
	run_strlcat_test("Empty src", "initial", "", 20);
	run_strlcat_test("Empty dst", "", "just me", 10);
	run_strlcat_test("No room to write", "ABCDEFGHIJK", "Z", 5);
}

static void	run_strchr_test(const char *desc, const char *s, int c)
{
	char *std = strchr(s, c);
	char *ft = ft_strchr(s, c);
	print_result(desc, std == ft || (std && ft && strcmp(std, ft) == 0));
}

static void	run_strrchr_test(const char *desc, const char *s, int c)
{
	char *std = strrchr(s, c);
	char *ft = ft_strrchr(s, c);
	print_result(desc, std == ft || (std && ft && strcmp(std, ft) == 0));
}

void	test_strchr(void)
{
	run_strchr_test("ft_strchr(\"hello\", 'e')", "hello", 'e');
	run_strchr_test("ft_strchr(\"hello\", 'l')", "hello", 'l');
	run_strchr_test("ft_strchr(\"hello\", 'o')", "hello", 'o');
	run_strchr_test("ft_strchr(\"hello\", '\\0')", "hello", '\0');
	run_strchr_test("ft_strchr(\"hello\", 'z')", "hello", 'z');
}

void	test_strrchr(void)
{
	run_strrchr_test("ft_strrchr(\"hello\", 'l')", "hello", 'l');
	run_strrchr_test("ft_strrchr(\"hello\", 'o')", "hello", 'o');
	run_strrchr_test("ft_strrchr(\"hello\", '\\0')", "hello", '\0');
	run_strrchr_test("ft_strrchr(\"hello\", 'z')", "hello", 'z');
	run_strrchr_test("ft_strrchr(\"hellohello\", 'l')", "hellohello", 'l');
}

void    run_string_tests(void)
{   
    printf("\n[ String tests ]\n");
    print_line();
	test_strlen();
	print_line();
	test_strlcpy();
	print_line();
	test_strlcat();
	print_line();
	test_strchr();
	print_line();
	test_strrchr();
	print_line();
}