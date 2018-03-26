//
//  PreOrderBSTRecursive.cpp
//  Job2018
//
//  Created by Jiamei Shuai on 26/03/2018.
//
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v)
    {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* BuildTree(std::vector<int> vals)
{
    if(vals.size() < 1) return nullptr;
    
    TreeNode* root = new TreeNode(vals[0]);
    std::queue<TreeNode*> nodequeue;
    nodequeue.push(root);
    for(int i = 1; i < vals.size(); i++)
    {
        while(nodequeue.size() > 0)
        {
            TreeNode* parent = nodequeue.front();
            nodequeue.pop();
            
            // build left
            TreeNode* newNode = new TreeNode(vals[i]);
            parent->left = newNode;
            nodequeue.push(newNode);
            i++;
            // build right
            if(i < vals.size())
            {
                newNode = new TreeNode(vals[i]);
                parent->right = newNode;
                nodequeue.push(newNode);
                i++;
            }
            else return root;
        }
    }
    return root;
}

void PreOrderTraversal(TreeNode* root)
{
    if(!root) return;
    std::cout<<root->val<<"\t";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PreOrderRecursive(TreeNode* root)
{
    if(!root) return;
    
    std::stack<TreeNode*> nodestack;
    nodestack.push(root);
    while(!nodestack.empty())
    {
        TreeNode* root = nodestack.top();
        nodestack.pop();
        std::cout<<root->val<<"\t";
        if(root->right)                     // note this non-null predictive is important
        {
            nodestack.push(root->right);
        }
        if(root->left)
        {
            nodestack.push(root->left);
        }
    }
}



void InOrderTraversal(TreeNode* root)
{
    if(!root) return;
    InOrderTraversal(root->left);
    std::cout<<root->val<<"\t";
    InOrderTraversal(root->right);
}

int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8};
    TreeNode* root = BuildTree(vec);
    std::cout<<"PreOrder:"<<std::endl;
    PreOrderTraversal(root);
    std::cout<<"\nPreOrderRecursive"<<std::endl;
    PreOrderRecursive(root);
    std::cout<<"\nInOrder:"<<std::endl;
    InOrderTraversal(root);
    return 0;
}

















