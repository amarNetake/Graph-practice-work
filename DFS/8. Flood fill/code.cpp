class Solution {
public:
    void floodfillUtil(vector<vector<int>>& image,int sr,int sc,int newColor,int source,int m,int n)
    {
        if(sr<0||sr>=m||sc<0||sc>=n||image[sr][sc]!=source||image[sr][sc]==newColor)
        {
            return;
        }
        image[sr][sc]=newColor;
        floodfillUtil(image,sr-1,sc,newColor,source,m,n);
        floodfillUtil(image,sr+1,sc,newColor,source,m,n);
        floodfillUtil(image,sr,sc-1,newColor,source,m,n);
        floodfillUtil(image,sr,sc+1,newColor,source,m,n);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size();
        if(m==0)
        {
            return image;
        }
        int n=image[0].size();
        int source=image[sr][sc];
        if(source==newColor)
        {
            return image;
        }
        image[sr][sc]=newColor;
        floodfillUtil(image,sr-1,sc,newColor,source,m,n);
        floodfillUtil(image,sr+1,sc,newColor,source,m,n);
        floodfillUtil(image,sr,sc-1,newColor,source,m,n);
        floodfillUtil(image,sr,sc+1,newColor,source,m,n);
        return image;
    }
};