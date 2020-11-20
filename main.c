#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#define _CRT_SECURE_NO_WARNINGS
int main(int argc, char* argv[]) {
    char *ref1 = argv[2];
    char *ref2 = argv[4];
    float val1 = strtof(ref1, NULL);
    float val2 = strtof(ref2, NULL);
    float rct;
    float cct;
    struct tm *local;
    time_t start, end;


    if(argc != 5){
        printf("Error invalid command");
        exit(1);
    }
    else{

        time(&start);
        local = localtime(&start);
        printf("# Start time and date: %s", asctime(local));

        scanf("%f", &rct);
        scanf("%f", &cct);

        float** rows = (float **) malloc(rct * sizeof(float*));
        if (rows == 0){

            fprintf(stderr, "Couldn't allocate sufficient row space. \n");
           exit(1);
       }
       int i ,j;
       for(i=0;i < rct; i++){
           float *row = (float *) malloc(cct * sizeof(float));
                   if(row == 0){
                       fprintf(stderr, "couldn't allocate sufficient row space.\n");
                       exit(1); //    scanf("%f", rows[i][j]);
                   }

           rows[i] =row;

       }
        for(int i=0;i<rct;i++){
            for(int j=0;j<cct;j++){
                scanf("%f", &rows[i][j]);
            }
        }
        //Print to check if reading matrix into memory correctly
/*for(int i = 0; i <rct; i++){
for(int j = 0; j <cct; j++){
fprintf(stdout, "r=%d : c=%d : %.2f\n", i, j , rows[i][j]);
}
}*/

        approxEqual(val1, val2, rct, cct, rows);

       time(&end);
       local = localtime(&end);
       printf("# Time ended: %s", asctime(local));
       printf("####End of file###");

   }
}
