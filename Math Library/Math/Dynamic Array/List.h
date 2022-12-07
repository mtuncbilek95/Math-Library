// Copyright Metehan Tuncbilek, All Rights Reserved.

/*****************************************************************************************************
 *
 *  This is a standart Dynamic Array library which is created to use instead of std library.
 *
 *  Current capabilities:
 *  -   All written functions are working properly.
 *  -   [] operator is also working correctly.
 *
 *  W.I.P Features:
 *  -   Thinking about adding a Sort algorithm.
 *  
 *****************************************************************************************************/

#ifndef LIST_H
#define LIST_H


namespace MathLib
{
    template <typename T>
    class List
    {
    public:
        List();
        ~List() = default;

        void Init(unsigned initSize);
        unsigned Size() const;

        T& At(unsigned int index);
        T& operator[](const unsigned index);

        void Add(const T& element);
        void InsertFirst(const T& element);
        void InsertByIndex(const T& element, unsigned index);
        void RemoveFirst();
        void Remove(const unsigned index);
        void RemoveAll();

        void Swap(const unsigned& swapItemIndex1, const unsigned& swapItemIndex2);
    private:
        unsigned int maximumSize = 5;
        unsigned int currentSize;
        T* Array;

        void ChangeSize();
        void ClearMemory();
        unsigned MaxSize() const;
    };

    template <typename T>
    List<T>::List()
    {
        currentSize = 0;
        Array = new T[this->maximumSize];
    }

    template <typename T>
    void List<T>::Init(unsigned initSize)
    {
        maximumSize = initSize;
        Array = new T*[this->maximumSize];
    }

    template <typename T>
    unsigned List<T>::Size() const
    {
        return currentSize;
    }

    template <typename T>
    unsigned List<T>::MaxSize() const
    {
        return maximumSize;
    }

    template <typename T>
    T& List<T>::At(unsigned index)
    {
        return Array[index];
    }

    template <typename T>
    T& List<T>::operator[](const unsigned index)
    {
        return Array[index];
    }

    template <typename T>
    void List<T>::Add(const T& element)
    {
        if (currentSize == maximumSize)
        {
            ChangeSize();
        }
        Array[currentSize] = element;
        currentSize++;
    }

    template <typename T>
    void List<T>::InsertFirst(const T& element)
    {
        InsertByIndex(element, 0);
    }

    template <typename T>
    void List<T>::InsertByIndex(const T& element, unsigned index)
    {
        if (currentSize == maximumSize)
        {
            maximumSize *= 2;
        }

        T* Temp = new T[maximumSize];

        for (unsigned i = 0; i < currentSize; i++)
        {
            Temp[i] = Array[i];
        }

        ClearMemory();
        Array = new T[maximumSize];

        for (unsigned i = 0; i < index; i++)
        {
            Array[i] = Temp[i];
        }

        Array[index] = element;

        for (unsigned i = index; i < currentSize; i++)
        {
            Array[i + 1] = Temp[i];
        }
        delete[] Temp;
        currentSize ++;
    }

    template <typename T>
    void List<T>::RemoveFirst()
    {
        for (unsigned i = 0; i < currentSize - 1; i++)
        {
            Array[i] = Array[i + 1];
        }
        currentSize--;
    }

    template <typename T>
    void List<T>::Remove(const unsigned order)
    {
        if (order >= currentSize)
        {
            throw "Out of Range";
        }

        for (unsigned i = order; i < currentSize; i++)
        {
            Array[i - 1] = Array[i];
        }
        currentSize--;
    }

    template <typename T>
    void List<T>::RemoveAll()
    {
        ClearMemory();
        maximumSize = 5;
        currentSize = 0;
    }

    template <typename T>
    void List<T>::Swap(const unsigned& swapItemIndex1, const unsigned& swapItemIndex2)
    {
        if (swapItemIndex1 >= currentSize || swapItemIndex1 <= currentSize)
        {
            throw "Out of Range";
        }
        T TempData = Array[swapItemIndex1];

        Array[swapItemIndex1] = Array[swapItemIndex2];
        Array[swapItemIndex2] = TempData;
    }

    template <typename T>
    void List<T>::ChangeSize()
    {
        T* TempData = nullptr;
        if (currentSize == maximumSize)
        {
            TempData = new T[maximumSize];
            {
                for (unsigned i = 0; i < currentSize; i++)
                {
                    TempData[i] = Array[i];
                }
            }

            ClearMemory();

            maximumSize = maximumSize * 2;
            Array = new T[maximumSize];

            for (unsigned i = 0; i < currentSize; i++)
            {
                Array[i] = TempData[i];
            }
            delete[] TempData;
        }
    }

    template <typename T>
    void List<T>::ClearMemory()
    {
        if (Array == nullptr)
            return;

        delete[] Array;
    }
}

using namespace MathLib;

#endif
