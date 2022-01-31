#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct table{
    char* keyword;
    int count;

};

int main(int argc, char** argv)
{
    int i;
    struct table* abc = (struct table*) malloc(argc* sizeof(struct table));
    for(i=0; i<argc-1; i++)
    {
     abc[i].keyword = argv[i+1]; 
     abc[i].count = 0;
    }
    char *line=NULL;
    size_t maxlen=0;
    ssize_t n;
    while ( (n = getline(&line, &maxlen, stdin)) > 0)
    {
        char * linewords = strtok(line, " ");
        while(linewords != NULL)
        {
                    
            for(i=0; i<argc-1; i++)
            {
                if(strstr(linewords, "\n"))
                {
                    linewords[strlen(linewords)- 1] = '\0';
                }   
                if (strcmp(linewords, abc[i].keyword) == 0)
                {
                    abc[i].count += 1;
                }
            }
            linewords = strtok(NULL, " ");
        }
    }
    for(i=0; i<argc-1; i++)
    {
        printf("%s %d\n", abc[i].keyword, abc[i].count);
    }
    free(line);    
}

