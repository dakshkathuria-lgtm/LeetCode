class Encrypter {
public:

    map<char, string> mp;
    map<string, int>cnt;

    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i =0;i<keys.size();i++){
            mp[keys[i]] = values[i];
        }

        for(const string& word : dictionary){
            cnt[encrypt(word)]++;
        }
    }
    
    string encrypt(string word1) {
        string ans{""};
        for(int i =0;i<word1.size();i++){
            if(mp.count(word1[i])==0){
                return "";
            }
            ans = ans + mp[word1[i]];
        }
        return ans;
    }
    
    int decrypt(string word2) {
        return cnt[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */