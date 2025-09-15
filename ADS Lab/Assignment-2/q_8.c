#include <stdio.h>
#include <string.h>

int countVowels(const char *str) {
    int count = 0;
    while (*str) {
        if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' ||
            *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U') {
            count++;
        }
        str++;
    }
    return count;
}

int countVowelsWithLookup(const char *str) {
    int lookup[256] = {0};  // Initialize all to 0
    lookup['a'] = lookup['e'] = lookup['i'] = lookup['o'] = lookup['u'] = 1;
    lookup['A'] = lookup['E'] = lookup['I'] = lookup['O'] = lookup['U'] = 1;

    int count = 0;
    while (*str) {
        if (lookup[*str]) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char str[] = "Hello World";
    printf("Number of vowels: %d\n", countVowels(str));
    printf("Number of vowels: %d\n", countVowelsWithLookup(str));
    return 0;
}
