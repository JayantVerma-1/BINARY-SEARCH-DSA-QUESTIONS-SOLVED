#include <iostream>
using namespace std;

int findSqrt(int n){
    int target = n;
    int s = 0;
    int e = n;
    int mid = s + (e-s)/2;
    int ans = -1 ;

    while(s <= e){
        if (mid*mid == target)
        return mid;
        if (mid*mid > target){
        //search left
        e = mid - 1; 
        }
        else{
            //store ans first
            ans = mid;
            //right search
            s = mid+1;
        }
        mid = s + (e-s)/2;
     }
     return ans;
}

int main(){
    int n;
    cout << "enter the number" << endl;
    cin >> n;
    int ans = findSqrt(n);
    cout <<"ans is" << ans << endl;
    return 0;
}