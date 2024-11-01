#include "kernel/types.h"
#include "user/user.h"
#include "kernel/param.h" //MAXARGS

int main(int argc, char *argv[]) 
{
    char *cmd[MAXARG]; //command and args
    char buffer[512];

    int buffer_pos = 0; //keep track of the position in buffer

    int pid;

    //copy argv into cmd
    for (int i = 1; i < argc && i < MAXARG - 1; i++) 
    {
        cmd[i - 1] = argv[i];
    }

    while (1) 
    {
        int r = read(0, &buffer[buffer_pos], 1);

        if (r <= 0) break; 


        if (buffer[buffer_pos] == '\n') //endl found
        {
            buffer[buffer_pos] = '\0'; //terminiate the line
            cmd[argc - 1] = buffer;
            cmd[argc] = 0;

            pid = fork();

            if (pid == 0) //child pr
            {
                exec(cmd[0], cmd);
                exit(1);
            } 
            else if (pid > 0) //parent pr
            { 
                wait(0);  //waits for child to terminate
            } 
            else 
            {
                fprintf(2, "\nFork Error!\n");
                exit(1);
            }
            buffer_pos = 0; //reset buf for the next line
        } 
        else 
        {
            buffer_pos++; //line isnt ended yet, simply move to the next char in buf
        }
    }
    exit(0);
}
