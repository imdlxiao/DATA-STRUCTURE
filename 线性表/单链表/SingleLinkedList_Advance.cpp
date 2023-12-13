// Created by Tsunami on 2023/12/14.
#include <iostream>

/**
 * 链表创建升级版
 * 本实验用data数组实现尾插法建表
 */
struct Node {
    int data;
    struct Node *next;
} *head, *end, *cursor;  //分别是头节点、尾节点、遍历指针

int data_length = 4;
int data[] = {1, 3, 5, 7};


int main() {
    head = new Node; //创建头节点
    end = head;     //空表尾节点跟踪
    for (int i = 0; i < data_length; i++) {
        Node *newNode = new Node;   //创建新节点
        newNode->data = data[i];
        end->next = newNode;        //前节点和新节点的链接
        end = newNode;              //尾节点跟踪
    }
    end->next = nullptr;            //结束链表

    //打印遍历链表
    cursor = head;
    cursor = cursor->next;          //防止打印了没有数据域的头结点 于是跳过头结点
    while (cursor != nullptr) {
        std::cout << cursor->data << std::endl;
        cursor = cursor->next;
    }

    // 释放链表占用的内存空间，防止内存泄漏
    delete head;
    delete cursor;
    delete end;
}
