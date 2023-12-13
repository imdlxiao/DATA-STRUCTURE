// Created by Tsunami on 2023/12/14.
#include <iostream>
/**
 * 这是我用C和C++混合完成的一个最基础最傻瓜式的创建链表并遍历
 */
//定义一个结构体用来定义结点
struct Node {
    int data;
    struct Node *next;
};

int main() {
    Node *head = (Node *) malloc(sizeof(Node));//定义头结点
    Node *node1 = (Node *) malloc(sizeof(Node));//因为malloc返回的是一个void*的指针所以要强转
    Node *node2 = (Node *) malloc(sizeof(Node));
    head->next = node1;
    node1->data = 1;
    node1->next = node2;
    node2->data = 2;
    node2->next = nullptr;

    //循环遍历链表
    Node *current = head->next;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}
