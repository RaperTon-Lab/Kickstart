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

// Takes 0.048s in running test set 2
#include <bits/stdc++.h>

#define M 1000000007
typedef long long ll;
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    ll sum, product, pow;
    int t, n, k, sub, s, i, true_holder, false_holder;
    bool flag;
    string str;
    cin >> t;
    for (int p = 1; p <= t; ++p)
    {
        str.clear();
        cin >> n >> k;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, str);
        flag = false;
        sum = 0;
        pow = 1;
        sub = ceil((float)n / 2);
        s = sub;
        true_holder = false_holder = 0;
        for (i = (sub - 1); i >= 0; --i)
        {
            product = 1;
            product = (((int)(str.at(i) - 'a')) * pow) % M; //needs to be modulo
            pow = (pow * k) % M;                            //kepping the product under M as ll can hold it and the answer needs to be expressed as modulo of M
            sum = sum + product;

            if (((n % 2) != 0) && (i == (sub - 1)))
                continue;
            if ((str.at(i) < str.at(s)) && (false_holder == 0))
            {
                flag = true;
                ++true_holder;
            }
            else if ((str.at(i) == str.at(s)) && (true_holder == 0) && (false_holder == 0))
            {
                ++s;
            }
            else if ((str.at(i) > str.at(s)) && (true_holder == 0))
            {
                ++false_holder;
            }
        }
        if (flag)
            ++sum;
        cout << "Case #" << p << ": " << sum % M << endl;
    }
    return 0;
}
