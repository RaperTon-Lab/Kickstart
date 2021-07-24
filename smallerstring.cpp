/*You are given an integer K and a string S of length N, consisting of lowercase letters from the first K letters of the English alphabet. Find the number of palindrome strings of length N which are lexicographically smaller than S and consist of lowercase letters from the first K letters of the English alphabet.

A string composed of ordered letters a1,a2,…,an is lexicographically smaller than another string of the same length b1,b2,…,bn if ai<bi, where i is the first index where characters differ in the two strings. For example, the following strings are arranged in lexicographically increasing order: aaa, aab, aba, cab.

A palindrome is a string that is the same written forwards and backwards. For example, anna, racecar, aaa and x are all palindromes, while ab, frog and yoyo are not.

As the number of such strings can be very large, print the answer modulo 109+7.

Input
The first line of the input gives the number of test cases, T. T test cases follow.

Each test case consists of two lines. The first line contains two integers N and K. The second line contains a string S of length N, consisting of lowercase letters.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of lexicographically smaller palindrome strings modulo 109+7.

Limits
Memory limit: 1 GB.
1≤T≤100.
The string S consists of lowercase letters from the first K letters of the English alphabet.
Test Set 1
Time limit: 20 seconds.
1≤N≤8.
1≤K≤5.
Test Set 2
Time limit: 10 seconds.
1≤N≤105.
1≤K≤26.*/

//This algorithm has a bad time as well as space complexity
//takes 2min 1.909s to run test case 2


#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#define M 1000000007
using namespace std;
using namespace boost::multiprecision;
bool checkLexVal(vector<int> val, int i, int n);
void characterVal(vector<int> &val, string str, int n);
cpp_int prepow(int base, int exp);
int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    vector<int> val;
    cpp_int sum, product, pow;
    unsigned int t, n, k, sub, s;
    string str;
    //const unsigned int M = 1000000007;
    cin >> t;
    for (int p = 1; p <= t; ++p)
    {
        str.clear();
        cin >> n >> k;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, str);
        sum = 0;
        product = 1;
        characterVal(val, str, n);
        sub = ceil((float)n / 2);
        /*for (int i = 0; i < n; ++i)
            cout << val[i] << endl;*/
        pow = prepow(k, (sub - 1));
        for (int i = 0; i < sub; ++i)
        {
            product = 1;
            product = (((val.at(i) - 1) * pow));
            pow = pow / k;
            sum = sum + product;
            s = i;
        }
        if (checkLexVal(val, s, n))
            ++sum;
        cout << "Case #" << p << ": " << sum % M << endl;
        val.clear();
    }
    return 0;
}

bool checkLexVal(vector<int> val, int i, int n)
{
    int end;
    end = i + 1;
    int mid;
    mid = n / 2;
    --mid;
    for (int j = mid; j >= 0; --j)
    {
        /*cout << "j=" << j << " end= " << end << endl;
        cout << "val i = " << val.at(j) << " end = " << val.at(end) << endl;*/
        if (val.at(j) < val.at(end))
            return true;

        else if (val.at(j) == val.at(end))
            ++end;
        else if (val.at(j) > val.at(end))
            return false;
    }
    return false;
}

void characterVal(vector<int> &val, string str, int n)
{
    char *c = const_cast<char *>(str.c_str());
    for (int i = 0; i < n; ++i)
    {
        val.push_back((int)(c[i] - 96));
    }
}

cpp_int prepow(int base, int exp)
{
    cpp_int power = 1;
    for (int i = 1; i <= exp; ++i)
    {
        power = power * base;
    }
    //cout << power << endl;
    return power;
}

