#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(image[sr][sc] == color) return image;
    fill(image, sr, sc, image[sr][sc], color);
    return image;
}

void fill(vector<vector<int>>& image, int sr, int sc, int originalColor, int newColor){
    if(sc < 0 || sr < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != originalColor) return;

    image[sr][sc] = newColor;
    fill(image, sr, sc + 1, originalColor, newColor);
    fill(image, sr, sc - 1, originalColor, newColor);
    fill(image, sr + 1, sc, originalColor, newColor);
    fill(image, sr - 1, sc, originalColor, newColor);    
}