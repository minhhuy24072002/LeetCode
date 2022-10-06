class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> availableServer;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busyServer;
        vector<int> res;
        
        for (int i = 0; i < servers.size(); i++) {
            availableServer.push({servers[i], i});
        }
        
        int time = 0;
        for (int i = 0; i < tasks.size(); i++) {
            if (availableServer.size() == 0) {
                time = busyServer.top().first;
            }
            pair<int, int> server;
            // Release all server that finished their tasks
            while (busyServer.size() > 0 && busyServer.top().first <= time) {
                server =  busyServer.top();
                busyServer.pop();
                availableServer.push({servers[server.second], server.second});
            }
            // Assign first priority server to the current task
            server = availableServer.top();
            availableServer.pop();
            busyServer.push({time + tasks[i], server.second});
            res.push_back(server.second);
            if (i >= time) time++;
        }
        return res;
    }
};