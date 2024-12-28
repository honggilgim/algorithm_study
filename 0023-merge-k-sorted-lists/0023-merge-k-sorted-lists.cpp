/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> node;
        for(int i=0; i<lists.size(); i++) {
            if(lists[i] == nullptr)
                continue;
            queue<ListNode> q;
            q.push(*lists[i]);
            while(!q.empty()) {
                ListNode a = q.front();
                q.pop();
                if(a.next != nullptr)
                    q.push(*a.next);
                node.push_back(a.val);
            }
        }

        sort(node.begin(),node.end());
        /*for(auto k : node) {
            cout << k;
        }*/

        if(node.size() == 0)
            return nullptr;
        else {
            ListNode* ans = new ListNode(node[0]); // 첫 번째 노드 생성
            ListNode* current = ans;

            for (int i = 1; i < node.size(); i++) {
                current->next = new ListNode(node[i]); // 다음 노드 생성 및 연결
                current = current->next;             // 현재 노드를 갱신
            }

            return ans;
        }
   
    }
};