#include <iostream>
#include <vector>
#include <algorithm>
//we can also use  #include <bits/stdc++.h> instead of using all above # include header file
using namespace std;

bool ifPossibleSolution(vector<long long int> trees, long long int m, long long int mid)
{
    long long int woodCollected = 0;
    for (int i = 0; i < trees.size(); i++)
    {
        if (trees[i] > mid)
        {
            woodCollected = woodCollected + trees[i] - mid;
        }
    }
    return woodCollected >= m;
}
long long int maxSawBladeHeight(vector<long long int> trees, long long int m)
{
    long long int start = 0, end, ans = -1;
    end = *max_element(trees.begin(), trees.end());
    while(start <= end){
        long long int mid = start + (end - start) / 2;
        if (ifPossibleSolution(trees, m, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
return ans;
}
int main()
{
    long long int n, m;
    cin >> n >> m;
    vector<long long int> trees;
    while (n--)
    {
        long long int height;
        cin >> height;
        trees.push_back(height);
    }

    cout << maxSawBladeHeight(trees, m) << endl;
    return 0;
}