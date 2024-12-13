#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    ifstream inputFile("part1Input.txt");
    vector<int> a, b;
    int x, y;

    while (inputFile >> x >> y)
    {
        a.push_back(x);
        b.push_back(y);
    }
    inputFile.close();

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long sum = 0;

    for (int i = 0; i < a.size(); i++)
    {
        sum += abs(a[i] - b[i]);
    }
    cout << sum;

    return 0;
}