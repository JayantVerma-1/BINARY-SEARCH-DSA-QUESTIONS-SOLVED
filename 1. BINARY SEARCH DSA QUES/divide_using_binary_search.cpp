#include <iostream>
using namespace std;
int solve(int divident, int divisor)
{
    int s = 0;
    int e = abs(divident);
    int ans = 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        /*perfect solution*/
        if (abs(mid * divisor) == abs(divident))
        {
            return mid;
        }
        /*not perfect solution*/
        if (abs(mid * divisor) > abs(divident))
        {
            /*left*/
            e = mid - 1;
        }
        else
        {
            /*first - ans store*/
            ans = mid;
            /*right*/
            s = mid + 1;
        }
    mid = s + (e-s)/2;
    }
    if((divisor < 0 && divident < 0) || (divisor > 0 && divident > 0))
    return ans;
    else {
        return -ans; 
    }
}

int main()
{
    int divident = 22;
    int divisor = -7;
    int ans = solve(divident, divisor);
    cout << "ans is " << ans << endl;
    return 0;
}