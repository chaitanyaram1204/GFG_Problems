class Solution {
  public:
    Node* addOne(Node* head) {
        if(head == NULL)
            return new Node(1);
        // Your Code here
        // return head of list after adding one
        if(head->next == NULL)
        {
            if(head->data == 9){
                Node* n = new Node(1);
                head->data = 0;
                n->next = head;
                return n;
            }
            else{
                head->data += 1;
                return head;
            }
        }
        stack<Node*>st;
        Node* node = head;
        while(node){
            st.push(node);
            node = node->next;
        }
        int carry = 1;
        while(!st.empty()){
            node = st.top();
            st.pop();
            int value = node->data;
            int re = value + carry;
            node->data = re%10;
            carry = re/10;
        }
        if(carry != 0){
            Node* result;
            result = new Node(1);
            result->next = head;
            return result;
        }
        return head;
    }
};