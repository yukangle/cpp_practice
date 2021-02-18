#ifndef VECTOR_H
#define VECTOR_H

#include <memory>

namespace kangleyu {
    // pseudo-implementation of memory allocation strategy for a vector-like class
    template <class T> class Vector 
    {

    public:
        Vector(): elements(0), first_free(0), end(0) { }
        void push_back(const T&);

    private:
        // object to get raw memory
        static std::allocator<T> alloc;
        // get more space and copy existing elements
        void reallocate();
        // pointer to first element in the array
        T* elements;
        // pointer to first free element in the array
        T* first_free;
        // pointer to one past the end of the array
        T* end;
    };

    template <class T> void Vector<T>::push_back(const T &t) {
        if (first_free == end) {
            reallocate();
        }
        alloc.construct(first_free, t);
        ++first_free;
    }

    template <class T> void Vector<T>::reallocate() {
        // compute size of current array and allocate space for twice as many elements
        std::ptrdiff_t size = first_free - elements;
        std::ptrdiff_t newcapacity = 2 * std::max(static_cast<int>(size), 1);

        // allocate space to hold newcapacity number of elements of type T
        T* newelements = alloc.allocate(newcapacity);

        // construct copies of the existing elements in the new space
        std::uninitialized_copy(elements, first_free, newelements);
        // destroy the old elements in reverse order
        for (T *p = first_free; p != elements; ) {
            alloc.destroy(--p);
        }

        // deallocate cannot be called on a 0 pointer
        if (elements) {
            alloc.deallocate(elements, end - elements);
        }

        // make our data structure point to the new elements
        elements = newelements;
        first_free = elements + size;
        end = elements + newcapacity;
    }
}

#endif