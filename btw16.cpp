#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Node
{
    string tde;
    int sotrang;
    Node* firstChild;
    Node* nextSibling;

    Node(string t, int trang) : tde(t), sotrang(trang), firstChild(NULL), nextSibling(NULL) {}
};

class Book{
    private:
    Node* root;

    int countChapters(Node* node) {  
        if (node == NULL) return 0;  

        int count = 1; // Đếm node hiện tại  
        Node* child = node->firstChild;  

        while (child != NULL) {  
            count += countChapters(child);  
            child = child->nextSibling;   
        }  

        return count;  
    }

    int findLongestChapter(Node* node) {  
        if (node == NULL) return 0;  

        int maxLength = node->tde.length(); 
        Node* child = node->firstChild;  

        while (child != NULL) {  
            maxLength = max(maxLength, findLongestChapter(child));   
            child = child->nextSibling;  
        }  

        return maxLength;  
    }    
    Node* findAndDelete(Node* node, const string& tde, bool& found) {  
        if (node == NULL) return NULL;  

        if (node->tde == tde) {  
            found = true;  
            // Cập nhật số trang cho các mục con trước khi xóa  
            int newPageCount = 0;  
            Node* child = node->firstChild;  
            while (child != NULL) {  
                newPageCount += child->sotrang;  
                child = child->nextSibling;  
            }  
            return node;
        }  

        Node* prev = NULL;  
        Node* current = node->firstChild;  

        while (current != NULL) {  
            Node* deletedNode = findAndDelete(current, tde, found);  
            if (found && prev == NULL) {  
                node->firstChild = current->nextSibling; // Xóa node đầu tiên  
            } else if (found) {  
                prev->nextSibling = current->nextSibling; // Xóa node giữa  
            }  

            if (deletedNode != NULL) {  
                delete deletedNode;   
                return NULL; 
            }  

            prev = current;  
            current = current->nextSibling;  
        }  
        
        return NULL;  
    }  

public:  
    Book() : root(NULL) {}  

    // Thêm một node mới vào cây  
    void addChapter(const string& tde, int pages) {  
        Node* newNode = new Node(tde, pages);  
        if (root == NULL) {  
            root = newNode; 
        } else {  
            Node* current = root;  
            while (current->firstChild != NULL) {  
                current = current->firstChild;  
            }  
            current->firstChild = newNode; 
        }  
    }  

    // Hàm đếm số chương  
    int countChapters() {  
        return countChapters(root); 
    }  

    // Hàm tìm chương dài nhất  
    int findLongestChapter() {  
        return findLongestChapter(root);   
    }  

    // Hàm tìm và xóa một mục  
    void deleteChapter(const string& tde) {  
        bool found = false;  
        findAndDelete(root, tde, found);  
        if (found) {  
            cout << "Da xoa muc: " << tde << endl;  
        } else {  
            cout << "Khong tim thay muc: " << tde << endl;  
        }  
    }  
};  
int main() {  
    Book myBook;  

    // Thêm các chương vào cuốn sách  
    myBook.addChapter("Chap 1: Gioi thieu", 15);  
    myBook.addChapter("Chap 2: Noi dung chinh", 45);  
    myBook.addChapter("Chap 3: Ket Luan", 20);  
    myBook.addChapter("Chap 4: Tai lieu tham khao", 30);  

    // Xác định số chương của cuốn sách  
    cout << "So chuong cua sach: " << myBook.countChapters() << endl;  

    // Tìm chương dài nhất của cuốn sách  
    cout << "Do dai chuong dai nhat: " << myBook.findLongestChapter() << " ky tu" << endl;  

    // Xoá một mục trong sách  
    myBook.deleteChapter("Chap 2: Noi dung chinh");  
    
    // Kiểm tra lại số chương sau khi xoá  
    cout << "So chuong con lai sau khi xoa: " << myBook.countChapters() << endl;  

    return 0;  
}
