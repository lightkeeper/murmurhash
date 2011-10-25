// Compile with:
// gcc -o MurmurHash3.so -DPLATFORM64 -fPIC -shared MurmurHash3.cpp MurmurHash3_wrapper.cpp

#include "MurmurHash3.h"

// Microsoft Visual Studio
#if defined(_MSC_VER)

#define PREFIX __declspec(dllexport) 
#define PLATFORM64

#else
// Other compilers
#define PREFIX 

#endif

extern "C" {
   PREFIX void MurmurHash3_128_wrapper(const void *key, uint32_t len, uint32_t seed, void *out);
}


void MurmurHash3_128_wrapper(const void *key, uint32_t len, uint32_t seed, void *out)
{
#if defined(PLATFORM64)
   MurmurHash3_x64_128(key, len, seed, out);
#else
   MurmurHash3_x86_128(key, len, seed, out);
#endif
}

