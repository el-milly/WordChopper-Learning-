#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
	char* data;
	int len;
} String_View;

void chop_right_function(String_View *s)
{
	int n = 3;
	if(n>s->len) return;
	s->len -= n;
	s->data[s->len] = '\0';
	printf("%s", s->data);
}


String_View duplicate_function(char* arg, int argl) // argl - len of the word
{
	char* new_st = malloc(argl*sizeof(char));
	for(int i=0; i < argl; i++)
	{
		new_st[i] = arg[i]; // duplication process
	}
	String_View s = {new_st, argl};
	return s;
}


int main(void)
{
	char* cstr = "Hello, World!";
	int cstrl = strlen(cstr); // len of the word
	String_View new_cstr = duplicate_function(cstr, cstrl); // stores result in new_cstr
	chop_right_function(&new_cstr);
	free(new_cstr.data); // free the memory before the program ends
	return 0;
}
