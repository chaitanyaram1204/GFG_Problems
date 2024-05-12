class Solution
{
public:
    int minSteps(int d)
    {
        int pos = 0;
        int steps = 0;
        while (pos < d || (pos - d) % 2 != 0)
        {
            steps++;
            pos += steps;
        }
        return steps;
    }
};