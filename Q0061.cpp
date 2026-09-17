/*61. Rotate List*/

/*
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 10^9
 
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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode* curr=head,*tail=NULL;
        while(curr!=NULL){
            n++;
            if(curr->next==NULL){
                tail=curr;
            }
            curr=curr->next;
        }
        if(n<=1){
            return head;
        }      
        k=k%n;
        if(k==0){
            return head;
        }
        ListNode* nhead=NULL,*ntail=NULL;
        int moves=n-k;
        curr=head;
        for(int i=1;i<=moves;i++){
            if(i==moves){
                ntail=curr;
            }
            curr=curr->next;
        }
        nhead=curr;
        tail->next=head;
        ntail->next=NULL;
        return nhead;
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
    int n;
    cin>>n;
    ListNode* head=NULL;
    ListNode* tail=NULL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ListNode* newNode=new ListNode(x);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    int k;
    cin>>k;
    Solution obj;
    head=obj.rotateRight(head,k);
    print(head);
    return 0;
}