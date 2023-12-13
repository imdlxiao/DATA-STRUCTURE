//Created by Tsunami 12/12
#include <iostream>

#define MAXSIZE 100
using namespace std;

struct SequenceList {
    int data[MAXSIZE]; //˳���̬�����������
    int length;        //˳�����
};

/**
 * ˳���ĳ�ʼ��
 * @param L ָ��˳����ָ������
 */
void Init(SequenceList *&L) {
    L = new SequenceList;
    L->length = 0;
}

/**
 * ˳���Ĵ���
 * @param L
 * @param data ����
 * @param length ���鳤��
 */
void CreatSqlList(SequenceList *&L, const int data[], int length) {
    L = new SequenceList;
    L->length = length;
    for (int i = 0; i < length; i++) {
        L->data[i] = data[i];
    }
}

/**
 * ˳���ı���
 * @param L
 */
void PrintList(SequenceList *L) {
    cout << endl;
    for (int i = 0; i < L->length; ++i) {
        cout << L->data[i] << " ";
    }
}

/**
 * ����int���͵�����Ԫ��
 * @param L
 * @param i
 * @param num
 * @return
 */
bool insertIntList(SequenceList *&L, int i, int num) {//��i��λ�ã�ֵ
    if ((L->length == MAXSIZE) || (i < 1 || i > L->length + 1)) {//��ֹ˳����� �� ����λ�ò���
        return false;
    } else {
        i--;    //�߼�λ�ø�Ϊ����λ��
        for (int j = L->length; j > i; j--) {
            L->data[j] = L->data[j - 1];
        }
        L->data[i] = num;
        L->length++;
        return true;
    }
}

/**
 * ɾ����i������Ԫ��
 * @param L
 * @param i
 * @return
 */
bool deleteIntList(SequenceList *&L, int i) {
    if ((L->length == MAXSIZE) || (i < 1 || i > L->length + 1)) {//��ֹ˳����� �� ����λ�ò���
        return false;
    } else {
        i--;    //�߼�ת����
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
    CreatSqlList(L, data, length);      //�����ͳ�ʼ��
    PrintList(L);

    insertIntList(L, 6, 15);    //�������ݲ���
    PrintList(L);

    deleteIntList(L, 3);            //ɾ�����ݲ���
    PrintList(L);
}