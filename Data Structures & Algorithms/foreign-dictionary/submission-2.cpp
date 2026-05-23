class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int num = 26;
        int n = words.size();
        vector<bool> exists(num, false);
        vector<int> indegree(num, 0);
        vector<vector<int>> adjlist(num);

        for(auto w: words)
            for(auto c: w)
                exists[c-'a'] = true;

        for(int i=0; i<n-1; i++){
            string a = words[i];
            string b = words[i+1];
            int len = min(a.size(), b.size());
            bool found = false;

            for(int k=0; k<len; k++){
                if(a[k] != b[k]){
                    adjlist[a[k]-'a'].push_back(b[k]-'a');
                    indegree[b[k]-'a']++;
                    found = true;
                    break;
                }
            }

            if(!found && a.size() > b.size()) return "";
        }

        queue<int> q;
        string res = "";
        for(int i=0;i<num;i++)
            if(exists[i] && indegree[i] == 0) q.push(i);

        while(!q.empty()){
            int el = q.front(); q.pop();
            res += char('a' + el);

            for(auto nei: adjlist[el]){
                indegree[nei]--;
                if(indegree[nei] == 0) q.push(nei);
            }
        }

        int countLetters = 0;
        for(bool e: exists) if(e) countLetters++;
        if(res.size() != countLetters) return "";

        return res;
    }
};
