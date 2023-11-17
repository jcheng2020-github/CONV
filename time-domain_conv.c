//Junfu Cheng
//University of Florida
//Time-Domain Convolution Signal process

#include <stdio.h>

const int KERNEL_SIZE = 3;
const int SIGNAL_SIZE = 100;
const int RESULT_SIZE = SIGNAL_SIZE - (KERNEL_SIZE - 1);

int main()
{
    int kernel[KERNEL_SIZE];
    int signal[SIGNAL_SIZE];
    int result[RESULT_SIZE];
    
    //initialize kernel
    for(int i = 0; i < KERNEL_SIZE; i ++)
    {
        kernel[i] = i;
    }
    
    //initialize signal
    for(int i = 0; i < SIGNAL_SIZE; i ++)
    {
        signal[i] = i;
    }
    
    //initialize result
    for(int i = 0; i < RESULT_SIZE; i++)
    {
        result[i] = 0;
    }
    
    //time-domain conv
    for(int i = 0; i < RESULT_SIZE; i ++)
    {
        for(int j = 0; j < KERNEL_SIZE; j++)
        {
            result[i] += signal[i + j] * kernel[KERNEL_SIZE - 1 - j];
        }
    }
    
    //print result
    printf("result: \n");
    for(int i = 0; i < SIGNAL_SIZE - (KERNEL_SIZE - 1); i ++)
    {
        printf(" %d", result[i]);
    }
    printf("\n");
    return 0;
}
