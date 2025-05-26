#include "../utils/utils.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

static void test_putchar_fd_case(char c, const char *expected, const char *desc)
{
	int saved_stdout = dup(STDOUT_FILENO);
	int fd = open("test_out.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);

	ft_putchar_fd(c, 1);
	fflush(stdout);

	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	close(fd);

	FILE *file = fopen("test_out.txt", "r");
	char buf[8] = {0};
	if (file)
	{
		fread(buf, 1, sizeof(buf) - 1, file);
		fclose(file);
	}
	print_result(desc, strcmp(buf, expected) == 0);
}

static void test_putchar_fd(void)
{
	test_putchar_fd_case('A', "A", "ft_putchar_fd('A')");
	test_putchar_fd_case('\n', "\n", "ft_putchar_fd('\\n')");
	test_putchar_fd_case(' ', " ", "ft_putchar_fd(' ')");
	test_putchar_fd_case('0', "0", "ft_putchar_fd('0')");
	test_putchar_fd_case('@', "@", "ft_putchar_fd('@')");
}

static void test_putstr_fd_case(const char *input, const char *expected, const char *desc)
{
	int saved_stdout = dup(STDOUT_FILENO);
	int fd = open("test_out.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);

	ft_putstr_fd((char *)input, 1);  // cast to discard const
	fflush(stdout);

	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	close(fd);

	FILE *file = fopen("test_out.txt", "r");
	char buf[128] = {0};
	if (file)
	{
		fread(buf, 1, sizeof(buf) - 1, file);
		fclose(file);
	}
	print_result(desc, strcmp(buf, expected) == 0);
}

static void test_putstr_fd(void)
{
	test_putstr_fd_case("Hello", "Hello", "ft_putstr_fd(\"Hello\")");
	test_putstr_fd_case("", "", "ft_putstr_fd(\"\")");
	test_putstr_fd_case(NULL, "", "ft_putstr_fd(NULL)");
	test_putstr_fd_case("42Prague", "42Prague", "ft_putstr_fd(\"42Prague\")");
}

static void test_putendl_fd_case(const char *input, const char *expected, const char *desc)
{
	int saved_stdout = dup(STDOUT_FILENO);
	int fd = open("test_out.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);

	ft_putendl_fd((char *)input, 1);
	fflush(stdout);

	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	close(fd);

	FILE *file = fopen("test_out.txt", "r");
	char buf[128] = {0};
	if (file)
	{
		fread(buf, 1, sizeof(buf) - 1, file);
		fclose(file);
	}
	print_result(desc, strcmp(buf, expected) == 0);
}

static void test_putendl_fd(void)
{
	test_putendl_fd_case("Line", "Line\n", "ft_putendl_fd(\"Line\")");
	test_putendl_fd_case("", "\n", "ft_putendl_fd(\"\")");
	test_putendl_fd_case(NULL, "", "ft_putendl_fd(NULL)");
	test_putendl_fd_case("Test42", "Test42\n", "ft_putendl_fd(\"Test42\")");
}

static void test_putnbr_fd_case(int input, const char *expected, const char *desc)
{
	int saved_stdout = dup(STDOUT_FILENO);
	int fd = open("test_out.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);

	ft_putnbr_fd(input, 1);
	fflush(stdout);

	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	close(fd);

	FILE *file = fopen("test_out.txt", "r");
	char buf[64] = {0};
	if (file)
	{
		fread(buf, 1, sizeof(buf) - 1, file);
		fclose(file);
	}
	print_result(desc, strcmp(buf, expected) == 0);
}

static void test_putnbr_fd(void)
{
	test_putnbr_fd_case(0, "0", "ft_putnbr_fd(0)");
	test_putnbr_fd_case(42, "42", "ft_putnbr_fd(42)");
	test_putnbr_fd_case(-42, "-42", "ft_putnbr_fd(-42)");
	test_putnbr_fd_case(1, "1", "ft_putnbr_fd(1)");
	test_putnbr_fd_case(-1, "-1", "ft_putnbr_fd(-1)");
	test_putnbr_fd_case(1234567890, "1234567890", "ft_putnbr_fd(1234567890)");
	test_putnbr_fd_case(INT_MAX, "2147483647", "ft_putnbr_fd(INT_MAX)");
	test_putnbr_fd_case(INT_MIN, "-2147483648", "ft_putnbr_fd(INT_MIN)");
}

void run_fd_tests(void)
{
	printf("\n[ FD output tests ]\n");
	print_line();
	test_putchar_fd();
	print_line();
	test_putstr_fd();
	print_line();
	test_putendl_fd();
	print_line();
	test_putnbr_fd();
	print_line();
}
