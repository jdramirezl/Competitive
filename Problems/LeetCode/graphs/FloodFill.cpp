#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     vector<vector<int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
         int temp = image[sr][sc];
        image[sr][sc] = newColor;
        
        for (const auto &move: moves){
            int nx = sr + move[0];
            int ny = sc + move[1];
            if (image.size() > nx && nx >= 0 && image[0].size() > ny && ny >= 0 && image[nx][ny] == temp){
                floodFill(image, nx, ny, newColor);
            }
        }
                
        return image;
    }
};