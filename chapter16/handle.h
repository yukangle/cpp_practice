#ifndef HANDLE_H
#define HANDLE_H

#include <stdexcept>

using std::runtime_error;

/* generic handle class: Provides pointerlink behavior. Althrough access through
 * an unbound Handle is checked and throws a runtime_error exception.
 * The objec tto which the Handle points is deleted when the last Handle goes away
 * Users should allocate new objects of type T and bind them to a Handle.
 * Once an object is bound to a Handle, the user must not delete that object.
 */
template <class T> class Handle
{
public:
    //unbound handle
    Handle(T *p = 0): ptr(p), use(new size_t(1)) { }

    // overloaded operators to support pointer behavior
    T& operator*();
    T* operator->();
    const T& operator*() const;
    const T* operator->() const;

    // copy control: normal pointer behavior, but last Handle deletes the object
    Handle(const Handle &h): ptr(h.ptr), use(h.use) {
        ++*use;
    }
    Handle& operator=(const Handle&);
    ~Handle() {
        rem_ref();
    }

private:
    // shared object
    T * ptr;
    // count of how many handles point to *ptr
    size_t *use;
    void rem_ref() {
        if (--*use == 0) {
            delete ptr;
            delete use;
        }
    }
};

template <class T> inline Handle<T>& Handle<T>::operator=(const Handle &rhs) {
    // protect against self-assignment
    ++*rhs.use;
    // decrement use count and delete pointers if needed
    rem_ref();
    ptr = rhs.ptr;
    use = rhs.use;
    return *this;
}

template <class T> inline T& Handle<T>::operator*() {
    if (ptr) {
        return *ptr;
    } else {
        throw runtime_error("dereference of unbound Handle");
    }
}

template <class T> inline T* Handle<T>::operator->() {
    if (ptr) {
        return ptr;
    } else {
        throw runtime_error("access through unbound Handle");
    }
}

template <class T> inline const T& Handle<T>::operator*() const {
    if (ptr) {
        return *ptr;
    } else {
        throw runtime_error("dereference of unbound Handle");
    }
}

template <class T> inline const T* Handle<T>::operator->() const  {
    if (ptr) {
        return ptr;
    } else {
        throw runtime_error("access through unbound Handle");
    }
}

#endif