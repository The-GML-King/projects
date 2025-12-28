#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

char buff[128];
char hlp_txt[1024] = "\nThis is a simple shell program.\n"
                   "Available commands:\n"
                   "  help - Display this help message\n"
                   "  exit - Exit the shell\n"
                   "  timedate - Get the current system time\n"
                   "  clear - Clear the console screen\n"
                   "  notepad - Open Notepad application\n"
                   "  explorer - Open File Explorer\n\n";

void cmd_translate(){

    buff[strcspn(buff, "\n")] = '\0';

    for (int i = 0; i <strlen(buff); i++){
        if (isupper(buff[i])) {
            buff[i] = tolower(buff[i]);
        }
    }    

}

int main(int argc, char *argv[]) {
    printf("(c) Nerdcrosoft 2025.\n");
    printf("Type 'help' for documentation.\n");
    while (1) {
        printf("> ");
        fgets(buff, sizeof(buff), stdin);
        cmd_translate();
        if (strcmp(buff,"exit") == 0) {
            break;
        } else if (strcmp(buff,"help") == 0) {
            printf("%s", hlp_txt);
        } else if (strcmp(buff,"timedate") == 0) {
            time_t now;
            time(&now);
            printf("Current time and date: %s", ctime(&now));
        } else if (strcmp(buff,"clear") == 0) {
            system("cls");
        } else if (strlen(buff) == 0) {
            continue;
        } else if (strcmp(buff,"notepad") == 0) {
            system("notepad");
        } else if (strcmp(buff,"explorer") == 0) {
            system("explorer");
        } else {
            printf("Unknown command: %s\n", buff);
        }   
    }
    return 0;
}