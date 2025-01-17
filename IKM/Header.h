#include <iostream>
#include <vector>
#include <string>
#include <limits>

typedef std::vector<int> big;
#define MAX(a,b)( (a>b?a:b) )

void removeLeadingZeros(big& number);
bool greatest(const big& left, const big& right);
big sub(big left, const big& right);
big sum(const big& left, const big& right);
big mult(const big& left, const big& right);
big toBig(std::string inp);
big mult(const big& left, int right);
void shiftRight(big& number);
big div(const big& left, big right);
big mod(const big& left, const big& right);
big gcd(big left, big right);
std::string toStr(const big& num);
void func(big& num, big& den, const big& n);
big toBig(std::string inp);
bool isNumber(std::string str);
std::string uInp(std::string message, std::string error1, std::string error2);
std::string toStr(const big& num);
