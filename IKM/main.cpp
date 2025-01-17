#include "Header.h"

int main() {
    big num, den, n;
    while (true)
    {
        std::cout << "This program calculates the following function:\n 1    1    1    1    1          1\n-- + -- + -- + -- + -- + ... + --\n1!   2!   3!   4!   5!         n!\n";
        n = toBig(uInp("Enter n:", "Error: The line has wrong symbols!", "Error: The value of n has to be at least 1!"));
        func(num, den, n);
        std::cout << "Result:\n";
        std::string numS = toStr(num);
        std::string denS = toStr(den);
    
        std::cout << numS << "\n";
        std::string str(MAX(numS.size(), denS.size()), '-');
        std::cout << str << "\n";
        std::cout << denS << "\n\n";
    }
	return 0;
}