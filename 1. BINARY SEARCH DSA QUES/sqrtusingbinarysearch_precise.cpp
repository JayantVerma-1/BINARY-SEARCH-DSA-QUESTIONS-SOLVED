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

    int precision;
    cout << "enter the value of floating digits in presicion" << endl;
    cin >> precision;
    
    double step = 0.1;
    double finalAns = ans;
    for(int i=0 ; i<precision ; i++){
        for(double j=finalAns ; j*j<=n ; j = j + step){
            finalAns=j;
        }
        step = step/10;
    }
    cout<<"THE final ANS is" << finalAns <<endl;
    return 0;
}