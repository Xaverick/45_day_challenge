

// All Unique Permutation In An Array
void solve(vector<int> &arr, int n, set<vector<int>> &ans, vector<int> temp, int i)
{

    if (temp.size() == arr.size())
    {
        ans.insert(temp);
        return;
    }

    int j = i;
    for (j; j < n; j++)
    {
        swap(arr[i], arr[j]);
        temp.push_back(arr[i]);
        solve(arr, n, ans, temp, i + 1);
        temp.pop_back();
        swap(arr[i], arr[j]);
    }
}

vector<vector<int>> uniquePerms(vector<int> &arr, int n)
{
    set<vector<int>> tempans;
    vector<vector<int>> ans;
    vector<int> temp;
    solve(arr, n, tempans, temp, 0);

    for (auto i : tempans)
    {
        ans.push_back(i);
    }

    return ans;
}


// Generate Parantheses

void solve(int openBracket, vector<string> &ans, string temp, int open){
    //base case
    if(openBracket <= 0){
        //close the open ones
        while(open > 0){
            temp.push_back(')');
            open--;
        }

        ans.push_back(temp);
        return;
    }

    //Either we can open if we have option
    temp.push_back('(');
    solve(openBracket - 1, ans, temp, open + 1);
    temp.pop_back();

    if(open > 0){
        temp.push_back(')');
        solve(openBracket, ans, temp, open - 1);
        temp.pop_back();
    }
    //Either we can close if we have option


}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string temp;
    solve(n, ans, temp, 0);
    return ans;
}



//Longest Repeating Character

int characterReplacement(string s, int k) {
        int maxlen = 0, maxfreq = 0, l = 0, r = 0;
        int hash[26] = {0}; 
        while(r < s.size()){
            hash[s[r] - 'A']++;
            maxfreq = max(maxfreq, hash[s[r] - 'A']);
            //Not Valid Substring so move l
            while(r-l+1 - maxfreq > k){
                hash[s[l] - 'A']--;
                maxfreq = 0;
                //updatinfg max frequency
                for(int j = 0; j < 26; j++){
                    maxfreq = max(maxfreq, hash[j]);
                }
                l = l + 1;
            }
            // If i am coming here then i am sure that I have A valid Substring
            if(r-l+1 - maxfreq <= k){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
