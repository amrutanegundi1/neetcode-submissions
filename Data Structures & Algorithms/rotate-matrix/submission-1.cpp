class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int left = 0, top = 0, right = matrix.size()-1;
        int bottom = right;

        while(left < right)
        {
            top = left, bottom = right;

            for(int i = 0; i < right-left; i++)
            {
                int topLeft = matrix[top][left+i];

                // move bottom left to top left
                matrix[top][left+i] = matrix[bottom-i][left];

                // move bottom right to bottom left
                matrix[bottom-i][left] = matrix[bottom][right-i];

                // move right top to bottom right
                matrix[bottom][right-i] = matrix[top+i][right];

                // move top left to top right

                matrix[top+i][right] = topLeft;
            }
            left++;
            right--;
        }

        
    }
};
