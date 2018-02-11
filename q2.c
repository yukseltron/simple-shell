#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX_LINE 80 /* The maximum length command */

int main(void) {

	char args[MAX_LINE/2 + 1][MAX_LINE]; /* command line arguments */
	int should_run = 1; /* flag to determine when to exit program */

	while (should_run) { //Takes command and parses into array for manipulation
		char str[100];
		int i;//used as looping index
		int j;//letter index for a word
		int k;//word index for sentence

		printf("osh>");
		fgets(str, MAX_LINE, stdin);

		j=0;
		k=0;

	    for(i=0;i<=(strlen(str));i++)
	    {
	        // if space or NULL found, assign NULL into newString[ctr]
	        if(str[i]==' '||str[i]=='\0')
	        {
	            args[k][j]='\0';
	            k++;  //the next word
	            j=0;  //reset index for next word's frist letter to 0
	        }
	        else
	        {
	            args[k][j]=str[i];
	            j++;
	        }
	    }

		fflush(stdout);
    }

	return 0;
}
