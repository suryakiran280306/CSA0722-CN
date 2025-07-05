#include <stdio.h>
#include <string.h>

void bitStuffing(char *input, char *stuffed) {
    int i, count = 0, j = 0;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == '1') count++;
        else count = 0;

        stuffed[j++] = input[i];

        if (count == 5) {
            stuffed[j++] = '0'; // stuff a 0
            count = 0;
        }
    }
    stuffed[j] = '\0';
}

void bitDestuffing(char *stuffed, char *destuffed) {
    int i, count = 0, j = 0;
    for (i = 0; stuffed[i] != '\0'; i++) {
        if (stuffed[i] == '1') count++;
        else count = 0;

        destuffed[j++] = stuffed[i];

        if (count == 5 && stuffed[i+1] == '0') {
            i++; // skip the stuffed '0'
            count = 0;
        }
    }
    destuffed[j] = '\0';
}

int main() {
    char input[100], stuffed[200], destuffed[200];

    printf("Enter the binary data: ");
    scanf("%s", input);

    bitStuffing(input, stuffed);
    printf("\nStuffed data:   %s\n", stuffed);

    bitDestuffing(stuffed, destuffed);
    printf("Destuffed data: %s\n", destuffed);

    return 0;
}

