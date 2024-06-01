class Solution
{
public:
    string oddEven(string s)
    {
        int x = 0, y = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        for (auto ch : mp)
        {
            if ((ch.first % 2 == 0) && (ch.second % 2 == 0))
            {
                // cout<<"Even "<<ch.first<<" "<<ch.second<<endl;
                x++;
            }
            else if (ch.first % 2 && ch.second % 2 == 1)
            {
                // cout<<"Odd "<<ch.first<<" "<<ch.second<<endl;
                y++;
            }
        }
        // cout<<((x+y)%2)<<endl;
        return (x + y) % 2 == 0 ? "EVEN" : "ODD";
    }
};