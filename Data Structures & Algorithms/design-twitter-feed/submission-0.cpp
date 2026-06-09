class Tweet {
   public:
    int uId;
    int tId;

    Tweet(int userId, int tweetId) {
        uId = userId;
        tId = tweetId;
    }
};
class Twitter {
   private:
    vector<Tweet> tweets;
    unordered_map<int, vector<int>> followers;

   public:
    Twitter() {}

    void postTweet(int userId, int tweetId) { tweets.push_back(Tweet(userId, tweetId)); }

    vector<int> getNewsFeed(int userId) {
        vector<int> lt;
        for (auto itr = tweets.rbegin(); itr != tweets.rend(); itr++) {
            if(itr->uId == userId || std::ranges::contains(followers[userId], itr->uId))
            {
                lt.push_back(itr->tId);
                if(lt.size() > 9)
                    break;
            }
        }

        return lt;
    }

    void follow(int followerId, int followeeId) {
        followers[followerId].push_back(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        std::erase(followers[followerId], followeeId);
    }
};
