#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;                
    struct Node *left;        
    struct Node *right;       
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildExpressionTree(char postfix[]) {
    Node* stack[100];   
    int top = -1;   
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (ch >= 'A' && ch <= 'Z') { 
            stack[++top] = createNode(ch);
        } else {
            Node* newNode = createNode(ch);
            newNode->right = stack[top--]; 
            newNode->left = stack[top--];  
            stack[++top] = newNode;        
        }
    }

    return stack[top]; 
}

void preorder(Node* root) {
    if (root != NULL) {
        printf("%c ", root->data); 
        preorder(root->left);     
        preorder(root->right);    
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);     
        printf("%c ", root->data); 
        inorder(root->right);     
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);    
        postorder(root->right);   
        printf("%c ", root->data);
    }
}

int main() {
    char postfix[] = "AB+C*"; 
    
    Node* root = buildExpressionTree(postfix);

    printf("Duy?t trý?c (Preorder): ");
    preorder(root);
    printf("\n");

    printf("Duy?t gi?a (Inorder): ");
    inorder(root);
    printf("\n");

    printf("Duy?t sau (Postorder): ");
    postorder(root);
    printf("\n");

    return 0;
}
