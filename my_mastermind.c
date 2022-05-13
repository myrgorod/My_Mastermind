#include <stdlib.h>
#include <stdio.h>


#include "struct.h"
#include "utils.h"

int main (int argc, char **argv)
{
	int attempts = 10; 
	char code[5];
	
	my_strcpy(code, makeCode());
		for (int i = 1; i<argc; i ++ ) 
		{
			if (i+1 <= argc) 
			{
				if (my_strcmp(argv[i], "-t") == 1)
				{
					int value = atoi(argv[i + 1]);
					if (value !=0)
					{
						attempts = value ;
					}
				}
				if (my_strcmp(argv[i], "-c") == 1 )
				{
					if (validate_code (argv[i+1])){
						my_strcpy(code, argv [i+1]);
					}
				}
			}
		}
		printf ("Will you find the secret code?\n");
		char ucode[5];
		for (int attempt =0; attempt <attempts; attempt ++)
		{
			printf ("___\n Round %d\n", attempt);
			my_strcpy (ucode, ask_code());
			if (my_strcmp(code, ucode)==1)
			{
				printf ("Congrats! You did it!\n");
				return 0;
			}
			else
			{
				struct analytics result = analyze(code, ucode);
				printf ("Wellplaced places : %d\n misplaced places : %d\n", result.wellplaced , result.misplaced );
			}
			
		}
		return 0;
}
