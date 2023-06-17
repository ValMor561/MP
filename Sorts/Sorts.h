#pragma once
#include "pch.h"

template<typename IterType>//+
void Sh1sort(IterType begin, IterType end);

template<typename IterType>//+
void Sh2sort(IterType begin, IterType end);

template<typename IterType>//+
void HeapSort(IterType begin, IterType end);

template<typename IterType>//+
void Qsort(IterType begin, IterType end);

template<typename IterType>//+
void Hsort(IterType begin, IterType end);

template<typename IterType>//+
void SVsort(IterType begin, IterType end);

template<typename IterType>//+
void SNsort(IterType begin, IterType end);

template<typename IterType>
void LSD(IterType begin, IterType end);

template<typename IterType>
void STLheap_sort(IterType begin, IterType end);



template<typename IterType>
void Sh1sort(IterType begin, IterType end)
{
    size_t size = std::distance(begin, end);
    int* stepArr = new int[size];
    int index = 0;
    stepArr[index] = 1;
    while (stepArr[index] < size / 3)
    {
        stepArr[index + 1] = 3 * stepArr[index] + 1;
        ++index;
    }
    auto iterI = begin;
    auto iterJ = begin;
    auto temp = *begin;
    auto tempIter = begin;
    auto first = begin;
    for (int i = index - 1; i >= 0; --i)
    {
        for (size_t j = 0; j < stepArr[i]; ++j)
        {
            if (std::distance(first, end) <= stepArr[i])
                break;
            iterI = first;
            std::advance(iterI, stepArr[i]);
            while (iterI != end)
            {
                temp = *iterI;
                iterJ = iterI;
                while (iterJ != first && *iterJ >= temp)
                {
                    tempIter = iterJ;
                    std::advance(tempIter, -1 * stepArr[i]);
                    *iterJ = *tempIter;
                    iterJ = tempIter;
                }
                if (iterJ != first || *first < temp)
                    std::advance(iterJ, stepArr[i]);
                *iterJ = temp;
                if (std::distance(iterI, end) <= stepArr[i])
                    break;
                std::advance(iterI, stepArr[i]);
            }
            ++first;
        }
        first = begin;
    }
}

template<typename IterType>
void Sh2sort(IterType begin, IterType end)
{
    size_t size = std::distance(begin, end);
    int* stepArr = new int[size];
    int index = 0;
    stepArr[index] = 1;
    while (stepArr[index] < size / 3)
        stepArr[index++ + 1] = 2 * stepArr[index] + 1;
    auto iterI = begin;
    auto iterJ = begin;
    auto temp = *begin;
    auto tempIter = begin;
    auto first = begin;
    for (int i = index - 1; i >= 0; --i)
    {
        for (size_t j = 0; j < stepArr[i]; ++j)
        {
            if (std::distance(first, end) <= stepArr[i])
                break;
            iterI = first;
            std::advance(iterI, stepArr[i]);
            while (iterI != end)
            {
                temp = *iterI;
                iterJ = iterI;
                while (iterJ != first && *iterJ >= temp)
                {
                    tempIter = iterJ;
                    std::advance(tempIter, -1 * stepArr[i]);
                    *iterJ = *tempIter;
                    iterJ = tempIter;
                }
                if (iterJ != first || *first < temp)
                    std::advance(iterJ, stepArr[i]);
                *iterJ = temp;
                if (std::distance(iterI, end) <= stepArr[i])
                    break;
                std::advance(iterI, stepArr[i]);
            }
            ++first;
        }
        first = begin;
    }
}


template<typename IterType>
void makeHeap(IterType root, size_t index, size_t size)
{
    auto left = root;
    auto right = root;
    std::advance(left, index + 1);
    std::advance(right, index + 2);
    auto max = root;
    if (*left > * max)
        max = left;
    if (std::distance(root, right) + index < size && *right > * max)
        max = right;
    if (max != root)
    {
        std::swap(*root, *max);
        size_t indexMax = std::distance(root, max) + index;
        if (indexMax <= size / 2 - 1)
            makeHeap(max, indexMax, size);
    }
}

template<typename IterType>
void heap(IterType begin, IterType end)
{
    int size = std::distance(begin, end);
    int stop = size / 2 - 1;
    auto step = begin;
    std::advance(step, stop + 1);
    for (int i = stop; i >= 0; --i)
        makeHeap(--step, i, size);
}

template<typename IterType>
void pop(IterType first, IterType last)
{
    --last;
    std::swap(*first, *last);
    heap(first, last);
}

template<typename IterType>
void HeapSort(IterType begin, IterType end)
{
    auto stop = begin;
    ++stop;
    heap(begin, end);
    while (stop != end)
        pop(begin, end--);
}



template<typename IterType>
void Qsort(IterType begin, IterType end)
{
    --end;
    int i = -1;
    int size = std::distance(begin, end);
    int sizeL;
    int sizeR;
    IterType* stack = new IterType[2 * log2(size + 1)];
    auto L = begin;
    auto R = end;
    while (1)
    {
        if (size <= 1)
        {
            if (size == 1 && *L > * R)
                std::swap(*L, *R);
            if (i < 0)
                break;
            R = stack[i--];
            L = stack[i--];
            size = std::distance(L, R);
        }
        auto left = L;
        auto right = R;
        auto keyI = left;
        std::advance(keyI, size / 2);
        auto key = *keyI;
        while (size >= 0)
        {
            while (left != right && *left < key)
                ++left;
            while (right != left && *right > key)
                --right;
            if (left != right)
                std::swap(*left, *right);
            else
                break;
            ++left;
            --right;
            size = std::distance(left, right);
        }
        sizeL = std::distance(L, right);
        sizeR = std::distance(left, R);
        if (sizeL < sizeR)
        {
            if (sizeR == 1)
            {
                if (*left > * R)
                    std::swap(*left, *R);
            }
            else
            {
                stack[++i] = left;
                stack[++i] = R;
            }
            R = right;
            size = sizeL;
        }
        else
        {
            if (sizeL == 1)
            {
                if (*L > * right)
                    std::swap(*L, *right);
            }
            else
            {
                stack[++i] = L;
                stack[++i] = right;
            }
            L = left;
            size = sizeR;
        }
    }
}

template<typename IterType>
void Hsort(IterType begin, IterType end)
{

    int size = std::distance(begin, end) - 1;
    if (size < 1)
        return;
    --end;
    if (size == 1)
    {
        if (*begin > * end)
            std::swap(*begin, *end);
        return;
    }
    auto keyI = begin;
    std::advance(keyI, size / 2);
    auto key = *keyI;
    auto left = begin;
    auto right = end;
    auto eqL = begin;
    auto eqR = end;
    while (size >= 0)
    {
        while (left != right && *left <= key)
        {
            if (*left == key)
                std::swap(*eqL++, *left);
            ++left;
        }
        while (right != left && *right >= key)
        {
            if (*right == key)
                std::swap(*eqR--, *right);
            --right;
        }
        if (left != right)
            std::swap(*left, *right);
        else
            break;
        ++left;
        --right;
        size = std::distance(left, right);
    }
    if (*right >= key && right != begin)
        --right;
    if (*left <= key)
        ++left;
    while (eqL != begin && right != begin)
        std::swap(*--eqL, *right--);

    while (eqR != end)
        std::swap(*++eqR, *left++);
    ++end;
    Hsort(begin, ++right);
    Hsort(left, end);
}



template<typename IterType>
void SVsort(IterType begin, IterType end)
{
    auto size = std::distance(begin, end);
    typedef typename std::iterator_traits<IterType>::value_type T;
    if (size <= 1)
        return;
    if (size == 2)
    {
        --end;
        if (*begin > * end)
            std::swap(*begin, *end);
        return;
    }
    auto middle = begin;
    std::advance(middle, size / 2);
    SVsort(begin, middle);
    SVsort(middle, end);

    int sizeL = std::distance(begin, middle);
    int sizeR = std::distance(middle, end);
    T* tempL = new T[sizeL];
    T* tempR = new T[sizeR];
    auto iter = begin;
    int index = 0;
    while (iter != end)
    {
        if (index < sizeL)
            tempL[index++] = *iter++;
        else
            tempR[index++ - sizeL] = *iter++;
    }
    iter = begin;
    int j = 0;
    int i = 0;
    while (j + i < size)
    {
        if (j < sizeL && i < sizeR)
        {
            if (tempL[j] < tempR[i])
                *iter++ = tempL[j++];
            else
                *iter++ = tempR[i++];
        }
        else if (j < sizeL)
            *iter++ = tempL[j++];
        else
            *iter++ = tempR[i++];
    }
    delete[]tempL;
    delete[]tempR;
}

template<typename IterType>
void SNsort(IterType begin, IterType end)
{
    auto size = std::distance(begin, end);
    typedef typename std::iterator_traits<IterType>::value_type T;
    T* tempL = new T[size];
    T* tempR = new T[size];
    int tempSize = 1;
    auto iter = begin;
    int j = 0;
    int i = 0;
    int sizeL = 0;
    int sizeR = 0;
    while (tempSize < size)
    {
        while (j < tempSize && iter != end)
            tempL[j++] = *iter++;
        while (i < tempSize && iter != end)
            tempR[i++] = *iter++;
        sizeL = j;
        sizeR = i;
        j = 0;
        i = 0;
        std::advance(iter, -1 * (sizeL + sizeR));
        while (i + j < sizeL + sizeR)
        {
            if (j < sizeL && i < sizeR)
            {
                if (tempL[j] < tempR[i])
                    *iter++ = tempL[j++];
                else
                    *iter++ = tempR[i++];
            }
            else if (j < sizeL)
                *iter++ = tempL[j++];
            else
                *iter++ = tempR[i++];
        }
        i = 0;
        j = 0;
        if (iter == end)
        {
            iter = begin;
            tempSize *= 2;
        }
    }
    delete[]tempL;
    delete[]tempR;
}


template<typename IterType>
void LSD(IterType begin, IterType end)
{
    int size = std::distance(begin, end);
    std::string* strArr = new std::string[size];
    int* sizeArr = new int[size];
    int* indexArr = new int[size];
    auto iter = begin;
    int maxSize = 0;
    for (int i = 0; i < size; )
    {
        strArr[i] = *iter++;
        sizeArr[i] = strArr[i].size();
        if (sizeArr[i] - 1 > maxSize)
            maxSize = sizeArr[i];
        indexArr[i] = ++i;
    }
    indexArr[size - 1] = -1;
    int queue1[4][255];
    for (int i = 0; i < 255; ++i)
    {
        queue1[0][i] = -1;
        queue1[1][i] = -1;
        queue1[2][i] = -1;
        queue1[3][i] = -1;
    }
    int indexQueue = 0;
    int index;
    int stepIndex = maxSize - 1;
    for (int i = 0; i < size; ++i)
    {
        index = (sizeArr[i] - 1 < stepIndex) ? 0 : (int)strArr[i][stepIndex];
        if (queue1[indexQueue][index] == -1)
            queue1[indexQueue][index] = i;
        else
            indexArr[queue1[indexQueue + 1][index]] = i;
        queue1[indexQueue + 1][index] = i;
        indexArr[i] = -1;
    }
    --stepIndex;
    int indexQ;
    int temp;
    while (stepIndex != -1)
    {
        for (int i = 0; i < 255; ++i)
        {
            if (queue1[indexQueue % 4][i] == -1)
                continue;
            indexQ = queue1[indexQueue % 4][i];
            while (indexQ != -1)
            {
                index = (sizeArr[indexQ] - 1 < stepIndex) ? 0 : (int)strArr[indexQ][stepIndex];
                if (queue1[(indexQueue + 2) % 4][index] == -1)
                    queue1[(indexQueue + 2) % 4][index] = indexQ;
                else
                    indexArr[queue1[(indexQueue + 3) % 4][index]] = indexQ;
                queue1[(indexQueue + 3) % 4][index] = indexQ;
                temp = indexArr[indexQ];
                indexArr[indexQ] = -1;
                indexQ = temp;
            }
        }
        for (int i = 0; i < 255; ++i)
        {
            queue1[indexQueue % 4][i] = -1;
            queue1[(indexQueue + 1) % 4][i] = -1;
        }
        --stepIndex;
        indexQueue = indexQueue + 2;
    }
    iter = begin;
    for (int i = 0; i < 255; ++i)
    {
        if (queue1[indexQueue % 4][i] == -1)
            continue;
        indexQ = queue1[indexQueue % 4][i];
        while (indexQ != -1)
        {
            *iter++ = strArr[indexQ];
            indexQ = indexArr[indexQ];
        }
    }
}



template<typename IterType>
void STLheap_sort(IterType begin, IterType end)
{
    std::make_heap(begin, end);
    std::sort_heap(begin, end);
}