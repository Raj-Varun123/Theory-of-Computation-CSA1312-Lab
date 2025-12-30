#include <stdio.h>
#include <string.h>

int main() {
    char input_string[100];
    int current_state = 0;   // q0 = start state

    printf("Enter a binary string: ");
    scanf("%s", input_string);

    for (int index = 0; index < strlen(input_string); index++) {
        char symbol = input_string[index];

        switch (current_state) {
            case 0:  // q0: start state
                if (symbol == '0')
                    current_state = 1;   // move to q1
                else
                    current_state = 3;   // dead state
                break;

            case 1:  // q1: valid start with 0
                if (symbol == '0')
                    current_state = 1;   // stay in q1
                else if (symbol == '1')
                    current_state = 2;   // move to accepting state
                break;

            case 2:  // q2: ends with 1
                if (symbol == '0')
                    current_state = 1;   // go back to q1
                else if (symbol == '1')
                    current_state = 2;   // stay in q2
                break;

            case 3:  // dead state
                current_state = 3;
                break;
        }
    }

    if (current_state == 2)
        printf("Accepted: String starts with 0 and ends with 1\n");
    else
        printf("Rejected: String does not satisfy the condition\n");

    return 0;
}
