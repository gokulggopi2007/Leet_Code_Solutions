/*21. Merge Two Sorted Lists*/

/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
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
struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode* next):val(x),next(next){}
};
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(0);
        ListNode* cur=dummy;
        while(list1 && list2) {
            if (list1->val>list2->val) {
                cur->next=list2;
                list2=list2->next;
            } 
            else{
                cur->next=list1;
                list1=list1->next;
            }
            cur=cur->next;
        }
        cur->next=list1?list1:list2;

        ListNode* head=dummy->next;
        delete dummy;
        return head;        
    }
};
void print(ListNode* head){
    ListNode* curr=head;
    while(curr!=NULL){
        cout<<curr->val;
        if(curr->next!=NULL){
            cout<<" ";
        }
        curr=curr->next;
    }
    cout<<endl;
}
int main()
{
    int n,m;
    cin>>n>>m;
    ListNode* list1=NULL,*list2=NULL;
    ListNode* curr=NULL;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(list1==NULL){
            list1=new ListNode(x);
            curr=list1;
        }
        else{
            curr->next=new ListNode(x);
            curr=curr->next;
        }
    }
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        if(list2==NULL){
            list2=new ListNode(x);
            curr=list2;
        }
        else{
            curr->next=new ListNode(x);
            curr=curr->next;
        }
    }
    Solution s;
    ListNode* ans=s.mergeTwoLists(list1,list2);
    print(ans);
    return 0;
}
    