class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        int n = word.size();
        vector<long long> cnt(1024, 0);
        cnt[0] = 1;
        long long mask = 0;
        for(int i=0; i<n; i++){
            mask ^= 1<<(word[i]-'a');
            ans += cnt[mask];
            for(int j=0; j<10; j++){
                ans += cnt[mask^(1<<j)];
            }
            cnt[mask]++;
        }
        return ans;
    }
};