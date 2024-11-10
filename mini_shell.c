#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024  

int main() {
    char command[BUFFER_SIZE];  
    char *args[BUFFER_SIZE / 2]; 

    while (1) {  
        printf("Hamza's_shell> "); 
        fgets(command, BUFFER_SIZE, stdin);  
        command[strcspn(command, "\n")] = 0;
        int i = 0;
        args[i] = strtok(command, " ");  
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }
        if (strcmp(args[0], "exit") == 0) {
            break;  
        }
        else if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                fprintf(stderr, "Expected argument to \"cd\"\n");
            } else {
                if (chdir(args[1]) != 0) {
                    perror("Hamza's_shell");
                }
            }
        }
        else if (strcmp(args[0], "pwd") == 0) {
            char cwd[BUFFER_SIZE];
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                printf("%s\n", cwd);
            } else {
                perror("Hamza's_shell");
            }
        }
        else if (strcmp(args[0], "echo") == 0) {
            for (int j = 1; args[j] != NULL; j++) {
                printf("%s ", args[j]);
            }
            printf("\n");
        }
        else if (strcmp(args[0], "ls") == 0) {
            pid_t pid = fork();  
            if (pid < 0) {
                perror("Hamza's_shell");  
            } else if (pid == 0) {
                execvp(args[0], args);
                perror("Hamza's_shell");  
                exit(EXIT_FAILURE);
            } else {
                wait(NULL); 
            }
        }
        else {
            printf("Unknown command: %s\n", args[0]);
        }
    }

    printf("Exiting shell...\n");
    return 0;
}
