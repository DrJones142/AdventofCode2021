#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *fp;
    char buff[10];
    fp = fopen("input.txt", "r"); //Opens input file
    int fileLine = 0;
    int previous;
    int current;
    int count = 0;

    int rollingAverage1[3];

    while (!feof(fp))
    { //Reads until End of Line
        if (fileLine == 1)
        {
            fscanf(fp, "%s", buff);   //Reads value into buffer
            previous = atoi(buff); //Converts string to int
            fileLine++;               //Increments filecount
        }
        else
        {
            fscanf(fp, "%s", buff); //Scans from stream and put into buffer
            current = atoi(buff);     //Converts current number;

            
            if (feof(fp))           //Checks if end of File
            {
                printf("%d:\n", fileLine+1);  //Prints linenumber (hopefully no data)
            }
            else
            {
                if(current>=previous){   //Compares current value to previous
                    count++;             //Increments count
                }
                previous = current;     //Sets previous to current
                //printf("%d: %s\n", fileLine, buff); //Print buffer
                printf("%d: %d\n", fileLine+1, current); //Print buffer

            }

            fileLine++; //Increment fileLine
        }
    }
    fclose(fp);
    printf("End of Program\n");
    printf("Part 1: Number of times depth increased: %d\n",count);
}