/*Charles defines the goodness score of a string as the number of indices i such that Si≠SN−i+1 where 1≤i≤N/2 (1-indexed). For example, the string CABABC has a goodness score of 2 since S2≠S5 and S3≠S4.

Charles gave Ada a string S of length N, consisting of uppercase letters and asked her to convert it into a string with a goodness score of K. In one operation, Ada can change any character in the string to any uppercase letter. Could you help Ada find the minimum number of operations required to transform the given string into a string with goodness score equal to K?

Input
The first line of the input gives the number of test cases, T. T test cases follow.

The first line of each test case contains two integers N and K. The second line of each test case contains a string S of length N, consisting of uppercase letters.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum number of operations required to transform the given string S into a string with goodness score equal to K.

Limits
Memory limit: 1 GB.
1≤T≤100.
0≤K≤N/2.
Test Set 1
Time limit: 20 seconds.
1≤N≤100.
Test Set 2
Time limit: 40 seconds.
1≤N≤2×105 for at most 10 test cases.
For the remaining cases, 1≤N≤100.*/

//Commented lines are not neccesary for the competition. They are to reduce time complexity

#include <bits/stdc++.h>
using namespace std;
int stringGoodnessScore(string str, int len);
/*string stringManipulationLesser(string str, int len);
string stringManipulationLarger(string str, int len);
int o;*/

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    int n, len, k, score, realGoodScore = 0;
    string str;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        len = k = 0;
        str.clear();
        cin >> len >> k;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, str);
        //cout << str << endl;
        //realGoodScore = 0;
        score = stringGoodnessScore(str, len);
        //o = 0;
        //cout << stringGoodnessScore(str, len) << endl;
        if (score < k)
        {
            //str = stringManipulationLesser(str, len);
            //++realGoodScore;
            score = k - score;
        }
        else
        {
            //str = stringManipulationLarger(str, len);
            //++realGoodScore;
            score = score - k;
        }

        cout << "Case #" << i << ": " << score << endl;
    }
    return 0;
}

int stringGoodnessScore(string str, int len)
{
    char *c = const_cast<char *>(str.c_str());
    int k = 0;
    for (int i = 0; i < len / 2; ++i)
    {
        if (c[i] != c[len - i - 1])
            ++k;
    }
    return k;
}

/*string stringManipulationLesser(string str, int len)
{
    char *c = const_cast<char *>(str.c_str());
    while (c[o] != c[len - o - 1])
        ++o;
    c[o] = c[o] + 1;
    str = c;
    return str;
}
string stringManipulationLarger(string str, int len)
{
    char *c = const_cast<char *>(str.c_str());

    while (o <= len / 2)
    {
        if (c[o] != c[len - o - 1])
        {
            c[o] = c[len - o - 1];
            str = c;
            return str;
        }
        ++o;
    }
    return str;
}*/
