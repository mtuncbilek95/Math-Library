// Copyright Metehan Tuncbilek, All Rights Reserved.

/*****************************************************************************************************
 *
 *  This is a standart Dynamic Array Sorting Library which is created to use with the current array library.
 *  
 *****************************************************************************************************/

#ifndef SORT_H
#define SORT_H

namespace MathLib
{
    class Sort
    {
    public:
        template <typename ArrayTemp>
        static void BubbleSort(ArrayTemp& arrayValue);
        template <typename ArrayTemp, typename TValue>
        static void QuickSort(ArrayTemp& arrayValue, TValue min, TValue max);
        template <typename ArrayTemp>
        static void SelectionSort(ArrayTemp& arrayValue);
        template <typename ArrayTemp>
        static void InsertionSort(ArrayTemp& arrayValue);
        template <typename ArrayTemp>
        static void MergeSort(ArrayTemp& arrayValue);

    private:
        template <typename TValue>
        static void Swap(TValue& v1, TValue& v2);
    };

    template <typename ArrayTemp>
    void Sort::BubbleSort(ArrayTemp& arrayValue)
    {
        for(unsigned i = 0; i < arrayValue.Size() - 1; i++)
        {
            for(unsigned j = 0; j < arrayValue.Size() - i - 1; j++)
            {
                if(arrayValue[j] > arrayValue[j+1])
                    Sort::Swap(arrayValue[j], arrayValue[j+1]);
            }
        }
    }

    template <typename TValue>
    void Sort::Swap(TValue& v1, TValue& v2)
    {
        TValue temp = v1;
        v1 = v2;
        v2 = temp;
    }
}

#endif