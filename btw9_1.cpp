#include <iostream>
using namespace std;

struct Node {
    int coef;   
    int exp;   
    Node* next;
};

Node* taoNode(int coef, int exp) {
    Node* newNode = new Node;
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void themNode(Node*& head, int coef, int exp) {
    Node* newNode = taoNode(coef, exp);
    if (!head || head->exp < exp) {  
        newNode->next = head;
        head = newNode;
    } else {
        Node* p = head;
        while (p->next && p->next->exp > exp) {
            p = p->next;
        }
        if (p->exp == exp) { 
            p->coef += coef;
            delete newNode;
        } else {  
            newNode->next = p->next;
            p->next = newNode;
        }
    }
}

Node* congDaThuc(Node* p1, Node* p2) {
    Node* ketQua = NULL;
    while (p1 && p2) {
        if (p1->exp == p2->exp) {
            themNode(ketQua, p1->coef + p2->coef, p1->exp);
            cout << "Cong bac " << p1->exp << " voi he so tong: " << p1->coef + p2->coef << endl;
            cout << "Dia chi luu tru: " << ketQua << endl;
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            themNode(ketQua, p1->coef, p1->exp);
            cout << "Sao chep tu da thuc 1 bac " << p1->exp << " voi he so: " << p1->coef << endl;
            cout << "Dia chi luu tru: " << ketQua << endl;
            p1 = p1->next;
        } else {
            themNode(ketQua, p2->coef, p2->exp);
            cout << "Sao chep tu da thuc 2 bac " << p2->exp << " voi he so: " << p2->coef << endl;
            cout << "Dia chi luu tru: " << ketQua << endl;
            p2 = p2->next;
        }
    }

    while (p1) {
        themNode(ketQua, p1->coef, p1->exp);
        cout << "Sao chep tu da thuc 1 bac " << p1->exp << " voi he so: " << p1->coef << endl;
        cout << "Dia chi luu tru: " << ketQua << endl;
        p1 = p1->next;
    }
    while (p2) {
        themNode(ketQua, p2->coef, p2->exp);
        cout << "Sao chep tu da thuc 2 bac " << p2->exp << " voi he so: " << p2->coef << endl;
        cout << "Dia chi luu tru: " << ketQua << endl;
        p2 = p2->next;
    }

    return ketQua;
}

void inDaThuc(Node* head) {
    while (head) {
        cout << head->coef << "x^" << head->exp;
        if (head->next)
            cout << " + ";
        head = head->next;
    }
    cout << endl;
}

void xoaDanhSach(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* daThuc1 = NULL;
    Node* daThuc2 = NULL;

    themNode(daThuc1, 3, 4);
    themNode(daThuc1, 5, 2);
    themNode(daThuc1, 6, 0);

    themNode(daThuc2, 4, 3);
    themNode(daThuc2, 2, 2);
    themNode(daThuc2, 7, 0);

    cout << "Da thuc 1: ";
    inDaThuc(daThuc1);

    cout << "Da thuc 2: ";
    inDaThuc(daThuc2);

    Node* ketQua = congDaThuc(daThuc1, daThuc2);

    cout << "Tong hai da thuc: ";
    inDaThuc(ketQua);

    xoaDanhSach(daThuc1);
    xoaDanhSach(daThuc2);
    xoaDanhSach(ketQua);

    return 0;
}

