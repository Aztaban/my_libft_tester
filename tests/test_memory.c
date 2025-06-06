#include "../utils/utils.h"

static void	test_memset(void)
{
	unsigned char buf1[20];
	unsigned char buf2[20];

	ft_memset(buf1, 'A', 10);
	memset(buf2, 'A', 10);
	print_result("ft_memset 10 bytes to 'A'", memcmp(buf1, buf2, 10) == 0);

	ft_memset(buf1, 0x00, 20);
	memset(buf2, 0x00, 20);
	print_result("ft_memset 20 bytes to 0x00", memcmp(buf1, buf2, 20) == 0);

	ft_memset(buf1, 255, 5);
	memset(buf2, 255, 5);
	print_result("ft_memset first 5 bytes to 255", memcmp(buf1, buf2, 5) == 0);

	ft_memset(buf1, 'X', 0);
	memset(buf2, 'X', (size_t)0);
	print_result("ft_memset 0 bytes (n = 0)", memcmp(buf1, buf2, 20) == 0);
}

static void	test_bzero(void)
{
    char buf1[10] = "123456789";
    char buf2[10] = "123456789";

    ft_bzero(buf1, 5);
    bzero(buf2, 5);
    print_result("ft_bzero 5 bytes", memcmp(buf1, buf2, 10) == 0);
}

static void	test_memcpy(void)
{
	int passed;

	// Test 1: Basic string copy
	char src1[] = "42PragueLibft";
	char dest_std1[20];
	char dest_ft1[20];

	memcpy(dest_std1, src1, sizeof(src1));
	ft_memcpy(dest_ft1, src1, sizeof(src1));

	passed = memcmp(dest_std1, dest_ft1, sizeof(src1)) == 0;
	print_result("ft_memcpy Basic string copy", passed);

	// Test 2: Binary data (int array)
	int src2[] = {1, 2, 3, 4, 5};
	int dest_std2[5];
	int dest_ft2[5];

	memcpy(dest_std2, src2, sizeof(src2));
	ft_memcpy(dest_ft2, src2, sizeof(src2));

	passed = memcmp(dest_std2, dest_ft2, sizeof(src2)) == 0;
	print_result("ft_memcpy Binary int array copy", passed);

	// Test 3: Copy zero bytes
	char src3[] = "nothing";
	char dest_std3[] = "#######";
	char dest_ft3[] = "#######";

	memcpy(dest_std3, src3, 0);
	ft_memcpy(dest_ft3, src3, 0);

	passed = memcmp(dest_std3, dest_ft3, sizeof(dest_std3)) == 0;
	print_result("ft_memcpy Zero bytes copy", passed);

	// Test 4: Partial copy
	char src4[] = "libft42";
	char dest_std4[10] = {0};
	char dest_ft4[10] = {0};

	memcpy(dest_std4, src4, 4); // Only "libf"
	ft_memcpy(dest_ft4, src4, 4);

	passed = memcmp(dest_std4, dest_ft4, 10) == 0;
	print_result("ft_memcpy Partial string copy (4 bytes)", passed);
}

static void	test_memmove(void)
{
	int passed;

    // Test 1: Basic non-overlapping copy
    char src1[] = "Hello, world!";
    char dst_std1[20], dst_ft1[20];
    memmove(dst_std1, src1, sizeof(src1));
    ft_memmove(dst_ft1, src1, sizeof(src1));
    passed = memcmp(dst_std1, dst_ft1, sizeof(src1)) == 0;
    print_result("ft_memmove Basic non-overlapping copy", passed);

    // Test 2: Zero bytes copy
    char src2[] = "12345";
    char dst_std2[] = "XXXXX";
    char dst_ft2[] = "XXXXX";
    memmove(dst_std2, src2, 0);
    ft_memmove(dst_ft2, src2, 0);
    passed = memcmp(dst_std2, dst_ft2, sizeof(dst_std2)) == 0;
    print_result("ft_memmove Zero bytes copy", passed);

    // Test 3: src and dest are same
    char buffer3[] = "Same place";
    passed = ft_memmove(buffer3, buffer3, strlen(buffer3) + 1) == buffer3;
    print_result("ft_memmove Source equals destination", passed);

    // Test 4: Overlapping forward
    char buffer4_std[] = "123456";
    char buffer4_ft[]  = "123456";
    memmove(buffer4_std + 2, buffer4_std, 4);  // "121234"
    ft_memmove(buffer4_ft + 2, buffer4_ft, 4);
    passed = memcmp(buffer4_std, buffer4_ft, 6) == 0;
    print_result("ft_memmove Overlapping forward copy", passed);

    // Test 5: Overlapping backward
    char buffer5_std[] = "abcdef";
    char buffer5_ft[]  = "abcdef";
    memmove(buffer5_std, buffer5_std + 2, 4);  // "cdefef"
    ft_memmove(buffer5_ft, buffer5_ft + 2, 4);
    passed = memcmp(buffer5_std, buffer5_ft, 6) == 0;
    print_result("ft_memmove Overlapping backward copy", passed);

}

static void	run_memchr_test(const char *desc, const void *src, int c, size_t n)
{
	const void *std = memchr(src, c, n);
	const void *ft = ft_memchr(src, c, n);
	int match = (std == ft) || (std && ft && memcmp(std, ft, 1) == 0);
	print_result(desc, match);
}

void	test_memchr(void)
{
	char buffer[] = "libft42 test buffer";

	run_memchr_test("ft_memchr: find '4'", buffer, '4', sizeof(buffer));
	run_memchr_test("ft_memchr: find 't'", buffer, 't', sizeof(buffer));
	run_memchr_test("ft_memchr: find 'f'", buffer, 'f', 4);      // found early
	run_memchr_test("ft_memchr: find 'z' (not present)", buffer, 'z', sizeof(buffer));
	run_memchr_test("ft_memchr: find '\\0'", buffer, '\0', sizeof(buffer));
	run_memchr_test("ft_memchr: zero bytes", buffer, '4', 0);    // edge case
}

static void run_memcmp_test(const char *desc, const void *s1, const void *s2, size_t n)
{
	int std = memcmp(s1, s2, n);
	int ft = ft_memcmp(s1, s2, n);

	// Normalize to only compare sign (-, 0, +)
	int result = ((std == 0 && ft == 0) ||
				(std < 0 && ft < 0) ||
				(std > 0 && ft > 0));

	print_result(desc, result);
}

void test_memcmp(void)
{
	char a[] = "libft42";
	char b[] = "libft42";
	char c[] = "libFT42";
	char d[] = "lib";

	run_memcmp_test("ft_memcmp: identical", a, b, 7);
	run_memcmp_test("ft_memcmp: different at 4th char", a, c, 7);
	run_memcmp_test("ft_memcmp: only first 3 match", a, d, 3);
	run_memcmp_test("ft_memcmp: empty vs empty", "", "", 0);
	run_memcmp_test("ft_memcmp: early mismatch", "abc", "axc", 2);
	run_memcmp_test("ft_memcmp: mismatch after null", "abc\0z", "abc\0y", 6);
	run_memcmp_test("ft_memcmp: partial match", "abcd", "abcf", 3);
	run_memcmp_test("ft_memcmp: different lengths", "abc", "abcdef", 6);
}

static void run_calloc_test(const char *desc, size_t count, size_t size)
{
	void *mem = ft_calloc(count, size);
	int passed = 1;

	if (mem == NULL && count * size != 0)
		passed = 0;
	else if (mem != NULL)
	{
		unsigned char *bytes = (unsigned char *)mem;
		for (size_t i = 0; i < count * size; i++)
		{
			if (bytes[i] != 0)
			{
				passed = 0;
				break;
			}
		}
	}
	print_result(desc, passed);
	free(mem);
}

void test_calloc(void)
{
	run_calloc_test("ft_calloc: 10 ints", 10, sizeof(int));
	run_calloc_test("ft_calloc: 0 count", 0, sizeof(int));
	run_calloc_test("ft_calloc: 0 size", 10, 0);
	run_calloc_test("ft_calloc: 0 total", 0, 0);
	run_calloc_test("ft_calloc: 100 bytes", 100, 1);
	run_calloc_test("ft_calloc: large allocation", 1024, 1024); // 1 MB
}

void    run_memory_tests(void)
{   
    printf("\n[ Memory tests ]\n");
    print_line();
	test_memset();
	print_line();
	test_bzero();
	print_line();
	test_memcpy();
	print_line();
	test_memmove();
	print_line();
	test_memchr();
	print_line();
	test_memcmp();
	print_line();
	test_calloc();
	print_line();
}
