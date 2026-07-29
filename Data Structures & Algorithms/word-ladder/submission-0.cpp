class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        if (st.find(endWord) == st.end()) return 0;
        st.erase(beginWord);
        int cnt=1;
        while(!q.empty()){
           string word=q.front().first;
           int level=q.front().second;
           q.pop();
           if (word == endWord) return level;
           for(int i=0;i<word.size();i++){
            char org=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(st.find(word)!=st.end()){
                    q.push({word,level+1});
                    //cnt=level;
                    st.erase(word);
                }
            }
            word[i]=org;
           }

        }
        return 0;
    }
};
