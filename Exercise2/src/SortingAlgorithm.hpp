#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {
    template<typename T>
    concept Sortable = requires(T& t) {
        {t < t} -> std::convertible_to<bool>;
    };
    
    template<Sortable T>
    void BubbleSort(std::vector<T>& v)
    {
        const unsigned int n = v.size();
        for (unsigned int i = 0; i < n - 1; i++) 
        {
            for (unsigned int j = i+1; j < n; j++) 
            {
                if (v[j] < v[i]) 
                {
                    // swap:
                    T tmp = v[i];
                    v[i] = v[j];
                    v[j] = tmp;
                }
            }
        }
    }
    
    template<Sortable T>
    void HeapSort(std::vector<T>& v)
    {
        const unsigned int n = v.size();

        for (int i = n / 2 - 1; i >= 0; i--) 
        {
            unsigned int maxheap = i;
            while (true) 
            {
                unsigned int left = 2 * maxheap + 1;
                unsigned int right = 2 * maxheap + 2;
                unsigned int largest = maxheap;

                if (left < n && v[left] > v[largest])
                    largest = left;
                if (right < n && v[right] > v[largest])
                    largest = right;

                if (largest == maxheap) 
                    break;

                // swap:
                T tmp = v[maxheap];
                v[maxheap] = v[largest];
                v[largest] = tmp;

                maxheap = largest;
            }
        }

        for (int i = n - 1; i > 0; i--) 
        {
            T tmp = v[0];
            v[0] = v[i];
            v[i] = tmp;

            unsigned int maxheap = 0;
            while (true) 
            {
                unsigned int left = 2 * maxheap + 1;
                unsigned int right = 2 * maxheap + 2;
                unsigned int largest = maxheap;

                if (left < i && v[left] > v[largest]) 
                    largest = left;
                if (right < i && v[right] > v[largest])
                    largest = right;

                if (largest == maxheap) 
                    break;

                // swap:
                tmp = v[maxheap];
                v[maxheap] = v[largest];
                v[largest] = tmp;

                maxheap = largest;
            }
        }
    }    
}




