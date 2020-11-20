//
// Created by spike on 19/11/2020.
//

#ifndef LAB06_UTILS_H
#define LAB06_UTILS_H


void approxEqual(float val1, float val2, float rct, float cct, float**rows) {
    int count =0;
    float toleranceP = val1 + val2;
    float toleranceN = val1 - val2;
    for(int i = 0; i <rct; i++){
        for(int j = 0; j < cct; j++){
            if(rows[i][j] <= toleranceP && rows[i][j] >= toleranceN){
                fprintf(stdout, "r=%d, c=%d: %.6f\n", i ,j, rows[i][j]);
                count++;
            }
        }
    }
    fprintf(stdout, "Found %d approximate matches.\n", count);
}



#endif //LAB06_UTILS_H
//if(rows[i][j]<= val1 && rows[i][j] >= val2)