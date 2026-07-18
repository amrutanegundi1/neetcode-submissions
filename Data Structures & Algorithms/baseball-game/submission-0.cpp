class Solution {
public:
    int calPoints(vector<string>& operations) {


        stack<int> score;

        for(auto itr : operations)
        {
            if(itr == "C")
            {
                score.pop();
            }
            else if(itr == "D")
            {
                int temp = score.top();
                score.push(temp*2);
            }
            else if(itr == "+")
            {
                int temp1 = score.top();
                score.pop();
                int sum = temp1 + score.top();
                score.push(temp1);
                score.push(sum);
            }
            else
            {
                score.push(stoi(itr));
            }
        }
        int res = 0;
        while(!score.empty())
        {  
            res += score.top();
            score.pop();

        }
        return res;
        
    }
};