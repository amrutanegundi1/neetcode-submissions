class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool found = false;
        for (auto itr : wordList) {
            if (endWord == itr) {
                found = true;
                break;
            }
        }
        if (!found) {
            return 0;
        }

        map<string, vector<string>> adj;

        for (auto itr : wordList) {
            int diff = 0;
            for (int i = 0; i < itr.length(); i++) {
                if (beginWord[i] != itr[i]) {
                    diff++;
                    if (diff > 1) break;
                }
            }
            if (diff == 1) {
                adj[beginWord].push_back(itr);
                adj[itr].push_back(beginWord);
            }
        }

        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                string word1 = wordList[i], word2 = wordList[j];

                int diff = 0;
                for (int i = 0; i < word1.length(); i++) {
                    if (word1[i] != word2[i]) {
                        diff++;
                        if (diff > 1) break;
                    }
                }
                if (diff == 1) {
                    adj[word1].push_back(word2);
                    adj[word2].push_back(word1);
                }
            }
        }
        queue<string> que;
        set<string> visited;
        que.push(beginWord);
        visited.insert( beginWord);
        int res = 0;
        while(!que.empty())
        {
            res++;
            for(int i = que.size()-1; i >= 0; i--)
            {

                string inq = que.front();
                que.pop();
                if(inq == endWord)
                {
                    return res;
                }
                else
                {
                    for(int j = 0; j < adj[inq].size(); j++)
                    {
                        if(visited.find(adj[inq][j]) != visited.end())
                        {
                            continue;
                        }
                        que.push(adj[inq][j]);
                        visited.insert(adj[inq][j]);
                    }
                }
            }
        }
        return 0;
    }
};
