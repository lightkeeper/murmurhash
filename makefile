# This builds a shared library with a wrapper for MurmurHash3  128-bit hash.

all: base64

base64:
	gcc -o MurmurHash3.so -DPLATFORM64 -fPIC -shared MurmurHash3.cpp MurmurHash3_wrapper.cpp

base32:
	gcc -o MurmurHash3.so -fPIC -shared MurmurHash3.cpp MurmurHash3_wrapper.cpp

mac:
	gcc -arch i386 -arch x86_64 -lstdc++ -o MurmurHash3.so -fPIC -shared MurmurHash3.cpp MurmurHash3_wrapper.cpp
