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

static void	test_strchr(void)
{
	run_strchr_test("ft_strchr(\"hello\", 'e')", "hello", 'e');
	run_strchr_test("ft_strchr(\"hello\", 'l')", "hello", 'l');
	run_strchr_test("ft_strchr(\"hello\", 'o')", "hello", 'o');
	run_strchr_test("ft_strchr(\"hello\", '\\0')", "hello", '\0');
	run_strchr_test("ft_strchr(\"hello\", 'z')", "hello", 'z');
}

static void	test_strrchr(void)
{
	run_strrchr_test("ft_strrchr(\"hello\", 'l')", "hello", 'l');
	run_strrchr_test("ft_strrchr(\"hello\", 'o')", "hello", 'o');
	run_strrchr_test("ft_strrchr(\"hello\", '\\0')", "hello", '\0');
	run_strrchr_test("ft_strrchr(\"hello\", 'z')", "hello", 'z');
	run_strrchr_test("ft_strrchr(\"hellohello\", 'l')", "hellohello", 'l');
}

static void run_strncmp_test(const char *desc, const char *s1, const char *s2, size_t n) {
	int std = strncmp(s1, s2, n);
	int ft = ft_strncmp(s1, s2, n);
	print_result(desc, (std == 0 && ft == 0) || (std < 0 && ft < 0) || (std > 0 && ft > 0));
}

static void test_strncmp(void) {
	run_strncmp_test("ft_strncmp: equal strings", "hello", "hello", 5);
	run_strncmp_test("ft_strncmp: equal strings, short n", "hello", "hello", 2);
	run_strncmp_test("ft_strncmp: different at end", "hello", "helLo", 5);
	run_strncmp_test("ft_strncmp: first is shorter", "abc", "abcd", 4);
	run_strncmp_test("ft_strncmp: second is shorter", "abcd", "abc", 4);
	run_strncmp_test("ft_strncmp: empty vs non-empty", "", "abc", 3);
	run_strncmp_test("ft_strncmp: non-empty vs empty", "abc", "", 3);
	run_strncmp_test("ft_strncmp: both empty", "", "", 1);
	run_strncmp_test("ft_strncmp: n = 0", "abc", "xyz", 0);
	run_strncmp_test("ft_strncmp: long identical prefix", "libft42", "libft42test", 6);
}

static void run_strnstr_test(const char *desc, const char *haystack, const char *needle, size_t len)
{
	char *std = strnstr(haystack, needle, len);
	char *ft = ft_strnstr(haystack, needle, len);
	print_result(desc, std == ft || (std && ft && strcmp(std, ft) == 0));
}

static void test_strnstr(void)
{
	run_strnstr_test("ft_strnstr: found inside range", "Hello, 42Prague!", "42", 15);
	run_strnstr_test("ft_strnstr: not found (needle out of range)", "Hello, 42Prague!", "42", 5);
	run_strnstr_test("ft_strnstr: partial match only", "abcdef", "cdg", 6);
	run_strnstr_test("ft_strnstr: full match just fits", "abcdef", "def", 6);
	run_strnstr_test("ft_strnstr: needle is empty", "abcdef", "", 3);
	run_strnstr_test("ft_strnstr: haystack is empty", "", "abc", 5);
	run_strnstr_test("ft_strnstr: both empty", "", "", 2);
	run_strnstr_test("ft_strnstr: len is 0", "abcdef", "abc", 0);
	run_strnstr_test("ft_strnstr: exact match, full length", "abc", "abc", 3);
	run_strnstr_test("ft_strnstr: needle longer than haystack", "abc", "abcdef", 5);
}

static void run_strdup_test(const char *desc, const char *input)
{
	char *ft = ft_strdup(input);
	int passed = (ft != NULL && strcmp(ft, input) == 0);

	print_result(desc, passed);
	free(ft);
}

static void test_strdup(void)
{
	run_strdup_test("ft_strdup: basic", "libft");
	run_strdup_test("ft_strdup: empty string", "");
	run_strdup_test("ft_strdup: special chars", "42!@#\t\n");
	run_strdup_test("ft_strdup: long string", "This is a longer test string with lots of characters.");
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
	test_strncmp();
	print_line();
	test_strnstr();
	print_line();
	test_strdup();
	print_line();
}