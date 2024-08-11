#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#define MAX 100001

#define endl "\n"

using namespace std;

// 100,000

int main() {
    
    int n,k;
    //n : 공 k : 바구니
    cin >> n >> k;
    
    int temp = 0;
    for(int i=1; i<=k; i++) {
        temp += i;
    }
    
    if(n < temp) {
        cout << -1;
    } else{
        if((n-temp) % k != 0) {
            cout <<k;
        } else {
            cout << (k-1);
        }
    }
    
    
    return 0;
}
