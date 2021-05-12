#include "home-work-4.h"

#include <string>
#include <cmath>

using std::string;
using std::floor;
using std::sqrt;

const char* isRange_10_20 (int a, int b) {
    long long c = a + b;
    if (c >= 10 && c <= 20) {
        return "true";
    } else {
        return "false";
    }
}

const char* both_10_or_sum_10(int a, int b) {
    if (a == 10 && b == 10) {
        return "true";
    } else if (a + b == 10)
        return "true";
    else return "false";
}

string odd_nums(int start, int end) {
    string res;
    for(int num = start; num <= end; num += 2) {
        res += to_string(num) + ' ';
    }
    return res;
}
string odd_nums_1_50() {
    return odd_nums(1, 50);
}


bool isPrime(unsigned num) {
    if (num == 0) return false;
    unsigned divisor = static_cast<unsigned>(floor(sqrt(static_cast<float>(num))));
    while(divisor > 1) {
        if (!(num % divisor--))
            return false;
    }
    return true;
}

bool isLeapYear(int year) {
    if (!(year % 100))
        return !(year % 400);
    return !(year % 4);
}


