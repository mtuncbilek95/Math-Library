#include <stdio.h>
#include "Math/Definitions/Definitions.h"
#include "Math/Dynamic Array/List.h"
#include "Math/Vectors and Matrices/Vector2.h"
#include "Math/Vectors and Matrices/Vector3.h"

int main(int argumentCount, char* argumentValue[])
{
    List<float> myArray1;
    
    for(unsigned i = 0; i<20; i++)
    {
        myArray1.Add((float)(i+1));
    }
    
    printf("Array: ");
    for(unsigned i = 0; i<myArray1.Size(); i++)
    {
        if(i == myArray1.Size()-1)
        {
            printf("%.0f.\n", myArray1[i]);
        }
        else
        {
            printf("%.0f, ", myArray1[i]);
        }
    }
    printf("Array size: %hu.\n", myArray1.Size());
    myArray1.Remove(17);

    printf("Array: ");
    for(unsigned i = 0; i<myArray1.Size(); i++)
    {
        if(i == myArray1.Size()-1)
        {
            printf("%.0f.\n", myArray1[i]);
        }
        else
        {
            printf("%.0f, ", myArray1[i]);
        }
    }
    printf("Array size: %hu \n", myArray1.Size());

    List<float> myArray2;
    
    for(unsigned i = 0; i<20; i++)
    {
        myArray2.Add((float)((i+1)*2));
    }
    
    printf("Array: ");
    for(unsigned i = 0; i<myArray2.Size(); i++)
    {
        if(i == myArray2.Size()-1)
        {
            printf("%.0f.\n", myArray2[i]);
        }
        else
        {
            printf("%.0f, ", myArray2[i]);
        }
    }
    printf("Array size: %hu.\n", myArray2.Size());
    myArray2.Remove(17);

    printf("Array: ");
    for(unsigned i = 0; i<myArray2.Size(); i++)
    {
        if(i == myArray2.Size()-1)
        {
            printf("%.0f.\n", myArray2[i]);
        }
        else
        {
            printf("%.0f, ", myArray2[i]);
        }
    }
    printf("Array size: %hu \n", myArray2.Size());
    
    List<List<float>> Arrays;

    Arrays.Add(myArray1);
    Arrays.Add(myArray2);
    
    printf("%f\n",Arrays[0][5]);
    Arrays.Swap(0,1);
    
    printf("%f\n",Arrays[0][5]);
    return 0;
}
