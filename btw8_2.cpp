#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* taoVongTron(int N) {
    Node* head = new Node;
    head->data = 1;
    Node* prev = head;

    for (int i = 2; i <= N; i++) {
        Node* temp = new Node;
        temp->data = i;
        prev->next = temp;
        prev = temp;
    }
    prev->next = head;  
    return head;
}


int timNguoiChienThang(int N, int M) {

    if (M == 0) {
        return N;
    }

    Node* head = taoVongTron(N);
    Node* p = head;

    while (p->next != p) {
      
        for (int i = 1; i < M; i++) {
            p = p->next;
        }
        
        Node* temp = p->next;
        p->next = temp->next; 
        delete temp;
        p = p->next;  
    }
    int nguoiChienThang = p->data;
    delete p;  
    return nguoiChienThang;
}

int main() {
    int N, M;

    cout << "N: ";
    cin >> N;
    cout << "M: ";
    cin >> M;

    int nguoiChienThang = timNguoiChienThang(N, M);
    cout << nguoiChienThang << endl;

    return 0;
}
// Do phuc tap thuat toan O(N^2)

