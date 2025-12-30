#include <stdio.h>
#include <string.h>

int main() {
    char input_string[100];
    int index = 0, zero_count = 0, one_count = 0;

    printf("Enter a binary string: ");
    scanf("%s", input_string);

    /* Count leading 0s */
    while (input_string[index] == '0') {
        zero_count++;
        index++;
    }

    /* Count following 1s */
    while (input_string[index] == '1') {
        one_count++;
        index++;
    }

    /* Check complete consumption and equality */
    if (input_string[index] == '\0' && zero_count == one_count) {
        printf("Accepted: String belongs to the CFG\n");
    } else {
        printf("Rejected: String does not belong to the CFG\n");
    }

    return 0;
}
