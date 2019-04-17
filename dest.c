#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

void F_Name();
void F_Mask();

void main(int argc, char **argv)
    {
            FILE *loc = &argv[0];
            char *file_name = argv[0];
            F_Name(file_name,loc);
    }

    void F_Name(char *file_name,FILE *loc)
        {
            char path[PATH_MAX];
            char cfil[50];
            getcwd(path,sizeof(path));
	        char *fn = memmove(file_name,file_name+2,strlen(file_name));
            strcat(strcat(strcat(cfil,path),"/"),fn);
            F_Mask(cfil,loc);
        }

    void F_Mask(char *fullname,FILE *loc)
        {
            short count = 0;
            remove(fullname);
            loc = fopen(fullname,"w+");            
            while(count<5)
                {
                    fprintf(loc,"The time is [ %s ]\n",__TIME__);
                    printf("NOW [ %d ]\n",__TIME__);
                    count++;
                }
            fclose(loc);
        }
