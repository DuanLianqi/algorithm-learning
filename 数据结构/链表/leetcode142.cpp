#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> uset;
        ListNode *cur = head;
        while(cur) {
            if(uset.contains(cur)) {
                return cur;
            }
            uset.insert(cur);
            cur = cur->next;
        }
        return nullptr;
    }
};
