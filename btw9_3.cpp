#include <iostream>  
#include <cstring>  

using namespace std;  

struct Node {  
    char word[100];   
    Node* next;       

    Node(const char* newWord) {  
        strcpy(word, newWord);
        next = nullptr;     
    }  
};  
 
struct LinkedList {  
    Node* head;   

    LinkedList() {  
        head = nullptr; 
    }  

    void insertWord(const char* newWord) {  
        Node* newNode = new Node(newWord);  
        newNode->next = head; 
        head = newNode;  
    }  

    void mostFrequentWord(char* result) {  
        int maxCount = 0;  
        Node* current = head;  
        Node* check;  

        while (current != nullptr) {  
            int count = 0;  
            check = head;  
            while (check != nullptr) {  
                if (strcmp(current->word, check->word) == 0) {  
                    count++;  
                }  
                check = check->next;  
            }  
            if (count > maxCount) {  
                maxCount = count;  
                strcpy(result, current->word); 
            }  
            current = current->next;  
        }  
    }  

    void removeRedundantWords() {  
        Node* current = head;  
        while (current != nullptr && current->next != nullptr) {  
            if (strcmp(current->word, current->next->word) == 0) {  
                Node* temp = current->next;  
                current->next = current->next->next;
                delete temp; 
            } else {  
                current = current->next;  
            }  
        }  
    }  

    int countWords() {  
        int count = 0;  
        Node* current = head;  
        while (current != nullptr) {  
            count++;  
            current = current->next;  
        }  
        return count;  
    }  

    ~LinkedList() {  
        while (head != nullptr) {  
            Node* temp = head;  
            head = head->next;  
            delete temp;  
        }  
    }  
};  

int main() {  
    LinkedList wordList;  

    char sentence[1000];  
    cout << "Nhap mot cau: ";  
    cin.getline(sentence, 1000); 

    char* token = strtok(sentence, " "); 
    while (token != nullptr) {  
        wordList.insertWord(token);  
        token = strtok(nullptr, " ");  
    }  

    char frequentWord[100];  
    wordList.mostFrequentWord(frequentWord);  
    cout << "Tu xuat hien nhieu nhat: " << frequentWord << endl;  

    wordList.removeRedundantWords();  
    cout << "Da xoa cac tu lay." << endl;  

    int totalWords = wordList.countWords();  
    cout << "Tong so tu trong cau: " << totalWords << endl;  

    return 0;  
}
