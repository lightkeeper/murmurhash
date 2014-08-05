#include "order.h"

void OrderC_int(int* order, int* x, int len, int asc)
{   
   for (int i=0; i < len; i++) {order[i] = i;}
   if (asc) {
     std::stable_sort(order, order + len, [&x](size_t i, size_t j) -> bool {return x[i] < x[j];});
   } else {
     std::stable_sort(order, order + len, [&x](size_t i, size_t j) -> bool {return x[i] > x[j];});
   }
}  

void OrderC_long(int* order, bigOrder* x, int len, int asc)
{   
   for (int i=0; i < len; i++) {order[i] = i;}
   if (asc) {
     std::stable_sort(order, order + len, [&x](size_t i, size_t j) -> bool {return x[i] < x[j];});
   } else {
     std::stable_sort(order, order + len, [&x](size_t i, size_t j) -> bool {return x[i] > x[j];});
   }
}  

void OrderC_double(int *order, double *x, int len, int asc)
{   
   for (int i=0; i < len; i++) {order[i] = i;}
   if (asc) {
     std::stable_sort(order, order + len, [&x](size_t i, size_t j) -> bool {return x[i] < x[j];});
   } else {
     std::stable_sort(order, order + len, [&x](size_t i, size_t j) -> bool {return x[i] > x[j];});
   }
}
  
void OrderC_string(int* order, const char** x, int len, int asc)
{   
   std::vector<std::string> str(len);
   for (int i=0; i < len; i++) {order[i] = i; str[i] = x[i];}
   if (asc) {
     std::stable_sort(order, order + len, [&str](size_t i, size_t j) -> bool {return str[i] < str[j];});
   } else {
     std::stable_sort(order, order + len, [&str](size_t i, size_t j) -> bool {return str[i] > str[j];});
   }
}  

void OrderC_double2(int *order, double *x, double *y, int len, int asc)
{   
   for (int i=0; i < len; i++) {order[i] = i;}
   if (asc) {
     std::stable_sort(order, order + len, [&x, &y](size_t i, size_t j) -> bool {return (x[i] == x[j]) ? (y[i] < y[j]) : (x[i] < x[j]);});
   } else {
     std::stable_sort(order, order + len, [&x, &y](size_t i, size_t j) -> bool {return (x[i] == x[j]) ? (y[i] > y[j]) : (x[i] > x[j]);});
   }
}  

void OrderC_stringdate(int *order, const char **x, bigOrder *y, int len, int asc)
{   
  std::vector<std::string> str(len);
  for (int i=0; i < len; i++) {order[i] = i; str[i] = x[i];}
  if (asc) {
    std::stable_sort(order, order + len, [&str, &y](size_t i, size_t j) -> bool {return (str[i] == str[j]) ? (y[i] < y[j]) : (str[i] < str[j]);});
  } else {
     std::stable_sort(order, order + len, [&str, &y](size_t i, size_t j) -> bool {return (str[i] == str[j]) ? (y[i] > y[j]) : (str[i] > str[j]);});
  }
}  

void OrderC_wstringdate(int *order, const wchar_t **x, bigOrder *y, int len, int asc)
{   
  std::vector<std::wstring> str(len);
  for (int i=0; i < len; i++) {order[i] = i; str[i] = x[i];}
  if (asc) {
    std::stable_sort(order, order + len, [&str, &y](size_t i, size_t j) -> bool {return (str[i] == str[j]) ? (y[i] < y[j]) : (str[i] < str[j]);});
  } else {
    std::stable_sort(order, order + len, [&str, &y](size_t i, size_t j) -> bool {return (str[i] == str[j]) ? (y[i] > y[j]) : (str[i] > str[j]);});
  }
}  

