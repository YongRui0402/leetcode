class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendSet;
        for(auto deadend:deadends){
            deadendSet.insert(deadend);
        }

        unordered_set<string> visited;
        queue<pair<string, int>> queue;

        if (visited.count("0000")==0 && deadendSet.count("0000")==0){
            visited.insert("0000");
            queue.push({"0000",0});
        }

        while(!queue.empty()){
            pair<string, int> item = queue.front();
            queue.pop();
            if(item.first==target){
                return item.second;
            }
            else{
                for(int i=0;i<4;i++){
                    for(int bias:{-1,1}){
                        char newdigital = '0'+(item.first[i]-'0'+bias+10)%10;
                        string newstring = item.first;
                        newstring[i] = newdigital;

                        if(visited.count(newstring)==0 && deadendSet.count(newstring)==0){
                            visited.insert(newstring);
                            queue.push({newstring,item.second+1});
                        }
                    }
                }
            }
        }
        return -1; 
    }
};