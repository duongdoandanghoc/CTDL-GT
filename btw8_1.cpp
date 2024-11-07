#include <iostream>  
#include <cstring>  

using namespace std;  

struct Ngay {  
    int ngay, thang, nam;  
};  

struct SinhVien {  
    char maSV[8];  
    char hoTen[50];  
    int gioiTinh;  
    Ngay ngaySinh;  
    char diaChi[100];  
    char lop[12];  
    char khoa[7];  
};  

struct Node {  
    SinhVien data;  
    Node *link;  
};  

struct List {  
    Node *first;  
};  

void initList(List &list) {  
    list.first = NULL;  
}  

void insertStudentSorted(List &list, SinhVien sv) {  
    Node *newNode = new Node;  
    newNode->data = sv;  
    newNode->link = NULL;  

    if (list.first == NULL || strcmp(sv.maSV, list.first->data.maSV) < 0) {  
        newNode->link = list.first;  
        list.first = newNode;  
    } else {  
        Node *current = list.first;  
        while (current->link != NULL && strcmp(current->link->data.maSV, sv.maSV) < 0) {  
            current = current->link;  
        }  
        newNode->link = current->link;  
        current->link = newNode;  
    }  
}  

void printList(List list) {  
    Node *current = list.first;  
    while (current != NULL) {  
        cout << "Ma SV: " << current->data.maSV << endl;  
        cout << "Ho Ten: " << current->data.hoTen << endl;  
        cout << "Gioi Tinh: " << (current->data.gioiTinh == 0 ? "Nam" : "Nu") << endl;  
        cout << "Ngay Sinh: " << current->data.ngaySinh.ngay << "/"  
             << current->data.ngaySinh.thang << "/"  
             << current->data.ngaySinh.nam << endl;  
        cout << "Dia Chi: " << current->data.diaChi << endl;  
        cout << "Lop: " << current->data.lop << endl;  
        cout << "Khoa: " << current->data.khoa << endl;  
        cout << "------------------------" << endl;  
        current = current->link;  
    }  
}  

void findAndRemoveStudentsByDate(List &list, Ngay date) {  
    Node *current = list.first;  
    Node *prev = NULL;  
    bool found = false;  

    cout << "DSSV co cung ngay sinh " << date.ngay << ":" << endl;  

    while (current != NULL) {  
        if (current->data.ngaySinh.ngay == date.ngay) {  
            found = true;  
            cout << "Ma SV: " << current->data.maSV << ", Ho Ten: " << current->data.hoTen << endl;  
        }  
        current = current->link;  
    }  

    if (!found) {  
        cout << "Khong tim thay sinh vien cung ngay sinh" << endl;  
        return;  
    }  

    current = list.first;  
    prev = NULL;  

    while (current != NULL) {  
        if (current->data.ngaySinh.ngay == date.ngay) {  
            if (prev == NULL) {  
                list.first = current->link;  
                delete current;  
                current = list.first;  
            } else {  
                prev->link = current->link;  
                delete current;  
                current = prev->link;  
            }  
        } else {  
            prev = current;  
            current = current->link;  
        }  
    }  
    cout << "DS sau khi loai bo sinh vien co cung ngay sinh " << date.ngay << endl;  
}  

int main() {  
    List list;  
    initList(list);  

    const int fixedCount = 2;  
    SinhVien fixedStudents[fixedCount] = {  
        {"2022111", "Nguyen Van An", 0, {10, 10, 2004}, "Ha Tinh", "ET-E9 02", "DTVT"},  
        {"2022112", "Hoang Nguyen Bao", 0, {22, 11, 2004}, "Ha Noi", "ET-E9 01", "DTVT"},  
    };  

    for (int i = 0; i < fixedCount; i++) {  
        insertStudentSorted(list, fixedStudents[i]);  
    }  

    printList(list);  

    SinhVien newSV;  
    cout << "Nhap ma SV moi: ";  
    cin >> newSV.maSV;  
    cout << "Nhap ho ten: ";  
    cin.ignore();  
    cin.getline(newSV.hoTen, 50);  
    cout << "Nhap gioi tinh (0: Nam, 1: Nu): ";  
    cin >> newSV.gioiTinh;  
    cout << "Nhap ngay sinh (ngay thang nam): ";  
    cin >> newSV.ngaySinh.ngay >> newSV.ngaySinh.thang >> newSV.ngaySinh.nam;  
    cout << "Nhap dia chi: ";  
    cin.ignore();  
    cin.getline(newSV.diaChi, 100);  
    cout << "Nhap lop: ";  
    cin.getline(newSV.lop, 12);  
    cout << "Nhap khoa: ";  
    cin.getline(newSV.khoa, 7);  

    insertStudentSorted(list, newSV);  

    cout << "DSSV sau khi them sinh vien moi:" << endl;  
    printList(list);  

    Ngay searchDate = newSV.ngaySinh;  

    findAndRemoveStudentsByDate(list, searchDate);  
    printList(list);  

    return 0;  
}
