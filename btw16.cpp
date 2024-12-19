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
