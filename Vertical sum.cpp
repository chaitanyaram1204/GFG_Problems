class Solution
{
public:
    vector<int> verticalSum(Node *root)
    {
        map<int, map<int, multiset<int>>> nodes;

        queue<pair<Node *, pair<int, int>>> todo;
        todo.push({root, {0, 0}});

        while (!todo.empty())
        {
            auto p = todo.front();
            todo.pop();
            Node *temp = p.first;

            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(temp->data);
            if (temp->left)
            {
                todo.push({temp->left, {x - 1, y + 1}});
            }
            if (temp->right)
            {
                todo.push({temp->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        vector<int> result;
        for (auto &i : ans)
        {
            int sum = 0;
            for (int j = 0; j < i.size(); j++)
            {
                sum += i[j];
            }
            result.push_back(sum);
        }
        return result;
    }
};