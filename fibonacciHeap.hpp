#ifndef FIBONACCIHEAP_HPP_
#define FIBONACCIHEAP_HPP_
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <malloc.h>

using namespace std;

struct node {
    node* parent; // 父级指针
    node* child; // 子类指针
    node* left; // 指向左边的节点的指针
    node* right; // 指向右边的节点的指针
    pair<int,int> key; // 节点的数值
    int degree; 
    char mark; // 节点的黑色或白色标记
    char c; // 用于协助查找节点功能的标志
};

class fibonacciHeap{
private:

    // 创建最小指针为 "mini"
    struct node* mini = NULL;
  
    // 声明一个整数，表示堆中的节点数
    int no_of_nodes = 0;

public:
    // 在堆中插入一个节点的函数
    void insertion(pair<int,int> val){

        struct node* new_node = new node();
        new_node->key = val;
        new_node->degree = 0;
        new_node->mark = 'W';
        new_node->c = 'N';
        new_node->parent = NULL;
        new_node->child = NULL;
        new_node->left = new_node;
        new_node->right = new_node;
        if (mini != NULL) {
            (mini->left)->right = new_node;
            new_node->right = mini;
            new_node->left = mini->left;
            mini->left = new_node;
            if (new_node->key.first < mini->key.first)
                mini = new_node;
        }else {
            mini = new_node;
        }
        no_of_nodes++;
    }

    void Fibonnaci_link(struct node* ptrA, struct node* ptrB){
        (ptrA->left)->right = ptrA->right;
        (ptrA->right)->left = ptrA->left;
        if (ptrB->right == ptrB)
            mini = ptrB;
        ptrA->left = ptrA;
        ptrA->right = ptrA;
        ptrA->parent = ptrB;
        if (ptrB->child == NULL)
            ptrB->child = ptrA;
        ptrA->right = ptrB->child;
        ptrA->left = (ptrB->child)->left;
        ((ptrB->child)->left)->right = ptrA;
        (ptrB->child)->left = ptrA;
        if (ptrA->key.first < (ptrB->child)->key.first)
            ptrB->child = ptrA;
        ptrB->degree++;
    }

    void Consolidate(){
        int temp1;
        double temp2 = (log(no_of_nodes)) / (log(2));
        int temp3 = temp2;
        struct node* arr[temp3+1];
        for (int i = 0; i <= temp3; i++)
            arr[i] = NULL;
        node* ptr1 = mini;
        node* ptr2;
        node* ptr3;
        node* ptr4 = ptr1;
        do {
            ptr4 = ptr4->right;
            temp1 = ptr1->degree;
            while (arr[temp1] != NULL) {
                ptr2 = arr[temp1];
                if (ptr1->key.first > ptr2->key.first) {
                    ptr3 = ptr1;
                    ptr1 = ptr2;
                    ptr2 = ptr3;
                }
                if (ptr2 == mini)
                    mini = ptr1;
                Fibonnaci_link(ptr2, ptr1);
                if (ptr1->right == ptr1)
                    mini = ptr1;
                arr[temp1] = NULL;
                temp1++;
            }
            arr[temp1] = ptr1;
            ptr1 = ptr1->right;
        }while(ptr1 != mini);
        mini = NULL;
        for (int j = 0; j <= temp3; j++) {
            if (arr[j] != NULL) {
                arr[j]->left = arr[j];
                arr[j]->right = arr[j];
                if (mini != NULL) {
                    (mini->left)->right = arr[j];
                    arr[j]->right = mini;
                    arr[j]->left = mini->left;
                    mini->left = arr[j];
                    if (arr[j]->key.first < mini->key.first)
                        mini = arr[j];
                }else {
                    mini = arr[j];
                }
                if (mini == NULL)
                    mini = arr[j];
                else if (arr[j]->key.first < mini->key.first)
                    mini = arr[j];
            }
        }
    }
  
// 提取堆中最小节点的函数
void Extract_min()
{
    if (mini == NULL)
        cout << "The heap is empty" << endl;
    else {
        node* temp = mini;
        node* pntr;
        pntr = temp;
        node* x = NULL;
        if (temp->child != NULL) {
  
            x = temp->child;
            do {
                pntr = x->right;
                (mini->left)->right = x;
                x->right = mini;
                x->left = mini->left;
                mini->left = x;
                if (x->key.first < mini->key.first)
                    mini = x;
                x->parent = NULL;
                x = pntr;
            } while (pntr != temp->child);
        }
        (temp->left)->right = temp->right;
        (temp->right)->left = temp->left;
        mini = temp->right;
        if (temp == temp->right && temp->child == NULL)
            mini = NULL;
        else {
            mini = temp->right;
            Consolidate();
        }
        no_of_nodes--;
    }
}

void Cut(struct node* found, struct node* temp)
{
    if (found == found->right)
        temp->child = NULL;
  
    (found->left)->right = found->right;
    (found->right)->left = found->left;
    if (found == temp->child)
        temp->child = found->right;
  
    temp->degree = temp->degree - 1;
    found->right = found;
    found->left = found;
    (mini->left)->right = found;
    found->right = mini;
    found->left = mini->left;
    mini->left = found;
    found->parent = NULL;
    found->mark = 'B';
}
 

void Cascase_cut(struct node* temp)
{
    node* ptr5 = temp->parent;
    if (ptr5 != NULL) {
        if (temp->mark == 'W') {
            temp->mark = 'B';
        }
        else {
            Cut(temp, ptr5);
            Cascase_cut(ptr5);
        }
    }
}

void Decrease_key(struct node* found, int val)
{
    if (mini == NULL)
        cout << "The Heap is Empty" << endl;
  
    if (found == NULL)
        cout << "Node not found in the Heap" << endl;
  
    found->key.first = val;
  
    struct node* temp = found->parent;
    if (temp != NULL && found->key.first < temp->key.first) {
        Cut(found, temp);
        Cascase_cut(temp);
    }
    if (found->key.first < mini->key.first)
        mini = found;
}

void Find(struct node* mini, int old_val, int val)
{
    struct node* found = NULL;
    node* temp5 = mini;
    temp5->c = 'Y';
    node* found_ptr = NULL;
    if (temp5->key.first == old_val) {
        found_ptr = temp5;
        temp5->c = 'N';
        found = found_ptr;
        Decrease_key(found, val);
    }
    if (found_ptr == NULL) {
        if (temp5->child != NULL)
            Find(temp5->child, old_val, val);
        if ((temp5->right)->c != 'Y')
            Find(temp5->right, old_val, val);
    }
    temp5->c = 'N';
    found = found_ptr;
}

// 从堆中删除一个节点
void Deletion(int val)
{
    if (mini == NULL)
        cout << "The heap is empty" << endl;
    else {
  
        // 将该节点的值减少到0
        Find(mini, val, 0);
  
        // 调用Extract_min函数来
        // 删除最小值节点，该节点为0
        Extract_min();
        cout << "Key Deleted" << endl;
    }
}

bool is_empty(){
    return no_of_nodes == 0;
}

pair<int,int> get_min(){
    return mini->key;
}
  
~fibonacciHeap(){
        delete[] mini;
}
};
#endif