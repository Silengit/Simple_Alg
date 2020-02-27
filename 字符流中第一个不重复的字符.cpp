class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
         dict[ch] ++;
         str.push_back(ch);
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(auto &ch : str)
            if(dict[ch] == 1)
                return ch;
        return '#';
    }
    map<char, int> dict;
    string str;
};