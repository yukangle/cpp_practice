#ifndef UTILITIES_H
#define UTILITIES_H

#include <cstring>

template <typename T> int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

// special version of compare to handle C-style character strings
template <> int compare<const char*>(const char* const &v1, const char* const &v2) {
    return strcmp(v1, v2);
}

#endif