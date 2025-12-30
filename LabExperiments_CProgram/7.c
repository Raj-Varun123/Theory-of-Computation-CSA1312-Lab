#include <stdio.h>
#include <string.h>

int main() {
    char input_string[200];
    int length, found = 0;

    printf("Enter a binary string: ");
    scanf("%s", input_string);

    length = strlen(input_string);

    /* Check for substring "101" */
    for (int index = 0; index <= length - 3; index++) {
        if (input_string[index] == '1' &&
            input_string[index + 1] == '0' &&
            input_string[index + 2] == '1') {
            found = 1;
            break;
        }
    }

    /* Check all characters are 0 or 1 */
    for (int index = 0; index < length; index++) {
        if (input_string[index] != '0' && input_string[index] != '1') {
            printf("Rejected: String does not belong to the CFG\n");
            return 0;
        }
    }

    if (found)
        printf("Accepted: String belongs to the CFG\n");
    else
        printf("Rejected: String does not belong to the CFG\n");

    return 0;
}
