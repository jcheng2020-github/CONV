//Junfu Cheng
//University of Florida
//CONV2D

#include <stdio.h>


const int KERNEL_SIZE = 3;
const int SIGNAL_SIZE = 10;
const int STRIDE = 1;
const int PADDING = 0;
const int DILATION = 1;

const int RESULT_TEMPLATE_SIZE = SIGNAL_SIZE + (PADDING * 2);
const int RESULT_SIZE = ( RESULT_TEMPLATE_SIZE - (KERNEL_SIZE * DILATION - 1) ) / STRIDE;

int main()
{
    
    int kernel[KERNEL_SIZE][KERNEL_SIZE];
    int signal[SIGNAL_SIZE][SIGNAL_SIZE];
    int result[RESULT_SIZE][RESULT_SIZE];
    int result_template[RESULT_TEMPLATE_SIZE][RESULT_TEMPLATE_SIZE];
    
    //initialize kernel
    for(int i = 0; i < KERNEL_SIZE; i ++)
    {
        for(int j = 0; j < KERNEL_SIZE; j ++)
        {
            kernel[i][j] = i + j;
        }
    }
    
    //initialize signal
    for(int i = 0; i < SIGNAL_SIZE; i ++)
    {
        for(int j = 0; j < SIGNAL_SIZE; j ++)
        {
            signal[i][j] = i + j;
        }
    }
    
    //initialize reuslt_template
    for(int i = 0; i < RESULT_TEMPLATE_SIZE; i ++)
    {
        for(int j = 0; j < RESULT_TEMPLATE_SIZE; j ++)
        {
            if(i < PADDING || i >= SIGNAL_SIZE || j < PADDING || j >= SIGNAL_SIZE)
            {
                result_template[i][j] = 0;
            }
            else
            {
                result_template[i][j] = signal[i - PADDING][j - PADDING];
            }
        }
    }
    
    //initialize result
    for(int i = 0; i < RESULT_SIZE; i++)
    {
        for(int j = 0; j < RESULT_SIZE; j ++)
        {
            result[i][j] = 0;
        }
    }
    
    //CONV2D
    for(int i = 0; i < RESULT_SIZE; i ++)
    {
        for(int j = 0; j < RESULT_SIZE; j++)
        {
            for(int k = 0; k < KERNEL_SIZE; k ++)
            {
                for(int l = 0; l < KERNEL_SIZE; l ++)
                {
                    result[i][j] += result_template[i * STRIDE + k * DILATION][j * STRIDE + l * DILATION] * kernel[k][l];
                }
            }
        }
    }
    
    //print result
    printf("result: \n");
    for(int i = 0; i < RESULT_SIZE; i ++)
    {
        for(int j = 0; j < RESULT_SIZE; j ++)
        {
            printf(" %d", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}