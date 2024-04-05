#include <bits/stdc++.h>
using namespace std;

int arr[] = {1, 2, 3};

void printSubsequence(int index, vector<int> &op, int n)
{
    if (index == n)
    {
        for (auto it : op)
            cout << it;
        cout << endl; // Add a newline after printing each subsequence
        return;
    }
    op.push_back(arr[index]);
    printSubsequence(index + 1, op, n);
    op.pop_back();
    printSubsequence(index + 1, op, n);
}

int main()
{
    int n = 3;
    vector<int> answer;
    printSubsequence(0, answer, n);

    return 0;
}
