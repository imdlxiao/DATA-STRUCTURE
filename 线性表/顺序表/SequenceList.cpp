//Created by Tsunami 12/12
#include <iostream>

#define MAXSIZE 100
using namespace std;

struct SequenceList {
    int data[MAXSIZE]; //顺序表静态数组最大容量
    int length;        //顺序表长度
};

/**
 * 顺序表的初始化
 * @param L 指向顺序表的指针引用
 */
void Init(SequenceList *&L) {
    L = new SequenceList;
    L->length = 0;
}

/**
 * 顺序表的创建
 * @param L
 * @param data 数组
 * @param length 数组长度
 */
void CreatSqlList(SequenceList *&L, const int data[], int length) {
    L = new SequenceList;
    L->length = length;
    for (int i = 0; i < length; i++) {
        L->data[i] = data[i];
    }
}

/**
 * 顺序表的遍历
 * @param L
 */
void PrintList(SequenceList *L) {
    cout << endl;
    for (int i = 0; i < L->length; ++i) {
        cout << L->data[i] << " ";
    }
}

/**
 * 插入int类型的数据元素
 * @param L
 * @param i
 * @param num
 * @return
 */
bool insertIntList(SequenceList *&L, int i, int num) {//第i个位置，值
    if ((L->length == MAXSIZE) || (i < 1 || i > L->length + 1)) {//防止顺序表超载 和 插入位置不对
        return false;
    } else {
        i--;    //逻辑位置改为数组位置
        for (int j = L->length; j > i; j--) {
            L->data[j] = L->data[j - 1];
        }
        L->data[i] = num;
        L->length++;
        return true;
    }
}

/**
 * 删除第i个数据元素
 * @param L
 * @param i
 * @return
 */
bool deleteIntList(SequenceList *&L, int i) {
    if ((L->length == MAXSIZE) || (i < 1 || i > L->length + 1)) {//防止顺序表超载 和 插入位置不对
        return false;
    } else {
        i--;    //逻辑转数组
        for (int j = i; j < L->length - 1; j++) {
            L->data[i] = L->data[i + 1];
        }
        L->length--;
        return true;
    }
}

int main() {
    SequenceList *L;
    int data[] = {1, 2, 3, 4, 5, 6};
    int length = 6;
    Init(L);
    CreatSqlList(L, data, length);      //创建和初始化
    PrintList(L);

    insertIntList(L, 6, 15);    //插入数据操作
    PrintList(L);

    deleteIntList(L, 3);            //删除数据操作
    PrintList(L);
}