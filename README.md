# Hamza-s-Basic-Unix-Shell
## Overview
This project implements a basic Unix-like shell in C. Designed as a learning tool, the shell supports essential command-line functionalities such as:
- **Built-in commands**: `cd`, `pwd`, and `exit`
- **System command execution**: Supports commands like `ls`, `date`, `cat`, and others using `execvp`
- **Custom prompt**: Displays as `Hamza's_shell> `

 Features
- Command Parsing: Accepts user input and parses it into executable commands and arguments.
- Child Process Management: Creates child processes to handle non-built-in commands, ensuring isolation and resource management.
- Error Handling: Provides feedback for unknown commands or incorrect usage.
- Built-in Commands Implements basic commands like `cd` (for changing directories), `pwd` (to display the current directory), and `echo`.
1. Clone the repository.
2. Compile the program with `gcc`:
   ```bash
   gcc shell.c -o shell

