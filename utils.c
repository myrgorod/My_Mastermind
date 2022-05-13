#include <stdlib.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <time.h>
 
 #include "struct.h"





char *makeCode(){                   /*  generation random code*/
	srand(time(NULL));
	static char code[5];
	int from = '0';
	int to = '7';
		for (int i = 0; i < 4 ; i++){
			code[i]= (rand( ) % (to - from + 1)) + from;
		}
		return code;
}

int my_strcmp(char *param_1, char *param_2){   
	int i = 0;
	while (param_1[i] == param_2[i] && param_1[i] != '\0' && param_2[i] !='\0')
	{
		i++;
	}
	return param_1[i] - param_2[i] == 0 ? 1 : 0;
}

void my_strcpy (char * destination, char * source) /* êîï³þâàííÿ ç ðàäêà source â ðÿäîê  destination */
{
	while((*destination++ = *source++))
	{
	};
 } 
 
 int validate_code ( char *str){   //Function to check if the user input is valid 
	int i = 0;
	while (str[i] !='\0')
	{
		if (str[i]<'0' || str [i] >'7')
		{return 0;
		} 
		i++;
	} 
	return i == 4 ? 1:0;
}


char * ask_code()      /* Input code and checking correctness of the code */ 
{
	static char code [4];
	read(STDIN_FILENO,code,5);
	if(code [4]== '\n')
		{
			code[4] = '\0';
		}
	if (validate_code(code)==0)
	{
		printf("Wrong input!\n");
		return ask_code ();
	}
	return code;
}

struct analytics analyze (char *code, char *ucode)    /* Checking wellplaced and misplased characters in ucode*/
{
	struct analytics result;
	result.wellplaced = 0;
	result.misplaced = 0;
	int i = 0;
		while (ucode[i] !='\0')
		{
			if (code [i] == ucode [i])
			{
				result.wellplaced ++ ;
			} else
			{
				int j = 0;
				while (code [i] !='0')
				{
					if (code [j] == ucode [i])
					{
						result.misplaced ++ ;
						break;
					}
					j ++ ;
				}
			}
			i ++;
		}
	return result;
}


void debug (char *str)  /* debug function used in work on project*/
{
	int i = 0;
	while (str[i] !='\0')
	{
		printf ("%d", (int)str[i]);
		i++;
	}
	printf ("\n");
}


