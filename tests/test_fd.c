#include "../utils/utils.h"
#include <fcntl.h>
#include <unistd.h>

static void test_putchar_fd(void)
{
	int saved_stdout = dup(STDOUT_FILENO);
	FILE *file = freopen("test_out.txt", "w+", stdout);
	if (!file) return;

	ft_putchar_fd('A', 1);
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);

	file = fopen("test_out.txt", "r");
	char buf[2] = {0};
	fread(buf, 1, 1, file);
	print_result("ft_putchar_fd('A')", strcmp(buf, "A") == 0);
	fclose(file);
}


static void test_putstr_fd(void)
{
	int saved_stdout = dup(STDOUT_FILENO);
	FILE *file = freopen("test_out.txt", "w+", stdout);
	if (!file) return;

	ft_putstr_fd("Hello", 1);
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);

	file = fopen("test_out.txt", "r");
	char buf[6] = {0};
	fread(buf, 1, 5, file);
	print_result("ft_putstr_fd(\"Hello\")", strcmp(buf, "Hello") == 0);
	fclose(file);
}

static void test_putendl_fd(void)
{
	int saved_stdout = dup(STDOUT_FILENO);
	FILE *file = freopen("test_out.txt", "w+", stdout);
	if (!file) return;

	ft_putendl_fd("Line", 1);
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);

	file = fopen("test_out.txt", "r");
	char buf[6] = {0};
	fread(buf, 1, 5, file);
	print_result("ft_putendl_fd(\"Line\")", strcmp(buf, "Line\n") == 0);
	fclose(file);
}

static void test_putnbr_fd(void)
{
	int saved_stdout = dup(STDOUT_FILENO);
	FILE *file = freopen("test_out.txt", "w+", stdout);
	if (!file) return;

	ft_putnbr_fd(-12345, 1);
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);

	file = fopen("test_out.txt", "r");
	char buf[12] = {0};
	fread(buf, 1, 6, file);
	print_result("ft_putnbr_fd(-12345)", strcmp(buf, "-12345") == 0);
	fclose(file);
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
