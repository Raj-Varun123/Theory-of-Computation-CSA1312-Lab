#include <stdio.h>
#include <string.h>

int main() {
    char input_string[100];
    int length;

    printf("Enter a binary string: ");
    scanf("%s", input_string);

    length = strlen(input_string);

    /* Check minimum length and boundary symbols */
    if (length >= 2 && input_string[0] == '0' && input_string[length - 1] == '1') {
        /* Check that all symbols are either 0 or 1 */
        for (int index = 0; index < length; index++) {
            if (input_string[index] != '0' && input_string[index] != '1') {
                printf("Rejected: String does not belong to the CFG\n");
                return 0;
            }
        }
        printf("Accepted: String belongs to the CFG\n");
    } else {
        printf("Rejected: String does not belong to the CFG\n");
    }

    return 0;
}
