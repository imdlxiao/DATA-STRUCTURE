// Created by Tsunami on 2023/12/14.
//Created by dlx on 2023/11/3.
#include <iostream>

using namespace std;

struct Node {
    int coefficient;//系数
    int exponent;   //指数
    Node *next;
};
Node *last = new Node; //  尾指针永远指向尾节点


/**
 * 创建节点
 * @param coefficient 接收的系数
 * @param exponent    接收的指数
 * @return 每次创建的新结点
 */
Node *creatPolynomial(int coefficient, int exponent) {
    Node *newNode = new Node;
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = nullptr;
    return newNode;
}

/**
 * 采用尾插法创建链表、链接链表结点
 * @param head          头节点
 * @param coefficient   接收的系数
 * @param exponent      接收的指数
 */
void polyn(Node **head, int coefficient, int exponent) {
    Node *newNode = creatPolynomial(coefficient, exponent);
    if (*head == nullptr) {   //如果头节点为空新节点就是头节点
        *head = newNode;
        last = *head;        //尾指针跟踪到末尾
    }
    last->next = newNode;   //尾插法开始:让当前节点指向新节点
    last = newNode;         //尾指针跟踪
    last->next = nullptr;
}

/**
 * 多项式合并排序从高到低进行    1.指数相同，系数相加   2.指数比大小
 * @param head1 链表1
 * @param head2 链表2
 * @return
 */
Node *polyAdd(Node *head1, Node *head2) {
    Node *cHead = new Node; //要实现合并后的容器
    Node *firstNode = cHead; // 用于跟踪第一次插入的节点
    Node *cLast;  //  尾节点准备跟踪
    cLast = cHead;
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->exponent > head2->exponent) {//!从高到低开始链
            cLast->next = head1;
            cLast = head1;
            head1 = head1->next;    //被链走的指针往下一位
        } else if (head1->exponent < head2->exponent) {
            cLast->next = head2;
            cLast = head2;
            head2 = head2->next;
        } else if (head1->exponent == head2->exponent) {//!指数相同
            if (head1->coefficient + head2->coefficient == 0) { //!1.相加变为0
                head1 = head1->next;    //两个结点都无了下一个
                head2 = head2->next;
            } else {                                    //!2.相加不是负就是正
                Node *coeAdd = new Node;   //新建结点用来存放两个结点相加
                coeAdd->coefficient = head2->coefficient + head1->coefficient;
                coeAdd->exponent = head1->exponent;
                coeAdd->next = nullptr;
                cLast->next = coeAdd;
                cLast = coeAdd;
                head1 = head1->next;    //两个结点都被用到了所以下一个
                head2 = head2->next;
                delete coeAdd;
            }
        }
    }
    if (head1 != nullptr) {//!防止对比后有一个链表为空，不为空的链表剩下数据未插入
        cLast->next = head1;
    } else if (head2 != nullptr) {
        cLast->next = head2;
    }
    // 将第一次插入的节点设置为cHead的头节点
    if (firstNode->next != nullptr) {
        cHead = firstNode->next;
    }
    firstNode->next = nullptr; // 将第一次插入的节点断开连接
    return cHead;
}

/**
 *
 * @param head  计算的多项式
 * @param x     给定的变量数
 * @return      结果
 */
int polyCalculate(Node *head, int x) {
    int result = 0;     //结果
    int resultExp = 1;  //幂结果
    while (head != nullptr) {//遍历整个链表
        for (int i = 0; i < head->exponent; i++) {//幂几次就乘几次
            resultExp = resultExp * x;
        }
        result = result + head->coefficient * resultExp;//结果递增
        resultExp = 1;  //防止重复使用，强行初始化
        head = head->next;
    }
    return result;
}

//输出符号
void printSymbol(int i) {
    if (i == 1) {
        cout << "+";
    } else {
        return;
    }
}

//打印多项式
void printPolynomial(Node *head) {
    if (head == nullptr) {
        cout << "当前链表为空" << endl;
    } else {
        while (head) {
            if (head->exponent == 0) {//第一种大情况单项式为常数项
                if (head->coefficient > 0) {
                    printSymbol(1);
                }
                cout << head->coefficient;
            } else {//第二种大情况为一般项分两种情况
                if (head->coefficient > 0) {//系数为正
                    printSymbol(1);
                    cout << head->coefficient << "X^" << head->exponent;
                } else {//系数为负
                    cout << head->coefficient << "X^" << head->exponent;
                }
            }
            head = head->next;
        }
    }
}


int main() {
    //创建A(x)=1-8x^6+2x^8+7x^12
    Node *aHead = nullptr;//头节点初始化
    polyn(&aHead, 7, 12);
    polyn(&aHead, 2, 8);
    polyn(&aHead, -8, 6);
    polyn(&aHead, 1, 0);
    cout << "A(x)=";
    printPolynomial(aHead);

    //创建B(x)=-x^4+8x^6-3x^10+8x^12+5x^15
    Node *bHead = nullptr;//头节点初始化
    polyn(&bHead, 5, 15);
    polyn(&bHead, 8, 12);
    polyn(&bHead, -3, 10);
    polyn(&bHead, 8, 6);
    polyn(&bHead, -1, 4);
    cout << endl << "B(x)=";
    printPolynomial(bHead);

    //合并多项式并打印出来
    cout << endl << "C(x)=";
    Node *cHead = nullptr;//头节点初始化
    cHead = polyAdd(aHead, bHead);
    printPolynomial(cHead);

    //多项式C(x)赋值x计算
    int result = polyCalculate(cHead, 3);
    cout << endl << "多项式C(x)赋值3：C(3)=" << result;
}
