// TC = O(N)
// MC = O(N) where N is the size of given string
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> digit;
        digit.push(num[0]);
        // num = "2143"
        for(int i = 1; i < num.size(); i++){
            // maintain increasing sequence always
            // digit.top() = 2, num[i] = 1
            while(k>0 && !digit.empty() && num[i] < digit.top()){
                digit.pop();
                k--;
            }
            digit.push(num[i]);

        }
        // jokhn string traverse kora ses but K ekhno 0 hoy nai..tokhn ei block a asbe..
        // r jehetu stack a already increasing seq ase and amder jehetu num take aro
        // choto kora lgbe tai just boro value gula stack er upor theke delete kore dibo
        while(k>0 && !digit.empty()){
            digit.pop();
            k--;
        }
        string result = "";// result string

        while(!digit.empty()){// result a reverse akare string ta thkbe
            result.push_back(digit.top());
            digit.pop();
        }
        // as reverse akare ase tai leading '0' gula string er last a thkbe..ja badd dewa lgbe
        while(!result.empty() && result.back() == '0'){
            result.pop_back();
        }
        // result empty hoye gele "0" return kora lgbe
        if(result.empty()) return "0";
        // ta nahole reverse string ke soja kora lgbe
        reverse(result.begin(), result.end());
        return result;
    }
};
