// TC = O(10*N)
// MC = o(N) where N is the initial size of the wordlist
class Solution {
public:
    int calculateScore(string &referance, string &candidate){
        int res = 0;
        for(int i = 0; i < candidate.size(); i++){
            if(candidate[i] == referance[i]){
                res ++;
            }
        }
        return res;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        while(wordlist.size() > 1){
            int rIdx = rand() % wordlist.size();
            string queryString = wordlist[rIdx];
            int score = master.guess(queryString);
            vector<string> words;

            for(auto &word: wordlist){
                if(score == calculateScore(queryString, word)){
                    words.push_back(word);
                }
            }
            wordlist = words;
        }
        master.guess(wordlist[0]);
    }
};
