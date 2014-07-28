# This builds a shared library with a wrapper for MurmurHash3  128-bit hash.

all: base64

base64:
	gcc -o MurmurHash3.so -DPLATFORM64 -fPIC -shared -std=c++0x MurmurHash3.cpp order.cpp MurmurHash3_wrapper.cpp -lstdc++

base64Debug:
	gcc -g -o MurmurHash3.so -DPLATFORM64 -fPIC -shared -std=c++0x MurmurHash3.cpp order.cpp MurmurHash3_wrapper.cpp -lstdc++

base32:
	gcc -o MurmurHash3.so -fPIC -shared -std=c++0x MurmurHash3.cpp order.cpp MurmurHash3_wrapper.cpp  -lstdc++

base32:
	gcc -g -o MurmurHash3.so -fPIC -shared -std=c++0x MurmurHash3.cpp order.cpp MurmurHash3_wrapper.cpp  -lstdc++

mac:
	gcc -arch i386 -arch x86_64 -std=c++0x -lstdc++ -o MurmurHash3.so -fPIC -shared MurmurHash3.cpp order.cpp MurmurHash3_wrapper.cpp -lstdc++
