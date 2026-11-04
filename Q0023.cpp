/*23. Merge k Sorted Lists*/

/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []
 

Constraints:
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 10^4.
*/
#include<iostream>
#include<vector>
#include<map>
#include<numeric>
#include<iomanip>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_set>
#include<queue>
using namespace std;
#define ll long long int 
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
struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *next):val(x),next(next){}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto node:lists){
            while(node){
                pq.push(node->val);
                node=node->next;
            }
        }
        ListNode gokul(0);
        ListNode* tail=&gokul;
        while(!pq.empty()){
            tail->next=new ListNode(pq.top());
            tail=tail->next;
            pq.pop();
        }
        return gokul.next;
    }
};
void printList(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    return ;
}
int main()
{
    int n;
    cin>>n;
    vector<ListNode*> lists;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            ListNode* node=new ListNode(x);
            if(head==NULL){
                head=tail=node;
            }
            else{
                tail->next=node;
                tail=node;
            }
        }
        lists.push_back(head);
    }
    Solution s;
    ListNode* ans=s.mergeKLists(lists);
    printList(ans);
    return 0;
}