#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    ifstream inputFile("part2Input.txt");
    vector<int> a, b;
    int x, y;

    while (inputFile >> x >> y)
    {
        a.push_back(x);
        b.push_back(y);
    }
    inputFile.close();

    const int N = 1000;
    long long sum = 0;

    for (int i = 0; i < N; i++)
    {
        int num = a[i];
        int times = 0;
        for (int j = 0; j < N; j++)
        {
            if (b[j] == num)
            {
                times++;
            }
        }
        sum += (num * times);
    }

    cout << sum;
}