class MyLinkedList {
private:
    struct Node {
        int val;
        Node *next;
        Node(int val, Node *node) : val(val), next(node) {}
    };
    int size;
    Node *dummyHead;

public:
    MyLinkedList() {
        size = 0;
        dummyHead = new Node(0, nullptr);
    }

    int get(int index) {
        if(index < 0 || index >= size) {
            return -1;
        }
        Node *temp = dummyHead;
        for(int i = 0; i <= index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        Node *node = new Node(val, dummyHead->next);
        dummyHead->next = node;
        size++;
    }

    void addAtTail(int val) {
        Node *node = new Node(val, nullptr);
        Node *cur = dummyHead;
        int num = size;
        while(num--) {
            cur = cur->next;
        }
        cur->next = node;
        size++;
    }

    void addAtIndex(int index, int val) {
        if(index > size) {
            return;
        }
        if(index == size) {
            addAtTail(val);
            return;
        }
        Node *node = new Node(val, nullptr);
        Node *cur = dummyHead;
        while(index--) {
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        size++;
        return;
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) {
            return;
        }
        Node *cur = dummyHead;
        while(index--) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        size--;
    }
};
