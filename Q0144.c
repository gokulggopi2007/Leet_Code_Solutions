/*144. Binary Tree Preorder Traversal*/

/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [1,2,4,5,6,7,3,8,9]

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
#include<stdio.h>    
#include<stdlib.h>    
#include<string.h>  
#include<math.h>      
#include<time.h>     
#include<ctype.h>     
#include<limits.h>    
#include<float.h>     
#include<stdbool.h>   
#include<stdint.h>    
#include<assert.h>    
#include<errno.h>    
#include<locale.h>    
#include<wchar.h> 
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *root=NULL;
struct TreeNode* createNode(int val){
    struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}

struct TreeNode* buildTree(char *input) {
    struct TreeNode* nodes[100];
    struct TreeNode* queue[100];
    int count=0,front=0,rear=0;
    char *token=strtok(input,"[],\n\r");
    while(token!=NULL){
        if(strcmp(token,"null")==0)
            nodes[count++]=NULL;
        else
            nodes[count++]=createNode(atoi(token));

        token=strtok(NULL,"[],\n\r");
    }
    if(count==0||nodes[0]==NULL)
        return NULL;
    struct TreeNode* root=nodes[0];
    queue[rear++]=root;
    int i=1;
    while(front<rear && i<count){
        struct TreeNode* current=queue[front++];
        if (i<count){
            current->left=nodes[i++];
            if (current->left)
                queue[rear++]=current->left;
        }
        if(i<count){
            current->right=nodes[i++];
            if(current->right)
                queue[rear++]=current->right;
        }
    }
    return root;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void preorder(struct TreeNode* root,int* arr,int *count){
    if(root==NULL){
        return ;
    }
    arr[(*count)++]=root->val;
    preorder(root->left,arr,count);
    preorder(root->right,arr,count);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *arr=(int*)malloc(300*sizeof(int));
    *returnSize=0;
    preorder(root,arr,returnSize);
    return arr;
}
int main(){
    char input[10000];
    fgets(input,sizeof(input),stdin);
    struct TreeNode* root=buildTree(input);
    int returnSize;
    int *result=preorderTraversal(root,&returnSize);
    for(int i=0;i<returnSize;i++){
        printf("%d ",result[i]);
    }
    free(result);
    return 0;
}