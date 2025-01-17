#include <iostream>
#include <vector>
#include <string>
#include <limits>

typedef std::vector<int> big;
#define MAX(a,b)( (a>b?a:b) )

//Убирает незначащие нули в длинном числе
void removeLeadingZeros(big& number) {
    while (number.size() > 1 && number.back() == 0) {
        number.pop_back();
    }
}
//Возвращает true если левое число больше правого
bool greatest(const big& left, const big& right) {
    if (left.size() > right.size()) return true;
    else if (left.size() < right.size()) return false;
    for (int i = left.size() - 1; i >= 0; i--)
    {
        if (left[i] > right[i]) return true;
        else if (left[i] < right[i]) return false;
    }
    return false;
}
//Вычитание длинных чисел
big sub(big left, const big& right) {
    big result = left;
    for (int i = 0; i < result.size(); i++)
    {
        result[i] = left[i] - (i < right.size() ? right[i] : 0);
        if (result[i] < 0)
        {
            result[i] += 1000000000;
            left[i + 1]--;
        }
    }
    removeLeadingZeros(result);
    return result;
}
//Сумма длинных чисел
big sum(const big& left, const big& right) {
    long long cur;
    int ost = 0;
    big result(MAX(left.size(), right.size() + 1));
    for (int i = 0; i < result.size(); i++)
    {
        cur = (long long)(i < left.size() ? left[i] : 0) + (i < right.size() ? right[i] : 0) + ost;
        result[i] = (int)(cur % 1000000000);
        ost = (int)(cur / 1000000000);
    }
    removeLeadingZeros(result);
    return result;
}
//Умножение длнных чисел
big mult(const big& left, const big& right) {
    long long cur;
    int ost;
    big result(left.size() + right.size());
    for (int i = 0; i < left.size(); ++i) {
        ost = 0;
        for (int j = 0; j < right.size() || ost; ++j) {
            cur = result[i + j] + (j < right.size() ? (long long)left[i] * right[j] : 0) + ost;
            result[i + j] = (int)(cur % 1000000000);
            ost = (int)(cur / 1000000000);
        }
    }
    removeLeadingZeros(result);
    return result;
}
big toBig(std::string inp);
//Умножение длинного числа на обычное число
big mult(const big& left, int right) {
    big tmp = toBig(std::to_string(right));
    return mult(left, tmp);
}


void shiftRight(big& number) {
    if (number.size() == 0) {
        number.push_back(0);
        return;
    }
    number.push_back(number[number.size() - 1]);
    for (int i = number.size() - 2; i > 0; --i) number[i] = number[i - 1];
    number[0] = 0;
}
//Деление длинных чисел
big div(const big& left, big right) {
    big result(left.size()), current;
    for (long long i = (long long)(left.size()) - 1; i >= 0; --i) {
        shiftRight(current);
        current[0] = left[i];
        removeLeadingZeros(current);
        int x = 0, l = 0, r = 1000000000;
        while (l <= r) {
            int m = (l + r) / 2;
            big t = mult(right, m);
            if (!greatest(t, current)) {
                x = m;
                l = m + 1;
            }
            else r = m - 1;
        }

        result[i] = x;
        current = sub(current, mult(right, x));
    }

    removeLeadingZeros(result);
    return result;
}
//Остаток от деления длинных чисел
big mod(const big& left, const big& right) {
    big result = sub(left, mult(div(left, right), right));
    return result;
}
//Наибольшее общее кратное длинных чисел
big gcd(big left, big right) {
    const big bigZero = { 0 };
    while (right != bigZero)
    {
        big tmp = right;
        right = mod(left, right);
        left = tmp;
    }
    return left;
}
std::string toStr(const big& num);
//Вычисление основного выражения
void func(big& num, big& den, const big& n) {
    num = { 0 };
    den = { 1 };
    big a = { 1 }, b = { n };
    const big bigOne = { 1 }, bigZero = { 0 };
    while (b != bigZero)
    {
        den = mult(den, b);
        num = sum(num, a);
        a = mult(a, b);
        b = sub(b, bigOne);
    }
    big Gcd = gcd(num, den);
    num = div(num, Gcd);
    den = div(den, Gcd);
}
//Приведение строки к длинному числу
big toBig(std::string inp) {
    inp.insert(0, (9 - inp.size() % 9) % 9, '0');
    big result;
    std::string tmp;
    int chunks = inp.size() / 9;
    for (int i = chunks - 1; i >= 0; i--)
    {
        tmp = "";
        for (int j = i * 9; j < i * 9 + 9; j++)
        {
            tmp += inp[j];
        }
        result.push_back(std::stoi(tmp));
    }
    removeLeadingZeros(result);
    return result;
}
//Проверка состоит ли строка только из цифр
bool isNumber(std::string str) {
    std::string numbers = "1234567890";
    bool flag;
    for (auto i : str)
    {
        flag = false;
        for (auto j : numbers)
        {
            if (i == j)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            return false;
        }
    }
    return true;
}
//Запрос данных у пользоваателя с проверкой на дурака
std::string uInp(std::string message, std::string error1, std::string error2) {
    std::string result;
    const big bigZero = { 0 };
    bool err;
    do
    {
        err = false;
        std::cout << message << "\n";
        std::cin >> result;
        if (!isNumber(result))
        {
            err = true;
            std::cin.clear();
            std::cout << "Error: " << error1 << "\n";
        }
        else if (toBig(result) == bigZero)
        {
            err = true;
            std::cin.clear();
            std::cout << "Error: " << error2 << "\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (err);
    return result;
}
//Приведение длинного числа к строке
std::string toStr(const big& num) {
    std::string result = std::to_string(num.back()), tmp;

    for (int i = num.size() - 2; i >= 0; i--)
    {
        tmp = std::to_string(num[i]);
        tmp.insert(0, (9 - (tmp.size() % 9)) % 9, '0');
        result += tmp;
    }
    return result;
}