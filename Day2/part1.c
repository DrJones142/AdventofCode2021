#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *fp;
    char buff[255];
    fp = fopen("input.txt", "r"); //Opens input file
    int fileLine = 0;
    int horizontal=0;
    int depth=0;


     while (!feof(fp)){
     //Reads until End of Line
            fscanf(fp, "%s", buff); //Scans from stream and put into buffer
            if(!strcmp(buff,"down")){
                //printf("DOWN");
                fscanf(fp, "%s",buff);
                depth+= atoi(buff);
            }
            else if(!strcmp(buff,"up")){
                //printf("UP");
                fscanf(fp, "%s",buff);
                depth-= atoi(buff);
            }
            else if(!strcmp(buff,"forward")){
                //printf("Forward");
                fscanf(fp, "%s",buff);
                horizontal+= atoi(buff);
            }
            printf("%d: %s\n", fileLine, buff); //Print buffer
            fileLine++;
            }
    fclose(fp);
    printf("Horizontal: %d\n",horizontal);
    printf("Depth: %d\n",depth);
    printf("Product: %d",horizontal*depth);
    printf("End of Program\n");
}