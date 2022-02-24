#include <bits/stdc++.h>
using namespace std;
// Note: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500 y M = 1000

int romanToArabic(string num) {
    map <char, int> RtoA;
    RtoA['I'] = 1; RtoA['V'] = 5; RtoA['X'] = 10; RtoA['L'] = 50;
    RtoA['C'] = 100;RtoA['D'] = 500;RtoA['M'] = 1000;
    int value = 0;
    for (int i = 0; num[i]; i++) {
        if (num[i+1] && RtoA[num[i]] < RtoA[num[i+1]]) {
            value += RtoA[num[i+1]] - RtoA[num[i]];
            i++;
        }
        else value += RtoA[num[i]];
    }
    return value;
}