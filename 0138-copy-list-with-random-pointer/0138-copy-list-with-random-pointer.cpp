/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;

        Node* originalTrav = head;
        Node* copyNodeTrav = new Node(0);
        Node* copyPointer = copyNodeTrav;

        map<Node*,Node*> nodeToCopyNode;
        while(originalTrav){
            Node* newNode = new Node(originalTrav->val);
            copyNodeTrav->next = newNode;
            nodeToCopyNode[originalTrav] = newNode;
            originalTrav = originalTrav->next;
            copyNodeTrav= copyNodeTrav->next;
        }
        originalTrav = head;
        copyNodeTrav = copyPointer->next;
        while(originalTrav){
            Node* randAddress = nodeToCopyNode[originalTrav->random];
            copyNodeTrav->random = randAddress;

            copyNodeTrav = copyNodeTrav->next;
            originalTrav = originalTrav->next;
        }
        return copyPointer->next;

    }
};