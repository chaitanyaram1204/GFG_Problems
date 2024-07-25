class Solution
{
public:
    Node *binarytree(vector<int> &nums, int low, int high)
    {
        if (low <= high)
        {
            int mid = low + (high - low) / 2;
            Node *root = new Node(nums[mid]);
            root->left = binarytree(nums, low, mid - 1);
            root->right = binarytree(nums, mid + 1, high);
            return root;
        }
        return NULL;
    }
    Node *sortedArrayToBST(vector<int> &nums)
    {
        return binarytree(nums, 0, nums.size() - 1);
    }
};