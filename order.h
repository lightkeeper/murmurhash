#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

#ifndef ORDER_HEADER
#define ORDER_HEADER

// gcc -shared -o order.so -std=c++0x -fPIC -DPLATFORM64 order.cpp
// Microsoft Visual Studio
#if defined(_MSC_VER)

#define PREFIX __declspec(dllexport) 
#define PLATFORM64

#else
// Other compilers
#define PREFIX 

#endif

extern "C" {
  PREFIX void OrderC_int(int* order, int* x, int len, int asc);
  PREFIX void OrderC_long(int* order, long *x, int len, int asc);
  PREFIX void OrderC_double(int *order, double *x, int len, int asc);
  PREFIX void OrderC_double2(int *order, double *x, double *y, int len, int asc);
  PREFIX void OrderC_string(int* order, const char** x, int len, int asc);
  PREFIX void OrderC_stringdate(int *order, const char **x, long *y, int len, int asc);
  PREFIX void OrderC_wstringdate(int *order, const wchar_t **x, long *y, int len, int asc);
}

#endif
