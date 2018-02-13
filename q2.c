#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX_LINE 80 /* The maximum length command */


int counter = 0; //Keeps track of number of commands issued
char *history[5][MAX_LINE];//Stores lat 5 commands
char args[MAX_LINE/2 + 1][MAX_LINE]; /* command line arguments */

int enqueue(char *s[]) {
	char *temp1[MAX_LINE];
	char *temp2[MAX_LINE];


	strcpy(temp1, history[0]);
	strcpy(history[0], s);
	strcpy(temp2,history[1]);
	strcpy(history[1],temp1);
	strcpy(temp1,history[2]);
	strcpy(history[2],temp2);
	strcpy(temp2,history[3]);
	strcpy(history[3],temp1);
	strcpy(history[4],temp2);


	printf("2 %s\n", history[0]);
	printf("3 %s\n", history[1]);
	printf("4 %s\n", history[2]);
	printf("5 %s\n", history[3]);
	printf("6 %s\n", history[4]);
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

		printf("%s\n","---");
		printf("%s\n",history[0]);
		printf("%s\n",history[1]);
		printf("%s\n",history[2]);
		printf("%s\n",history[3]);
		printf("%s\n",history[4]);
		printf("%s\n","---");

		if (strcmp(str, "!!") == 10) {
			printf("osh>");
		//	printf("%s\n", history[0]);
			enqueue(str);
		} else {
			enqueue(str);
			//printf("%s\n",&history[0]);
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
