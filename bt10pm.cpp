#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

#define MAX_CAPACITY 10 // Sức chứa tối đa của mỗi loại gỗ  

// Cấu trúc để lưu trữ thông tin về một thanh gỗ  
typedef struct {  
    char type[20];  // loại gỗ  
    float size;     // kích thước  
    int age;        // tuổi gỗ  
} Wood;  

// Cấu trúc ngăn xếp (stack) để quản lý các thanh gỗ  
typedef struct {  
    Wood woods[MAX_CAPACITY]; // Mảng chứa các thanh gỗ  
    int top;                  // Chỉ số của phần tử trên cùng  
} Stack;  

// Hàm khởi tạo ngăn xếp  
void initStack(Stack* stack) {  
    stack->top = -1; // Ngăn xếp rỗng  
}  

// Hàm thêm thanh gỗ vào ngăn xếp  
int push(Stack* stack, Wood wood) {  
    if (stack->top >= MAX_CAPACITY - 1) {  
        printf("Kho đã đầy, không thể thêm gỗ.\n");  
        return 0; // Không thành công  
    }  
    stack->woods[++stack->top] = wood; // Thêm thanh gỗ vào ngăn xếp  
    return 1; // Thành công  
}  

// Hàm lấy thanh gỗ ra khỏi ngăn xếp  
Wood pop(Stack* stack) {  
    Wood emptyWood = {"", 0, 0}; // Thanh gỗ rỗng  
    if (stack->top < 0) {  
        printf("Ngăn xếp rỗng, không thể lấy gỗ.\n");  
        return emptyWood; // Trả về thanh gỗ rỗng  
    }  
    return stack->woods[stack->top--]; // Trả về thanh gỗ trên cùng và giảm chỉ số  
}  

// Hàm để đếm số lượng thanh gỗ có cùng tuổi gỗ  
int countWoodsWithSameAge(Stack* stack, int age) {  
    int count = 0;  
    for (int i = 0; i <= stack->top; i++) {  
        if (stack->woods[i].age == age) {  
            count++;  
        }  
    }  
    return count; // Trả về số lượng thanh gỗ có cùng tuổi  
}  

// Hàm hiển thị tất cả các thanh gỗ trong kho  
void display(Stack* stack) {  
    if (stack->top < 0) {  
        printf("Kho gỗ rỗng.\n");  
        return;  
    }  
    printf("Danh sách các thanh gỗ trong kho:\n");  
    for (int i = 0; i <= stack->top; i++) {  
        printf("Loại: %s, Kích thước: %.2f, Tuổi: %d năm\n", stack->woods[i].type, stack->woods[i].size, stack->woods[i].age);  
    }  
}  

int main() {  
    Stack woodStacks[3]; // Tạo 3 ngăn xếp cho các loại gỗ  
    const char* woodTypes[3] = {"Sồi", "Thông", "Bạch Đàn"};  

    // Khởi tạo các ngăn xếp  
    for (int i = 0; i < 3; i++) {  
        initStack(&woodStacks[i]);  
    }  

    // Tạo thông tin cho các thanh gỗ mẫu  
    Wood sampleWoods[3][MAX_CAPACITY] = {  
        {{"Sồi", 5.0, 10}, {"Sồi", 6.5, 10}, {"Sồi", 4.2, 8}, {"Sồi", 5.5, 15}, {"Sồi", 6.0, 10},  
         {"Sồi", 4.7, 12}, {"Sồi", 5.9, 9}, {"Sồi", 7.2, 14}, {"Sồi", 5.3, 10}, {"Sồi", 6.1, 13}},  
        {{"Thông", 3.5, 7}, {"Thông", 4.0, 9}, {"Thông", 4.8, 7}, {"Thông", 5.0, 8}, {"Thông", 3.8, 6},  
         {"Thông", 4.1, 7}, {"Thông", 5.5, 10}, {"Thông", 4.6, 9}, {"Thông", 3.7, 6}, {"Thông", 4.9, 8}},  
        {{"Bạch Đàn", 2.5, 5}, {"Bạch Đàn", 3.0, 4}, {"Bạch Đàn", 2.8, 6}, {"Bạch Đàn", 3.3, 5}, {"Bạch Đàn", 2.7, 5},  
         {"Bạch Đàn", 3.1, 6}, {"Bạch Đàn", 2.9, 5}, {"Bạch Đàn", 3.2, 7}, {"Bạch Đàn", 2.6, 4}, {"Bạch Đàn", 3.4, 5}}  
    };  

    // Thêm thông tin mẫu vào kho  
    for (int i = 0; i < 3; i++) {  
        for (int j = 0; j < MAX_CAPACITY; j++) {  
            push(&woodStacks[i], sampleWoods[i][j]); // Thêm thanh gỗ vào ngăn xếp  
        }  
    }  

    // Hiển thị kho gỗ của từng loại  
    for (int i = 0; i < 3; i++) {  
        printf("\nKho gỗ %s:\n", woodTypes[i]);  
        display(&woodStacks[i]);  
    }  

    // Đếm số lượng thanh gỗ có cùng tuổi gỗ  
    int age;  
    printf("\nNhap tuoi go muon dem: ");  
    scanf("%d", &age);  
    for (int i = 0; i < 3; i++) {  
        int count = countWoodsWithSameAge(&woodStacks[i], age);  
        printf("So luong thanh gỗ %s co cung tuoi %d la: %d\n", woodTypes[i], age, count);  
    }  

    // Lấy gỗ ra khỏi kho  
    for (int i = 0; i < 3; i++) {  
        printf("\nLay thanh gỗ ra kho %s:\n", woodTypes[i]);  
        Wood removedWood = pop(&woodStacks[i]);  
        if (removedWood.size != 0.0) { // Kiểm tra nếu có thanh gỗ được lấy  
            printf("Da lay thanh gỗ: Loai: %s, Kich thuoc: %.2f, Tuoi: %d năm\n", removedWood.type, removedWood.size, removedWood.age);  
        }  
        printf("Kho gỗ sau khi lấy gỗ ra:\n");  
        display(&woodStacks[i]);  
    }  

    return 0;  
}