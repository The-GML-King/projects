#include <stdio.h>
#include <string.h>

#define HEATER_MAX_TEMP 30
#define HEATER_MIN_TEMP 17

int temp = 17;
char input[10];

int main(int argc, char *argv[]) {
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strcmp(input,"+\n") == 0) {
            temp++;
        } else if (strcmp(input,"-\n") == 0) {
            temp--;
        } else if (strcmp(input,"q\n") == 0) {
            break;
        } else {
            printf("Invalid input. Use '+' to increase, '-' to decrease, 'q' to quit.\n");
            continue;
        }
        if (temp > HEATER_MAX_TEMP) {
            printf("Exceeded max temperature! Setting it within bounds.\n");
            temp = HEATER_MAX_TEMP;
        } else if (temp < HEATER_MIN_TEMP) {
            printf("Exceeded min temperature! Setting it within bounds.\n");
            temp = HEATER_MIN_TEMP;
        }
        printf("Current temperature: %d\n", temp);
    }
    return 0;
}