#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *fp;
    char buff[255];
    fp = fopen("input.txt", "r"); //Opens input file
    int sum[12];
    int fileLine = 0;


     while (!feof(fp)){
     //Reads until End of Line
            fscanf(fp, "%s", buff); //Scans from stream and put into buffer
            if(fileLine<1){
                printf("%s\n",buff);
            }
            fileLine++;
            for(int i=0;i<12;i++){
                char c = buff[i];
                int x = c - '0';
                sum[i]+=x;
            }

     }
    fclose(fp);
    for(int i=0;i<12;i++){
        printf("Bit %d: %d\n",i,sum[i]);
    }
    printf("Number of FileLines: %d\n",fileLine);
    printf("Sum of First Digit: %d\n",sum[0]);
    printf("End of Program\n");
}