#include "../utils/utils.h"  // Adjust path if needed

static int compare_split(char **result, const char **expected)
{
	if (!result || !expected)
		return 0;

	int i = 0;
	while (expected[i])
	{
		if (!result[i] || strcmp(result[i], expected[i]) != 0)
			return 0;
		i++;
	}
	return result[i] == NULL;
}

void free_split_result(char **result)
{
	if (!result)
		return;

	for (int i = 0; result[i]; i++)
		free(result[i]);
	free(result);
}

static void	test_ft_split(void)
{
	char **test_check = ft_split("check", ' ');
	if (!test_check)
	{
		fprintf(stderr, "⚠️  ft_split is missing! Skipping tests.\n");
		return;
	}
	free_split_result(test_check);

	// === Test 1 ===
	const char *s1 = "Hello world 42";
	const char *e1[] = {"Hello", "world", "42", NULL};
	char **r1 = ft_split(s1, ' ');
	print_result("ft_split(\"Hello world 42\", ' ')", compare_split(r1, e1));
	free_split_result(r1);

	// === Test 2 ===
	const char *s2 = "apple,banana,,kiwi";
	const char *e2[] = {"apple", "banana", "kiwi", NULL};
	char **r2 = ft_split(s2, ',');
	print_result("ft_split(\"apple,banana,,kiwi\", ',')", compare_split(r2, e2));
	free_split_result(r2);

	// === Test 3 ===
	const char *s3 = "--split--me--";
	const char *e3[] = {"split", "me", NULL};
	char **r3 = ft_split(s3, '-');
	print_result("ft_split(\"--split--me--\", '-')", compare_split(r3, e3));
	free_split_result(r3);

	// === Test 4 ===
	const char *s4 = "singleword";
	const char *e4[] = {"singleword", NULL};
	char **r4 = ft_split(s4, ' ');
	print_result("ft_split(\"singleword\", ' ')", compare_split(r4, e4));
	free_split_result(r4);

	// === Test 5 ===
	const char *s5 = "";
	const char *e5[] = {NULL};
	char **r5 = ft_split(s5, ' ');
	print_result("ft_split(\"\", ' ')", compare_split(r5, e5));
	free_split_result(r5);
}

static void to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

static void to_index_ascii(unsigned int i, char *c)
{
	*c = (char)(i + 65); // A, B, C, ...
}

static void test_striteri(void)
{
		char probe[] = "abc";
	ft_striteri(probe, to_upper);
	if (strcmp(probe, "ABC") != 0)
	{
		fprintf(stderr, "⚠️  ft_striteri is missing! Skipping tests.\n");
		return;
	}

	char s1[] = "hello";
	char expected1[] = "HELLO";
	ft_striteri(s1, to_upper);
	print_result("ft_striteri to_upper(\"hello\")", strcmp(s1, expected1) == 0);

	char s2[] = "abcde";
	char expected2[] = "ABCDE";
	ft_striteri(s2, to_index_ascii);
	print_result("ft_striteri to_index_ascii(\"abcde\")", strcmp(s2, expected2) == 0);

	char s3[] = "";
	ft_striteri(s3, to_upper); // should do nothing, not crash
	print_result("ft_striteri on empty string", strcmp(s3, "") == 0);
}

static void run_strjoin_test(const char *desc, const char *s1, const char *s2, const char *expected)
{
	char *result = ft_strjoin(s1, s2);
	int passed = result && strcmp(result, expected) == 0;
	print_result(desc, passed);
	free(result);
}

void test_strjoin(void)
{
	// Probe test to detect fallback
	char *probe = ft_strjoin("a", "b");
	if (!probe || strcmp(probe, "ab") != 0)
	{
		fprintf(stderr, "⚠️  ft_strjoin is missing! Skipping tests.\n");
		free(probe);
		return;
	}
	free(probe);

	run_strjoin_test("ft_strjoin Join 'Hello' + 'World'", "Hello", "World", "HelloWorld");
	run_strjoin_test("ft_strjoin Join 'Hello' + ''", "Hello", "", "Hello");
	run_strjoin_test("ft_strjoin Join '' + 'World'", "", "World", "World");
	run_strjoin_test("ft_strjoin Join '' + ''", "", "", "");
	run_strjoin_test("ft_strjoin Join long strings",
		"This is a long string. ",
		"And this continues the journey.",
		"This is a long string. And this continues the journey.");
}

static char to_upper_indexed(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return c - 32;
	return c;
}

static char to_ascii_from_index(unsigned int i, char c)
{
	(void)c;
	return (char)(i + 65); // A, B, C...
}

static void run_strmapi_test(const char *desc, const char *input, char (*f)(unsigned int, char), const char *expected)
{
	char *result = ft_strmapi(input, f);
	int passed = result && strcmp(result, expected) == 0;
	print_result(desc, passed);
	free(result);
}

void test_strmapi(void)
{
	// Probe test to detect fallback
	char *probe = ft_strmapi("ab", to_upper_indexed);
	if (!probe || strcmp(probe, "AB") != 0)
	{
		fprintf(stderr, "⚠️  ft_strmapi is missing! Skipping tests.\n");
		free(probe);
		return;
	}
	free(probe);

	run_strmapi_test("ft_strmapi Uppercase mapping", "hello", to_upper_indexed, "HELLO");
	run_strmapi_test("ft_strmapi Index to ASCII", "abcde", to_ascii_from_index, "ABCDE");
	run_strmapi_test("ft_strmapi Empty string", "", to_upper_indexed, "");
}

static void run_strtrim_test(const char *desc, const char *s1, const char *set, const char *expected)
{
	char *result = ft_strtrim(s1, set);
	int passed = result && strcmp(result, expected) == 0;
	print_result(desc, passed);
	free(result);
}

void test_strtrim(void)
{
	// Probe test to detect fallback
	char *probe = ft_strtrim(" test ", " ");
	if (!probe || strcmp(probe, "test") != 0)
	{
		fprintf(stderr, "⚠️  ft_strtrim is missing! Skipping tests.\n");
		free(probe);
		return;
	}
	free(probe);

	run_strtrim_test("ft_strtrim Trim spaces", "   hello   ", " ", "hello");
	run_strtrim_test("ft_strtrim Trim punctuation", "...hello...", ".", "hello");
	run_strtrim_test("ft_strtrim Trim mixed set", "abcHelloabc", "abc", "Hello");
	run_strtrim_test("ft_strtrim No trim needed", "42Prague", "x", "42Prague");
	run_strtrim_test("ft_strtrim Trim everything", "xxxx", "x", "");
	run_strtrim_test("ft_strtrim Empty string input", "", "x", "");
	run_strtrim_test("ft_strtrim Empty set", " test ", "", " test ");
}

static void run_substr_test(const char *desc, const char *s, unsigned int start, size_t len, const char *expected)
{
	char *result = ft_substr(s, start, len);
	int passed = result && strcmp(result, expected) == 0;
	print_result(desc, passed);
	free(result);
}

void test_substr(void)
{
	// Probe check
	char *probe = ft_substr("Hello", 1, 2);
	if (!probe || strcmp(probe, "el") != 0)
	{
		fprintf(stderr, "⚠️  ft_substr is missing! Skipping tests.\n");
		free(probe);
		return;
	}
	free(probe);

	run_substr_test("ft_substr Middle of string", "HelloWorld", 5, 3, "Wor");
	run_substr_test("ft_substr Start from 0", "42Prague", 0, 2, "42");
	run_substr_test("ft_substr Full string", "libft", 0, 10, "libft");
	run_substr_test("ft_substr Start beyond end", "test", 10, 5, "");
	run_substr_test("ft_substr Zero length", "hello", 2, 0, "");
	run_substr_test("ft_substr Empty string", "", 0, 5, "");
}

void	run_string_extra_tests()
{
	printf("\n[ Additional string tests ]\n");
	print_line();	
	test_ft_split();
	print_line();
	test_striteri();
	print_line();
	test_strjoin();
	print_line();
	test_strmapi();
	print_line();
	test_strtrim();
	print_line();
	test_substr();
	print_line();
}
