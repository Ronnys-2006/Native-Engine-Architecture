#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long binform = n;

        if(x == 1) return 1.0 ;
        if(x == 0) return 0.0 ;
        if(n == 0) return 1.0 ;
        if(x == -1 && n % 2 == 0) return 1.0 ;
        if(x == -1 && n % 2 != 0) return -1.0 ;

        if(n < 0)
        {
            x = 1/x ;
            binform = -binform ;
        }

        while(binform > 0)
        {
            if (binform % 2 == 1)
            {
                ans *= x ;
            }
            x *= x ;
            binform /= 2 ;
        }
        return ans ;
    }
};

int main() {
    Solution sol;
    cout.precision(10);
    cout << "Test 1: 2^10         = " << sol.myPow(2.0, 10) << "  (expected 1024)" << endl;
    cout << "Test 2: 2.1^3        = " << sol.myPow(2.1, 3) << "  (expected ~9.261)" << endl;
    cout << "Test 3: 2^-2         = " << sol.myPow(2.0, -2) << "  (expected 0.25)" << endl;
    cout << "Test 4: (-1)^INT_MIN = " << sol.myPow(-1.0, INT_MIN) << "  (expected 1)" << endl;
    cout << "Test 5: 2^INT_MIN    = " << sol.myPow(2.0, INT_MIN) << "  (expected ~0, tiny positive, NOT 1)" << endl;
    return 0;
}
