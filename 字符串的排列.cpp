class Solution {
public:
    vector<string> Permutation(string str) {
        vector<char> v1;
        v1.assign(str.begin(), str.end());
        vector<vector<char>> p =  RecurseHelper(v1);
        vector<string> trans_p;
        for(auto &item : p){
            string tmp;
            tmp.assign(item.begin(), item.end());
            trans_p.push_back(tmp);
        }
        sort(trans_p.begin(), trans_p.end());
        trans_p.erase(unique(trans_p.begin(), trans_p.end()), trans_p.end());
        return trans_p;
    }
    
    vector<vector<char>> RecurseHelper(vector<char> v1){
        vector<vector<char>> result;
        for(int i = 0; i < v1.size(); i++){
            vector<char> v2 = v1;
            v2.erase(v2.begin() + i);
            if(!v2.empty()){
                vector<vector<char>> subStr = RecurseHelper(v2);
                for(auto &item : subStr)
                    item.insert(item.begin(), v1[i]);
                result.insert(result.end(), subStr.begin(), subStr.end());
            }
            else
                result.push_back(v1);
        }
        return result;
    }
};