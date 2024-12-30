#include "libftprintf.h"

int main(void)
{
    ft_printf("Hello, %c!\n", 'A');                    // %c: Print a character
    ft_printf("String: %s\n", "Hello, World!");         // %s: Print a string
    ft_printf("Pointer: %p\n", (void *)0x1234abcd);     // %p: Print a pointer (address)
    ft_printf("Signed Integer: %d\n", -12345);          // %d: Print a signed integer
    ft_printf("Unsigned Integer: %u\n", 12345);         // %u: Print an unsigned integer
    ft_printf("Hex (lowercase): %x\n", 255);            // %x: Print a hexadecimal number (lowercase)
    ft_printf("Hex (uppercase): %X\n", 255);            // %X: Print a hexadecimal number (uppercase)

    return 0;
}