#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPossibleSolution(int A[], int n, int m, int sol)
    {
        int pageSum = 0;
        int c = 1;
        for (int i = 0; i < n; i++)
        {
            if (A[i] > sol)
            {
                return false;
            }
            if (pageSum + A[i] > sol)
            {
                c++;
                pageSum = A[i];
                if (c > m)
                {
                    return false;
                }
            }
            else
            {
                pageSum += A[i];
            }
        }
        return true;
    }
    // function to find minimum no. of pages
    int findPages(int A[], int n, int m)
    {
        if (m > n)
            return -1;

        int start = 0;
        int end =  accumulate(A, A + n, 0);
        int ans = -1;
        while (start <= end)
        {
            int mid = (start + end) >> 1;
            if (isPossibleSolution(A, n, m, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
