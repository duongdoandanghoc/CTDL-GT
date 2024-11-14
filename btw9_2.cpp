#include <iostream>  
#include <string>  

using namespace std;  

struct File {  
    string tenFile;  
    long sz; 
    string time; 
};  

struct Node {  
    File data;  
    Node* link;  
};  

struct List {  
    Node* first;  
};  

void initList(List& list) {  
    list.first = NULL;  
}  

void insertFileSorted(List& list, File newFile) {  
    Node* newNode = new Node;  
    newNode->data = newFile;  
    newNode->link = NULL;  

    if (list.first == NULL || list.first->data.time > newFile.time) {  
        newNode->link = list.first;  
        list.first = newNode;  
    } else {  
        Node* current = list.first;  
        while (current->link != NULL && current->link->data.time < newFile.time) {  
            current = current->link;  
        }  
        newNode->link = current->link;  
        current->link = newNode;  
    }  
}  

void printList(List list) {  
    Node* current = list.first;  
    while (current != NULL) {  
        cout << "Ten File: " << current->data.tenFile << ", Kich Thuoc: " << current->data.sz << " Byte, Thoi Gian: " << current->data.time << endl;  
        current = current->link;  
    }  
}  

long calculateTotalSize(List list) {  
    long totalSize = 0;  
    Node* current = list.first;  
    while (current != NULL) {  
        totalSize += current->data.sz;  
        current = current->link;  
    }  
    return totalSize;  
}  

void deleteSmallestFiles(List& list, long spaceNeeded) {  
    while (calculateTotalSize(list) > spaceNeeded) {  
        Node* minPrev = NULL;  
        Node* minNode = list.first;  
        Node* current = list.first;  
        Node* currentPrev = NULL;  

        while (current != NULL) {  
            if (current->data.sz < minNode->data.sz) {  
                minNode = current;  
                minPrev = currentPrev;  
            }  
            currentPrev = current;  
            current = current->link;  
        }  

        if (minPrev == NULL) {  
            list.first = minNode->link; 
        } else {  
            minPrev->link = minNode->link; 
        }  
        
        delete minNode;  
    }  
}  

int main() {  
    List fileList;  
    initList(fileList);  

    // Thêm các file m?u  
    File file1 = {"file1.txt", 5000000, "2024-11-01 10:00:00"};  
    File file2 = {"file2.jpg", 3000000, "2024-10-25 12:30:00"};  
    File file3 = {"file3.pdf", 7500000, "2024-11-05 08:15:00"};  
    File file4 = {"file4.docx", 2000000, "2024-11-10 09:00:00"};  

    insertFileSorted(fileList, file1);  
    insertFileSorted(fileList, file2);  
    insertFileSorted(fileList, file3);  
    insertFileSorted(fileList, file4);  

    cout << "Danh sach file trong thu muc:" << endl;  
    printList(fileList);  

    long totalSize = calculateTotalSize(fileList);  
    cout << "Tong kich thuoc cac file: " << totalSize << " Byte" << endl;  

    const long usbCapacity = 32 * 1024 * 1024 * 1024;  
    cout << "Kich thuoc USB: " << usbCapacity << " Byte" << endl;  

    if (totalSize > usbCapacity) {  
        cout << "Kich thuoc file lon hon USB, can xoa file nho nhat." << endl;  
        deleteSmallestFiles(fileList, usbCapacity);  
    }  

    cout << "Danh sach file sau khi xoa file nho nhat de sao luu:" << endl;  
    printList(fileList);  

    return 0;  
}
