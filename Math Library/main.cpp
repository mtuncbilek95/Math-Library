#include <condition_variable>
#include <iostream>
#include <stdio.h>
#include "Math/Definitions/Definitions.h"
#include "Math/Dynamic Array/List.h"
#include "Math/Vectors and Matrices/Vector2.h"
#include "Math/Vectors and Matrices/Vector3.h"



void PrintArray(List<float> Array);

int main(int argumentCount, char* argumentValue[])
{
    
    List<float> myArray1;
    
    for(unsigned i = 0; i<20; i++)
    {
        myArray1.Add((float)(i+1));
    }

    myArray1.RemoveFirst();

    PrintArray(myArray1);
    return 0;
}

void PrintArray(List<float> Array)
{
    printf("Array: ");
    
    printf("Array size: %hu \n", Array.Size());
}