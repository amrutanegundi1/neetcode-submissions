class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool found = false;

        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == endWord) {
                found = true;
                break;
            }
        }
        if (!found) {
            return 0;
        }

        unordered_map<string, vector<string>> adj;
        for (int i = 0; i < wordList.size(); i++) {
            string word1 = beginWord;
            string word2 = wordList[i];
            int diff = 0;
            for (int i = 0; i < word1.length(); i++) {
                if (word1[i] != word2[i]) {
                    diff++;
                }
            }
            if (diff == 1) {
                adj[word1].push_back(word2);
                adj[word2].push_back(word1);
            }
        }

        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i+1; j < wordList.size(); j++) {
                string word1 = wordList[i];
                string word2 = wordList[j];
                int diff = 0;
                for (int i = 0; i < word1.length(); i++) {
                    if (word1[i] != word2[i]) {
                        diff++;
                    }
                }
                if (diff == 1) {
                    adj[word1].push_back(word2);
                    adj[word2].push_back(word1);
                }
            }
        }


        int res = 0;
        queue<string> que;
        que.push(beginWord);
        unordered_set<string> visited;
        while(!que.empty())
        {
            res++;
            for(int i = que.size()-1; i>= 0; i--)
            {
                string word = que.front();
                que.pop();
                if(visited.count(word))
                {
                    continue;
                }
                visited.insert(word);
                if(word == endWord)
                {
                    return res;
                }
                for(auto itr : adj[word])
                {
                    que.push(itr);
                }
            }
        }
        return 0;

    }
};
