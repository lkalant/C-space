// Levon Kalantarian
// Program that forks 8 child processes from the main process

#include <stdio.h>
#include <unistd.h>

int main()
{
    int p;     // int to store fork return values (pid's)
    int c = 0; // counter for printing child numbers

    for (int i = 0; i < 8; i++) // Loop 8 times through, forking only from the main process each time
    {
        p = fork();
        c++;        // After each fork, increment the child counter, assuming a new child was created
        if (p == 0) // Test if p = 0.  If p = 0, it is the child process
        {
            printf("    Child number: %d, pid: %d\n\n", c, getpid()); // Print child number c, and pid of child process
            break;                                                    // Break out of for loop once a child process is executed.  This prevents any child processes from forking
        }
        else // Else if p!=0, then it is the parent process
        {
            printf("Parent p = %d, pid: %d        \n", p, getpid()); // Print fork return value p, and pid of parent process (should be the same process each time)
            sleep(1);                                                // slight pause, then fork next child process (up to 8) in the loop
        }
    }
}
