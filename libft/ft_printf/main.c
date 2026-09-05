
#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		count;
	int		real_count;
	char	*str;
	int		num;

	str = "Hello 42!";
	num = 12345;

	printf("===== ft_printf tests =====\n\n");

	printf("CHAR:\n");
	count = ft_printf("Count test %c\n", 'A');
	real_count = printf("Count test %c\n", 'A');
	printf("libc printf output: %c\n", 'A');
	ft_printf("my printf output: %c\n", 'A');
	printf("Count comparison: %d vs %d\n\n", count, real_count);

	printf("STRING:\n");
	count = ft_printf("Count test %s\n", str);
	real_count = printf("Count test %s\n", str);
	printf("libc printf output: %s\n", str);
	ft_printf("my printf output: %s\n", str);
	printf("Count comparison: %d vs %d\n\n", count, real_count);
	
	printf("DECIMAL:\n");
	count = ft_printf("Count test %d\n", num);
	real_count = printf("Count test %d\n", num);
	printf("libc printf output: %d\n", num);
	ft_printf("my printf output: %d\n", num);
	printf("Count comparison: %d vs %d\n\n", count, real_count);

	printf("INTEGER:\n");
	count = ft_printf("Count test %i\n", -num);
	real_count = printf("Count test %i\n", -num);
	printf("libc printf output: %i\n", -num);
	ft_printf("my printf output: %i\n", -num);
	printf("Count comparison: %d vs %d\n\n", count, real_count);

	printf("UNSIGNED:\n");
	count = ft_printf("Count test %u\n", 4294967295u);
	real_count = printf("Count test %u\n", 4294967295u);
	printf("libc printf output: %u\n", 4294967295u);
	ft_printf("my printf output: %u\n", 4294967295u);
	printf("Count comparison: %d vs %d\n\n", count, real_count);

	printf("PERCENT:\n");
	count = ft_printf("Count test %%\n");
	real_count = printf("Count test %%\n");
	printf("libc printf output: %%\n");
	ft_printf("my printf output: %%\n");
	printf("Count comparison: %d vs %d\n\n", count, real_count);

	printf("HEX LOWER:\n");
	count = ft_printf("Count test %x\n", 48879);
	real_count = printf("Count test %x\n", 48879);
	printf("libc printf output: %x\n", 48879);
	ft_printf("my printf output: %x\n", 48879);
	printf("Count comparison: %d vs %d\n\n", count, real_count);

	printf("HEX UPPER:\n");
	count = ft_printf("Count test %X\n", 48879);
	real_count = printf("Count test %X\n", 48879);
	printf("libc printf output: %X\n", 48879);
	ft_printf("my printf output: %X\n", 48879);
	printf("Count comparison: %d vs %d\n\n", count, real_count);

	printf("POINTER:\n");
	count = ft_printf("Count test %p\n", &num);
	real_count = printf("Count test %p\n", (void *)&num);
	printf("libc printf output: %p\n", &num);
	ft_printf("my printf output: %p\n", &num);
	printf("Count comparison: %d vs %d\n\n", count, real_count);

	printf("NULL POINTER:\n");
	count = ft_printf("Count test %p\n", NULL);
	real_count = printf("Count test %p\n", NULL);
	printf("libc printf output: %p\n", NULL);
	ft_printf("my printf output: %p\n", NULL);
	printf("Count comparison: %d vs %d\n\n", count, real_count);

	printf("MIXED:\n");
	count = ft_printf("Count test %c %s %d %u %x %X %p %%\n",
		'Z', "test", -42, 42, 42, 42, &num);
	real_count = printf("Count test %c %s %d %u %x %X %p %%\n",
		'Z', "test", -42, 42, 42, 42, (void *)&num);
	printf("Count comparison: %d vs %d\n\n", count, real_count);

	printf("Series of edge cases, my result, then libc result\n\n");

	printf("0 passed into d:\n");
	ft_printf("%d\n", 0);
	printf("%d\n\n", 0);

	printf("0 passed into u:\n");
	ft_printf("%u\n", 0);
	printf("%u\n\n", 0);

	printf("0 passed into x:\n");
	ft_printf("%x\n", 0);
	printf("%x\n\n", 0);

	printf("NULL passed into p:\n");
	ft_printf("%p\n", NULL);
	printf("%p\n\n", NULL);

	printf("empty string passed into s:\n");
	ft_printf("%s\n", "");
	printf("%s\n\n", "");

	printf("NULL passed into s:\n");
	ft_printf("%s\n", NULL);
	printf("%s\n\n", NULL);

	printf("int min passed into d:\n");
	ft_printf("%d\n", -2147483648);
	printf("%d\n\n", -2147483648);

	printf("max uint passed into u:\n");
	ft_printf("%u\n", 4294967295u);
	printf("%u\n\n", 4294967295u);
	
	printf("series of percentages:\n");
	ft_printf("%% %\n");
	printf("%% %\n");
	
	return (0);
}