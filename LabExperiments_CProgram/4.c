#include <stdio.h>
#include <string.h>

int main() {
    char input_string[100];
    int left_index, right_index;

    printf("Enter a binary string: ");
    scanf("%s", input_string);

    left_index = 0;
    right_index = strlen(input_string) - 1;

    /* Check palindrome property */
    while (left_index < right_index) {
        if (input_string[left_index] != input_string[right_index]) {
            printf("Rejected: String does not belong to the CFG\n");
            return 0;
        }
        left_index++;
        right_index--;
    }

    /* Check that all characters are 0 or 1 */
    for (int index = 0; index < strlen(input_string); index++) {
        if (input_string[index] != '0' && input_string[index] != '1') {
            printf("Rejected: String does not belong to the CFG\n");
            return 0;
        }
    }

    printf("Accepted: String belongs to the CFG\n");
    return 0;
}
