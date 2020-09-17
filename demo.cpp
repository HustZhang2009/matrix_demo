#include <iostream>
#include <stdlib.h>
#include "matrix.h"

int main(int argc,char** argv)
{
    std::cout << "test matrix demo ...... " << std::endl;

    int32_t m = 5;
    int32_t n = 10;
    Matrix mat(m,n);
    std::cout << mat << std::endl;

    // set matrixr value to rand()
    std::cout << "---------" << std::endl;
    for(int i=0;i<m;i++)
    {
       for(int j=0;j<n;j++)
       {
           mat.val[i][j] = (double)rand() / RAND_MAX;
       } 
    }
    std::cout << mat << std::endl;

    // test getData
    std::cout << "---------" << std::endl;
    FLOAT* val_ptr = (FLOAT*)malloc(m*n*sizeof(FLOAT));
    mat.getData(val_ptr);
    for(int i=0;i<m*n;i++)
    {
        std::cout << val_ptr[i];
        if(i!=0&&(i%(n-1)==0))
        {
            std::cout << "\n";
        }else
        {
            std::cout << "\t";
        }
    }
    std::cout << std::endl;

    // test operator *
    std::cout << "---------" << std::endl;
    Matrix mat2(n,m,val_ptr);
    Matrix mat3 = mat * mat2;
    std::cout << mat3 << std::endl;

    return 0;
}