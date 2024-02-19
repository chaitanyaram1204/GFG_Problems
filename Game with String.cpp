class Solution
{
public:
    int minValue(string s, int k)
    {
        unordered_map<char, int> mp;
        priority_queue<int> heap;

        for (auto &i : s)
        {
            mp[i]++;
        }

        for (auto &i : mp)
        {
            heap.push(i.second);
        }

        while (k != 0)
        {
            int top = heap.top();
            heap.pop();
            heap.push(--top);
            k--;
        }

        int ans = 0;
        while (!heap.empty())
        {
            int top = heap.top();
            heap.pop();
            ans += (top * top);
        }
        return ans;
    }
};