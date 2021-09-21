#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
public: 
/*
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
    }
*/
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c){
        int left = c - 1, right = 0, up = 0, down = r - 1, moves = r*c;
        vector<int> ans;
        while (true){
            for (int i = right; i <= left; ++i){
                ans.push_back(matrix[up][i]);
                moves--;
            }
            
    
            up++;
            if (moves == 0) break;
            for (int i = up; i <= down; ++i){
                ans.push_back(matrix[i][left]);
                moves--;
            }
        
    
            left--;
            if (moves == 0) break;
            for (int i = left; i >= right; --i){
                ans.push_back(matrix[down][i]);
                moves--;
            }
            down--;
            if (moves == 0) break;
    
            for (int i = down; i >= up; --i){
                ans.push_back(matrix[i][right]);
                moves--;
            }
            right++;
            if (moves == 0) break;
            
        }
    
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends