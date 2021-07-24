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
