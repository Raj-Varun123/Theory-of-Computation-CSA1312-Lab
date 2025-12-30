#include <stdio.h>
#include <string.h>

int main() {
    char input_string[100];
    int possible_start = 0;   // represents starting with 'b'
    int possible_end = 0;     // represents ending with 'a'

    printf("Enter a string over {a, b}: ");
    scanf("%s", input_string);

    /* NFA start condition: first symbol must be 'b' */
    if (input_string[0] == 'b')
        possible_start = 1;

    /* NFA end condition: last symbol must be 'a' */
    if (input_string[strlen(input_string) - 1] == 'a')
        possible_end = 1;

    /* Check validity of symbols */
    for (int index = 0; index < strlen(input_string); index++) {
        if (input_string[index] != 'a' && input_string[index] != 'b') {
            printf("Rejected: Invalid symbol\n");
            return 0;
        }
    }

    if (possible_start && possible_end)
        printf("Accepted: String starts with 'b' and ends with 'a'\n");
    else
        printf("Rejected: String does not satisfy the NFA conditions\n");

    return 0;
}
