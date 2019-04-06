#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

int F_Name();
int F_Mask();

void main(int argc, char **argv)
    {
            char *file_name = argv[0];
            F_Name(file_name);
    }

    int F_Name(char *file_name)
        {
            char path[PATH_MAX];
            char cfil[50];
            getcwd(path,sizeof(path));
	        char *fn = memmove(file_name,file_name+2,strlen(file_name));
            strcat(strcat(strcat(cfil,path),"/"),fn);
            return F_Mask(cfil);
        }

    int F_Mask(char *fullname)
        {
            printf("[> %s <]\n", fullname);
            remove(fullname);
            FILE *loc;
            loc = fopen(fullname,"w");
            fprintf(loc,__TIME__);
            fclose(loc);            
           return 0;
        }
