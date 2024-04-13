class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // prepare dictionary of available words
        map<string, bool> mp;
        for(auto word: wordList) {
            mp[word] = true;
        }
        if(!mp[endWord]) return 0; // if endWord is not found in the dictionary
        
        queue<string> q; q.push(beginWord);
        int level = 1; // base level
        while(!q.empty()) {
            int qSize = q.size();
            for(int k=0;k<qSize;k++) {
                string currentNode = q.front(); q.pop();
                for(int j = 0; j<currentNode.size();j++) {
                    char origChar = currentNode[j];
                    for(int i=0;i<26;i++) {
                        char replaceChar = 'a' + i;
                        if(origChar == replaceChar) continue;
                        // replace jth character by each possible character and push into
                        // the queue if the transformed word in present in the dictionary
                        currentNode[j] = replaceChar;
                        if(currentNode == endWord) return level+1;
                        if(mp[currentNode]) {
                            q.push(currentNode);
                            mp.erase(currentNode); // remove the word from the dictioary 
                        }
                    }
                    currentNode[j] = origChar; // retrive the word in original position
                }
            }
            level++;
        }
        return 0; // no transformation exists
    }
};