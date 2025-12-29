#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int state = 0;  // 0 = start, 1 = valid start with 'a', 2 = dead state

    printf("Enter a string: ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {
        char symbol = input[i];

        switch (state) {
            case 0: // start state
                if (symbol == 'a')
                    state = 1;
                else
                    state = 2;
                break;

            case 1: // started with 'a'
                if (symbol == 'a' || symbol == 'b')
                    state = 1;
                break;

            case 2: // dead state
                state = 2;
                break;
        }
    }

    if (state == 1 && input[strlen(input) - 1] == 'a')
        printf("String is ACCEPTED by the DFA\n");
    else
        printf("String is REJECTED by the DFA\n");

    return 0;
}
