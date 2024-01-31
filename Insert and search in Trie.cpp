class Solution
{
public:
    // Function to insert string into TRIE.
    void insert(struct TrieNode *root, string key)
    {
        for (auto i : key)
        {
            if (root->children[i - 'a'])
            {
                root = root->children[i - 'a'];
            }
            else
            {
                TrieNode *newNode = getNode();
                root->children[i - 'a'] = newNode;
                root = root->children[i - 'a'];
            }
        }
        root->isLeaf = 1;
    }

    // Function to use TRIE data structure and search the given string.
    bool search(struct TrieNode *root, string key)
    {
        for (auto i : key)
        {
            if (root->children[i - 'a'])
            {
                root = root->children[i - 'a'];
            }
            else
            {
                return 0;
            }
        }
        return root->isLeaf;
    }
};