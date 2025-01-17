class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
      unordered_map<char,int>freq;
      for(char c :s){
        freq[c]++;
      }
      priority_queue<pair<int,char>>maxheap;

      for(auto& entry : freq){
        maxheap.push({entry.second, entry.first});
      }
      string res;

      while(!maxheap.empty()){
        auto[val,key] = maxheap.top();
        maxheap.pop();
        res.append(val,key);
      }
      return res;

    }
};