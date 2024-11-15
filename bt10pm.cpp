#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

#define MAX_CAPACITY 10 // 

// C?u trúc d? luu tr? thông tin v? m?t thanh g?  
typedef struct {  
    char type[20];  // lo?i g?  
    float size;     // kích thu?c  
    int age;        // tu?i g?  
} Wood;  

// C?u trúc ngan x?p (stack) d? qu?n lý các thanh g?  
typedef struct {  
    Wood woods[MAX_CAPACITY]; // M?ng ch?a các thanh g?  
    int top;                  // Ch? s? c?a ph?n t? trên cùng  
} Stack;  

// Hàm kh?i t?o ngan x?p  
void initStack(Stack* stack) {  
    stack->top = -1; // Ngan x?p r?ng  
}  

// Hàm thêm thanh g? vào ngan x?p  
int push(Stack* stack, Wood wood) {  
    if (stack->top >= MAX_CAPACITY - 1) {  
        printf("Kho dã d?y, không th? thêm g?.\n");  
        return 0; // Không thành công  
    }  
    stack->woods[++stack->top] = wood; // Thêm thanh g? vào ngan x?p  
    return 1; // Thành công  
}  

// Hàm l?y thanh g? ra kh?i ngan x?p  
Wood pop(Stack* stack) {  
    Wood emptyWood = {"", 0, 0}; // Thanh g? r?ng  
    if (stack->top < 0) {  
        printf("Ngan x?p r?ng, không th? l?y g?.\n");  
        return emptyWood; // Tr? v? thanh g? r?ng  
    }  
    return stack->woods[stack->top--]; // Tr? v? thanh g? trên cùng và gi?m ch? s?  
}  

// Hàm d? d?m s? lu?ng thanh g? có cùng tu?i g?  
int countWoodsWithSameAge(Stack* stack, int age) {  
    int count = 0;  
    for (int i = 0; i <= stack->top; i++) {  
        if (stack->woods[i].age == age) {  
            count++;  
        }  
    }  
    return count; // Tr? v? s? lu?ng thanh g? có cùng tu?i  
}  

// Hàm hi?n th? t?t c? các thanh g? trong kho  
void display(Stack* stack) {  
    if (stack->top < 0) {  
        printf("Kho g? r?ng.\n");  
        return;  
    }  
    printf("Danh sách các thanh g? trong kho:\n");  
    for (int i = 0; i <= stack->top; i++) {  
        printf("Lo?i: %s, Kích thu?c: %.2f, Tu?i: %d nam\n", stack->woods[i].type, stack->woods[i].size, stack->woods[i].age);  
    }  
}  

int main() {  
    Stack woodStacks[3]; // T?o 3 ngan x?p cho các lo?i g?  
    const char* woodTypes[3] = {"S?i", "Thông", "B?ch Ðàn"};  

    // Kh?i t?o các ngan x?p  
    for (int i = 0; i < 3; i++) {  
        initStack(&woodStacks[i]);  
    }  

    // T?o thông tin cho các thanh g? m?u  
    Wood sampleWoods[3][MAX_CAPACITY] = {  
        {{"S?i", 5.0, 10}, {"S?i", 6.5, 10}, {"S?i", 4.2, 8}, {"S?i", 5.5, 15}, {"S?i", 6.0, 10},  
         {"S?i", 4.7, 12}, {"S?i", 5.9, 9}, {"S?i", 7.2, 14}, {"S?i", 5.3, 10}, {"S?i", 6.1, 13}},  
        {{"Thông", 3.5, 7}, {"Thông", 4.0, 9}, {"Thông", 4.8, 7}, {"Thông", 5.0, 8}, {"Thông", 3.8, 6},  
         {"Thông", 4.1, 7}, {"Thông", 5.5, 10}, {"Thông", 4.6, 9}, {"Thông", 3.7, 6}, {"Thông", 4.9, 8}},  
        {{"B?ch Ðàn", 2.5, 5}, {"B?ch Ðàn", 3.0, 4}, {"B?ch Ðàn", 2.8, 6}, {"B?ch Ðàn", 3.3, 5}, {"B?ch Ðàn", 2.7, 5},  
         {"B?ch Ðàn", 3.1, 6}, {"B?ch Ðàn", 2.9, 5}, {"B?ch Ðàn", 3.2, 7}, {"B?ch Ðàn", 2.6, 4}, {"B?ch Ðàn", 3.4, 5}}  
    };  

    // Thêm thông tin m?u vào kho  
    for (int i = 0; i < 3; i++) {  
        for (int j = 0; j < MAX_CAPACITY; j++) {  
            push(&woodStacks[i], sampleWoods[i][j]); // Thêm thanh g? vào ngan x?p  
        }  
    }  

    // Hi?n th? kho g? c?a t?ng lo?i  
    for (int i = 0; i < 3; i++) {  
        printf("\nKho g? %s:\n", woodTypes[i]);  
        display(&woodStacks[i]);  
    }  

    // Ð?m s? lu?ng thanh g? có cùng tu?i g?  
    int age;  
    printf("\nNhap tuoi go muon dem: ");  
    scanf("%d", &age);  
    for (int i = 0; i < 3; i++) {  
        int count = countWoodsWithSameAge(&woodStacks[i], age);  
        printf("So luong thanh g? %s co cung tuoi %d la: %d\n", woodTypes[i], age, count);  
    }  

    // L?y g? ra kh?i kho  
    for (int i = 0; i < 3; i++) {  
        printf("\nLay thanh g? ra kho %s:\n", woodTypes[i]);  
        Wood removedWood = pop(&woodStacks[i]);  
        if (removedWood.size != 0.0) { // Ki?m tra n?u có thanh g? du?c l?y  
            printf("Da lay thanh g?: Loai: %s, Kich thuoc: %.2f, Tuoi: %d nam\n", removedWood.type, removedWood.size, removedWood.age);  
        }  
        printf("Kho g? sau khi l?y g? ra:\n");  
        display(&woodStacks[i]);  
    }  

    return 0;  
}
