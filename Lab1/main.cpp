/**
 * @file main.cpp
 * @author Arpit01Goel
 * @date 2025/01/09 17:15:24
 */

#include <bits/stdc++.h>
#include <time.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;

void fibb(int n) {
    //calculate nth fibb number
    //in linear time 
    long double a = 0,b = 1, c = 1;
    for (int i=0;i<n;i++) {
        a=b;
        b=c;
        c=a+b;
    }
    //a is nth fibb now 
    // cout << setprecision(30) <<  a << endl;  
}
double time() {
    clock_t start = clock();

    for (int i=0;i<50;i++) {
        fibb(100);
    }
    clock_t end = clock();
    double duration = (double(end-start)/CLOCKS_PER_SEC)*1000;
    return duration;
}

int main() {
    // fast_io
    double total_time = 0;
    for (int i=0;i<200;i++) {
        total_time += time();
    }
    total_time /= 200;
    cout << total_time << endl;
    return 0;
}

// GitHub: https://github.com/Arpit01Goel