#include <stdio.h>
#include <string.h>

int main() {
    char input_string[100];
    int possible_start = 0;   // check if string can start with '0'
    int possible_end = 0;     // check if string can end with '1'

    printf("Enter a binary string: ");
    scanf("%s", input_string);

    /* Check start symbol */
    if (input_string[0] == '0')
        possible_start = 1;

    /* Check end symbol */
    if (input_string[strlen(input_string) - 1] == '1')
        possible_end = 1;

    /* Check all symbols are valid binary characters */
    for (int index = 0; index < strlen(input_string); index++) {
        if (input_string[index] != '0' && input_string[index] != '1') {
            printf("Rejected: Invalid symbol in string\n");
            return 0;
        }
    }

    if (possible_start && possible_end)
        printf("Accepted: String starts with '0' and ends with '1'\n");
    else
        printf("Rejected: String does not satisfy the NFA conditions\n");

    return 0;
}
