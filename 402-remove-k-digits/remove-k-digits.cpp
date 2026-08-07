class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        for(int i =0;i<n;i++){
            while(!st.empty() and st.top() > num[i] && k!=0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(!st.empty() and k!=0){
            st.pop();
            k--;
        }

        string res = "";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        int i = 0;
        while(i<res.size() and res[i]=='0'){
            i++;
        }
        if(i==res.size()){
            return "0";
        }
        return res.substr(i);
    }
};