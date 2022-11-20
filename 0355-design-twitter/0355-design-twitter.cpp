class Twitter {
public:
    struct Post {
        int id;
        int postTime;
        Post(int x, int y) {
            id = x;
            postTime = y;
        }
    };
    
    struct User {
        list<Post> posts;
        list<Post> newsFeed;
        unordered_set<int> followers;
        unordered_map<int, list<Post>::iterator> post_feed;
    };
    
    int timer;
    unordered_map<int, User> user;
    
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        timer++;
        User* postUser = &user[userId];
        
        postUser->posts.push_back(Post(tweetId, timer));
        postUser->newsFeed.push_back(Post(tweetId, timer));
        list<Post>::iterator tempIt = postUser->newsFeed.end();
        postUser->post_feed[tweetId] = --tempIt;
        
        for (auto followerId : postUser->followers) {
            User* follower = &user[followerId];
            follower->newsFeed.push_back(Post(tweetId, timer));
            tempIt = follower->newsFeed.end();
            follower->post_feed[tweetId] = --tempIt;
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        timer++;
        User* currentUser = &user[userId];
        
        int postNum = min(10, (int) currentUser->newsFeed.size());
        vector<int> result;
        list<Post>::iterator it = currentUser->newsFeed.end();
        --it;
        while (postNum--) {
            result.push_back(it->id);
            --it;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        timer++;
        User* follower = &user[followerId];
        User* followee = &user[followeeId];
        
        if (followee->followers.find(followerId) != followee->followers.end()) {
            return;
        }
        followee->followers.insert(followerId);
        
        list<Post>::iterator followerIt = follower->newsFeed.begin();
        list<Post>::iterator followeeIt = followee->posts.begin();
        
        // Merge followee posts to follower news feed
        while (followeeIt != followee->posts.end()) {
            if (followerIt != follower->newsFeed.end() && followeeIt->postTime < followerIt->postTime) {
                follower->newsFeed.insert(followerIt, Post(followeeIt->id, followeeIt->postTime));
                follower->post_feed[followeeIt->id] = followerIt;
                follower->post_feed[followeeIt->id]--;
                followeeIt++;
            } else if (followerIt == follower->newsFeed.end()) {
                follower->newsFeed.push_back(Post(followeeIt->id, followeeIt->postTime));
                follower->post_feed[followeeIt->id] = follower->newsFeed.end();
                follower->post_feed[followeeIt->id]--;
                followeeIt++;
            } else {
                followerIt++;
            }
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        timer++;
        User* follower = &user[followerId];
        User* followee = &user[followeeId];
        
        if (followee->followers.find(followerId) == followee->followers.end()) {
            return;
        }
        followee->followers.erase(followerId);
        
        for (list<Post>::iterator followeeIt = followee->posts.begin(); followeeIt != followee->posts.end(); followeeIt++) {
            int tweetId = followeeIt->id;
            list<Post>::iterator followerIt = follower->post_feed[tweetId];
            follower->newsFeed.erase(followerIt);
            follower->post_feed.erase(tweetId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */