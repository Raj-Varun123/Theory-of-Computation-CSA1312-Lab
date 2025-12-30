#include <stdio.h>
#include <string.h>

int main() {
    char input_string[100];
    int left_index = 0, right_index, length;

    printf("Enter a binary string: ");
    scanf("%s", input_string);

    length = strlen(input_string);
    right_index = length - 1;

    /* Match leading and trailing 0s (S ? 0S0) */
    while (left_index < right_index && input_string[left_index] == '0' && input_string[right_index] == '0') {
        left_index++;
        right_index--;
    }

    /* Middle part must be only 1s (A ? 1A | e) */
    for (int index = left_index; index <= right_index; index++) {
        if (input_string[index] != '1') {
            printf("Rejected: String does not belong to the CFG\n");
            return 0;
        }
    }

    printf("Accepted: String belongs to the CFG\n");
    return 0;
}
