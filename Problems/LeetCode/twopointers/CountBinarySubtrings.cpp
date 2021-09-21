#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int zeros = 0, ones = 0, total = 0;
        char firs = 'b';
        
        for (int i = 0; i < s.length(); ++i){
            //cout << zeros << " " << ones << endl;
            if(s[i] == firs){
                total += min(zeros, ones);
                if (firs == '0') zeros = 0;
                else ones = 0;
                firs = 'b';
            }
            
            if (s[i] == '0'){
                if (ones >= 0 && firs == 'b') firs = '1';
                
                zeros++;
            }
            else if (s[i] == '1'){
                if (zeros >= 0 && firs == 'b') firs = '0';
                ones++;
            }
        }
        
        total += min(zeros, ones);
        
        return total;
    }
};