#include <stdio.h>
#include "libft.h"

// Example function to use with ft_striteri
void ft_striteri_function(unsigned int i, char c) {
    printf("ft_striteri: %c at index %u\n", c, i);
}

// Example function to use with ft_strmapi
char ft_strmapi_function(unsigned int i, char c) {
    return c - i;
}

int main() {
    // Test ft_putchar_fd
    char c = 'A';
    int fd = 1;  // Standard output
    ft_putchar_fd(c, fd);  // Expected output: 'A'

    // Test ft_putstr_fd
    ft_putstr_fd("Hello, world!", fd);  // Expected output: "Hello, world!"

    // Test ft_putendl_fd
    ft_putendl_fd("Hello, world!", fd);  // Expected output: "Hello, world!\n"

    // Test ft_putnbr_fd
    ft_putnbr_fd(42, fd);  // Expected output: "42"

    // Test character functions
    printf("ft_isascii('A'): %d\n", ft_isascii('A'));  // Expected output: 1
    printf("ft_isascii(128): %d\n", ft_isascii(128)); // Expected output: 0
    printf("ft_isalpha('A'): %d\n", ft_isalpha('A')); // Expected output: 1
    printf("ft_isalpha('1'): %d\n", ft_isalpha('1')); // Expected output: 0
    printf("ft_isdigit('5'): %d\n", ft_isdigit('5')); // Expected output: 1
    printf("ft_isdigit('a'): %d\n", ft_isdigit('a')); // Expected output: 0
    printf("ft_isprint(' '): %d\n", ft_isprint(' ')); // Expected output: 1
    printf("ft_isprint(127): %d\n", ft_isprint(127)); // Expected output: 0

    // Test character conversion
    printf("ft_tolower('A'): %c\n", ft_tolower('A')); // Expected output: 'a'
    printf("ft_toupper('a'): %c\n", ft_toupper('a')); // Expected output: 'A'

    // Test memory functions
    char str1[] = "Hello, World!";
    printf("ft_memchr: %s\n", (char *)ft_memchr(str1, 'W', sizeof(str1))); // Expected output: "World!"
    printf("ft_memcmp: %d\n", ft_memcmp("Hello", "Hello", 5)); // Expected output: 0
    char dest1[20];
    ft_memcpy(dest1, str1, sizeof(str1));
    printf("ft_memcpy: %s\n", dest1); // Expected output: "Hello, World!"
    ft_memmove(dest1 + 7, dest1, sizeof(dest1) - 7);
    printf("ft_memmove: %s\n", dest1); // Expected output: "HelloHello, World!"
    ft_memset(dest1, 'A', 5);
    printf("ft_memset: %s\n", dest1); // Expected output: "AAAAAHelloHello, World!"

    // Test string functions
    printf("ft_strncmp: %d\n", ft_strncmp("Hello", "Hello", 5)); // Expected output: 0
    printf("ft_strlen: %zu\n", ft_strlen("Hello, World!")); // Expected output: 13
    char dest2[20];
    ft_strlcpy(dest2, "Hello, World!", 20);
    printf("ft_strlcpy: %s\n", dest2); // Expected output: "Hello, World!"
    ft_strlcat(dest2, ", universe!", 20);
    printf("ft_strlcat: %s\n", dest2); // Expected output: "Hello, World!, universe!"
    char *joined = ft_strjoin("Hello, ", "World!");
    printf("ft_strjoin: %s\n", joined); // Expected output: "Hello, World!"
    free(joined);
    char *dup = ft_strdup("Duplicate this string");
    printf("ft_strdup: %s\n", dup); // Expected output: "Duplicate this string"
    free(dup);
    
    // Test ft_bzero
    char str2[] = "Hello, World!";
    ft_bzero(str2, 5);
    printf("ft_bzero: %s\n", str2); // Expected output: ", World!"
    
    // Test ft_calloc
    int *arr = (int *)ft_calloc(5, sizeof(int));
    if (arr) {
        for (int i = 0; i < 5; i++) {
            printf("ft_calloc: %d ", arr[i]); // Expected output: 0 0 0 0 0
        }
        free(arr);
    }

    // Test ft_striteri
    char str3[] = "abcdef";
    ft_striteri(str3, ft_striteri_function);  // This will now work
    
    // Test ft_strchr
    printf("ft_strchr: %s\n", ft_strchr("Hello, World!", 'W')); // Expected output: "World!"

    // Test ft_strrchr
    printf("ft_strrchr: %s\n", ft_strrchr("Hello, World!", 'o')); // Expected output: "orld!"

    // Test ft_strtrim
    printf("ft_strtrim: %s\n", ft_strtrim("   Hello, World!   ", " ")); // Expected output: "Hello, World!"

    // Test ft_substr
    printf("ft_substr: %s\n", ft_substr("Hello, World!", 7, 5)); // Expected output: "World"

    // Test ft_strnstr
    printf("ft_strnstr: %s\n", ft_strnstr("Hello, World!", "World", 5)); // Expected output: NULL

    // Test ft_strmapi
    printf("ft_strmapi: %s\n", ft_strmapi("abcdef", ft_strmapi_function)); // Expected output: "abcde"

    // Test ft_itoa
    printf("ft_itoa: %s\n", ft_itoa(12345)); // Expected output: "12345"

    // Test ft_split
    char **split = ft_split("one,two,three", ',');
    for (int i = 0; split && split[i]; i++) {
        printf("ft_split: %s\n", split[i]); // Expected output: "one", "two", "three"
    }
    free(split);

    // Test ft_atoi
    printf("ft_atoi: %d\n", ft_atoi("   -42")); // Expected output: -42
    printf("ft_atoi: %d\n", ft_atoi("12345"));   // Expected output: 12345
    printf("ft_atoi: %d\n", ft_atoi("   42abc")); // Expected output: 42

    return 0;
}
