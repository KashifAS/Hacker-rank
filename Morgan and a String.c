#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *str = NULL;
char* readline();

// Complete the morganAndString function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//
char* morganAndString(char* a, char* b) {
int n = strlen(a) + strlen(b);
int i = 0, j= 0, k = 0,i1 = 0,j1 = 0;
char prev = '\0';
str = (char *)malloc(n * sizeof(char));
while(a[i] != '\0' && b[j] !='\0')
{
    if(a[i]  < b[j])
    {
        str[k++] = a[i++]; 
    }
    else if(a[i] > b[j])
    {
        str[k++] = b[j++];
    }
    else {
    //int i1 = i, j1 = j;
    if((i >= i1 || j >= j1) || (prev == a[i] && a[i1] == '\0') || (prev == a[i] && b[j1] == '\0'))
    {
        j1 = j;
        i1 = i;
     while(a[i1] == b[j1] && a[i1] != '\0' && b[j1] != '\0')
        {
            i1++;
            j1++;

        }
    }
    prev = a[i];
    if(a[i1] <= b[j1] && a[i1] !='\0' && b[j1] != '\0')
    {
        str[k++] = a[i++];
    }
    else if(a[i1] > b[j1] && a[i1] !='\0' && b[j1] != '\0')
    {
        str[k++] = b[j++];
    }
    else if(a[i1] =='\0' && b[j1] == '\0')
    {
        str[k++] = a[i++];
    }
    else if(a[i1] !='\0' && b[j1] == '\0')
    {
        str[k++] = a[i++];
    }
    else if(a[i1] =='\0' && b[j1] != '\0')
    {
        str[k++] = b[j++];
    }

    }
}
    while(a[i] != '\0')
    {
        str[k++] = a[i++];
    }
    while(b[j] != '\0')
    {
        str[k++] = b[j++];

    }

    str[k] = '\0';

return str;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char* a = readline();

        char* b = readline();

        char* result = morganAndString(a, b);

        fprintf(fptr, "%s\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
