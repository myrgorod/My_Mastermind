# ifndef FILE_UTILS_SEEN
# define FILE_UTILS_SEEN


int my_strcmp(char *param_1, char *param_2);
void my_strcpy (char * destination, char * source);
int validate_code ( char *digit);
char *makeCode();
char * ask_code();
struct analytics analyze (char *code, char *ucode);
void debug (char *str);


#endif