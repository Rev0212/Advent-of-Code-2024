#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

bool isIncreasing(const vector<int> &levels)
{
    for (size_t i = 0; i < levels.size() - 1; i++)
    {
        if (levels[i + 1] <= levels[i])
        {
            return false;
        }
    }
    return true;
}

bool isDecreasing(const vector<int> &levels)
{
    for (size_t i = 0; i < levels.size() - 1; i++)
    {
        if (levels[i + 1] >= levels[i])
        {
            return false;
        }
    }
    return true;
}

bool hasValidDifferences(const vector<int> &levels)
{
    for (size_t i = 0; i < levels.size() - 1; i++)
    {
        int diff = abs(levels[i] - levels[i + 1]);
        if (diff < 1 || diff > 3)
        {
            return false;
        }
    }
    return true;
}

bool isSafeReport(const vector<int> &levels)
{
    return (isIncreasing(levels) || isDecreasing(levels)) && hasValidDifferences(levels);
}

bool isSafeAfter(const vector<int> &levels)
{
    for (size_t i = 0; i < levels.size(); i++)
    {
        vector<int> modified = levels;
        modified.erase(modified.begin() + i); // nee vaatu each time new array va create panra by deleting on index that is ith so if 5 element irrunchu na u will make 5 array and check at max
        if (isSafeReport(modified))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Error: Unable to open input file!" << endl;
        return 1;
    }

    vector<vector<int>> reports;
    string line;

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        vector<int> levels;
        int value;
        while (ss >> value)
        {
            levels.push_back(value);
        }
        if (!levels.empty())
        {
            reports.push_back(levels);
        }
    }

    inputFile.close();

    int totalSafe = 0;
    for (const auto &levels : reports)
    {
        if (isSafeAfter(levels))
        {
            totalSafe++;
        }
    }

    cout << "Total Safe: " << totalSafe << endl;
    return 0;
}
