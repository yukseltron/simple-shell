#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX_LINE 80 /* The maximum length command */


int counter = 0; //Keeps track of number of commands issued
char * history[5];//Stores lat 5 commands
char args[MAX_LINE/2 + 1][MAX_LINE]; /* command line arguments */

int enqueue(char *s[]) {
	history[4] = history[3];
	history[3] = history[2];
	history[2] = history[1];
	history[1] = history[0];
	history[0] = s;
}


int main(void) {
	int should_run = 1; /* flag to determine when to exit program */
	int concurrent; //0 = not conccurent execution

	while (should_run == 1) { //Takes command and parses into array for manipulation
		char str[100];
		int i;//used as looping index
		int j;//letter index for a word
		int k;//word index for sentence

		printf("osh>");
		fgets(str, MAX_LINE, stdin);//get input from user
		counter++;

		if (strcmp(str, "!!") == 10) {
			printf("osh>");
			printf("%s\n", history[2]);
		} else {
			enqueue(str);
			printf("%s\n",history[2]);
		}


		if (strcmp(str, "exit") == 10) {
			should_run = 0;
		}

		j=0;
		k=0;
		concurrent = 0;//default is not concurrent

	    for(i=0;i<=(strlen(str));i++)
	    {
	        // if space or NULL found, assign NULL into newString[ctr]
	        if(str[i]==' '||str[i]=='\0')
	        {
	            args[k][j]='\0';
	            j=0;  //reset index for next word's frist letter to 0
	            k++;  //the next word
	        }
	        else
	        {
				if(str[i] == '&'){//checks for & to determine if it is to be concurrently run
					concurrent = 1;
				}
	            args[k][j]=str[i];//assigns letter to word
	            j++; //next letter
	        }
	    }
/*
		pid_t pid;
		pid = fork();

		if (concurrent == 1) { //Execute concurrently
			execvp(args[0], args); //execute commands given
		}
		else { //Parent waits for child to execute first
			if (pid == 0) {
				execvp(args[0], args);
				exit(1);//child terminates
			} else {
				wait();//waits for child to complete process
			}
		}
		*/

		fflush(stdout);//cleans the buffer
    }

	return 0;
}
