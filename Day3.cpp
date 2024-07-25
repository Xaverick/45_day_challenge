// max water in a container

int maxArea(vector<int> &height)
{
    int area = 0;
    int i = 0, j = height.size() - 1;
    while (i < j)
    {
        int l = j - i;
        int h = min(height[i], height[j]);
        area = max(area, l * h);
        if (height[i] > height[j])
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return area;
}

// Simplfy Path
string simplifyPath(string path)
{
    string s = "/";
    int i = 1, j = 0;
    while (i < path.size())
    {
        // cout<<path[i]<<" "<<s[j]<<endl;
        if (path[i] == '/' && s[j] == '/')
        {
            i++;
            continue;
        }

        s.push_back(path[i]);
        i++, j++;
    }

    vector<string> parts;
    for (int i = 1; i < s.size(); i++)
    {
        string temp;
        while (s[i] != '/' && i < s.size())
        {
            temp.push_back(s[i]);
            i++;
        }
        parts.push_back(temp);
    }

    vector<string> finalPath;
    for (int i = 0; i < parts.size(); i++)
    {
        if (parts[i] == "..")
        {
            if (finalPath.size() > 0)
                finalPath.pop_back();
            continue;
        }
        else if (parts[i] == ".")
        {
            continue;
        }
        else
        {
            finalPath.push_back(parts[i]);
        }
    }

    string ans;
    for (int i = 0; i < finalPath.size(); i++)
    {
        ans.push_back('/');
        ans += finalPath[i];
    }

    if (ans == "")
        return "/";

    return ans;
}

// Group Anagram
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> hash;
    vector<vector<string>> ans;
    int n = strs.size();

    for (int i = 0; i < n; i++)
    {
        string sortedstr = strs[i];
        sort(sortedstr.begin(), sortedstr.end());
        hash[sortedstr].push_back(strs[i]);
    }

    for (auto it = hash.begin(); it != hash.end(); ++it)
    {
        ans.push_back(it->second);
    }

    return ans;
}

//  Integer to roman
bool subForm(int n)
{
    if (n == 9 || n == 4)
        return true;

    return false;
}

string numtoRoman(int n, int decimal)
{
    int arr[7] = {1, 5, 10, 50, 100, 500, 1000};
    char symbol[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    string ans = "";
    int start = n / decimal;
    if (subForm(start))
    {
        if (n == 4)
            return "IV";
        else if (n == 9)
            return "IX";
        else if (n == 40)
            return "XL";
        else if (n == 90)
            return "XC";
        else if (n == 400)
            return "CD";
        else
            return "CM";
    }

    else
    {
        int i = 6;
        while (n && i >= 0)
        {
            if (n - arr[i] >= 0)
            {
                ans = ans + symbol[i];
                n -= arr[i];
                i = 6;
            }
            else
            {
                i--;
            }
        }
    }

    return ans;
}

string intToRoman(int num)
{
    string ans;
    int i = 0;
    while (num)
    {
        int n = num % 10;
        n = n * pow(10, i);
        string temp = numtoRoman(n, pow(10, i));
        ans = temp + ans;
        num = num / 10;
        i++;
    }

    return ans;
}