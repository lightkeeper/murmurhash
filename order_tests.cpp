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
    char s[2] = {(char) distribution(generator), (char) distribution(generator)};
    ans[i] = s[2];
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
    ans = ans && (x[order[i]] >= x[order[i-1]]);
  }
  return ans;
}

bool test_stringlong(int size)
{
  return true;
}

int main(int argc, char**argv)
{
  int size = 10;
  printf("test_string = %s\n", test_string(size) ? "true" : "false");

}
