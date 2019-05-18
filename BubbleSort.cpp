#include <iostream>
#include <vector>
#include <stdlib.h>      // for rand()
#include <bits/stdc++.h> // for swap()

using namespace std;

vector<int> initRandomArray(int length)
{
    vector<int> res;
    for (int i = 0; i < length; ++i)
    {
        int radNum = (rand() % length) + 1;
        res.push_back(radNum);
    }
    return res;
}
int main()
{
    vector<int> random = initRandomArray(15);
    vector<int> random_bk(random);

    int count = 0;

    for (int i = 0; i < random.size(); i++)
    {
        int n = random.size() - 1, m = n - 1;
        while (m >= i)
        {
            if (random[n] < random[m])
            {
                swap(random[n], random[m]);
            }
            m--;
            n--;
            count++;
        }
        count++;
    }

    cout << "Origin array: " << endl;
    for (int i : random_bk)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i : random)
    {
        cout << i << " ";
    }
    cout << endl
         << "loop time: " << count;
    return 0;
}
