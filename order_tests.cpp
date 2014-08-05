#include "order.h"
#include <vector>
#include <string>
#include <random>
#include <cstdio>

std::vector<std::string> random_string(int size)
{
  std::vector<std::string> ans(size);
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(65, 90);
  for (int i=0; i < size; i++) {
    ans[i] = std::string("  ");
    ans[i][0] = (char) distribution(generator);
    ans[i][1] = (char) distribution(generator);
  }
  return ans;
}

std::vector<long> random_long(int size)
{
  std::vector<long> ans(size);
  std::default_random_engine generator;
  std::uniform_int_distribution<long> distribution(1,100);
  for (int i=0; i < size; i++) {
    ans[i] = distribution(generator);
  }
  return ans;
}

bool test_string(int size)
{
  bool ans = true;
  std::vector<std::string> strvec = random_string(size);
  std::vector<const char *> x(size);
  for (int i=0; i < size; i++) {
    x[i] = strvec[i].c_str();
  }
  std::vector<int> order(size);
  OrderC_string(&order[0], &x[0], size, 1);
  for (int i=1; i < size; i++) {
    // printf("%s %i\n", x[order[i]], (int) ans);
    ans = ans && (std::string(x[order[i]]) >= std::string(x[order[i-1]]));
  }
  return ans;
}

bool test_stringlong(int size)
{
  bool ans = true;
  std::vector<std::string> strvec = random_string(size);
  std::vector<const char *> x(size);
  for (int i=0; i < size; i++) {
    x[i] = strvec[i].c_str();
  }
  std::vector<long> lngvec = random_long(size);
  std::vector<int> order(size);
  OrderC_stringdate(&order[0], &x[0], &lngvec[0], size, 1);
  for (int i=1; i < size; i++) {
    // printf("%s %i %i\n", x[order[i]], lngvec[order[i]], ans);
    ans = ans && ((std::string(x[order[i]]) > std::string(x[order[i-1]])) || (std::string(x[order[i]]) == std::string(x[order[i-1]]) && lngvec[order[i]] >= lngvec[order[i-1]]));
    
  }
  return ans;
  
}

int main(int argc, char**argv)
{
  int size = 100000;
  printf("test_string = %s\n", test_string(size) ? "true" : "false");
  printf("test_stringlong = %s\n", test_stringlong(size) ? "true" : "false");
}
