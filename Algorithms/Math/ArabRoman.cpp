#include <bits/stdc++.h>
using namespace std;
// Note: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500 y M = 1000

string arabicToRoman(int num) {
    string uni[10] = {"", "I", "II", "III", "IV", "V",
    "VI", "VII", "VIII", "IX"};
    string deci[10]={"", "X", "XX", "XXX", "XL", "L",
    "LX", "LXX", "LXXX", "XC"};
    string cen[10]={"", "C", "CC", "CCC", "CD", "D",
    "DC", "DCC", "DCCC", "CM"};
    string mil[4]={"", "M", "MM", "MMM"};
    int nUni = num % 10;
    int nDec = (num / 10) % 10;
    int nCen = ((num / 10) / 10) % 10;
    int nMil = (((num / 10) / 10) / 10) % 10;
    string ans = mil[nMil];
    ans += cen[nCen];
    ans += deci[nDec];
    ans += uni[nUni];
    return ans;
}