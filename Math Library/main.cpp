#include <iostream>
#include <vector>

#include "Math/Dynamic Array/List.h"
#include "Math/Functions/Sort.h"

int main(int argumentCount, char* argumentValue[])
{
    List<int> myList;
    myList.Add(4);
    myList.Add(6);
    myList.Add(1);
    myList.Add(2);
    myList.Add(7);
    myList.Add(3);
    myList.Add(5);

    std::vector<int> a = {5,7,3,1,4,2,6};

    MathLib::Sort::BubbleSort(myList);

    for (unsigned i = 0; i < myList.Size(); i++)
        std::cout << myList[i] << std::endl;
    
    return 0;
}
