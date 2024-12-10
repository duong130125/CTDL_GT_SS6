#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct
{
    char data[MAX_SIZE];
    int top;
} Stack;

// Khởi tạo ngăn xếp
void initStack(Stack *stack)
{
    stack->top = -1;
}

// Kiểm tra ngăn xếp có đầy không
int isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

// Kiểm tra ngăn xếp có rỗng không
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Thêm phần tử vào ngăn xếp
void push(Stack *stack, char value)
{
    if (isFull(stack))
    {
        printf("Ngăn xếp đầy!\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Lấy phần tử trên cùng khỏi ngăn xếp
char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Ngăn xếp rỗng!\n");
        return '\0'; // Trả về ký tự rỗng nếu ngăn xếp rỗng
    }
    return stack->data[stack->top--];
}

int main()
{
    Stack stack;
    initStack(&stack);

    char input[MAX_SIZE];
    printf("Nhập một chuỗi (không quá 100 ký tự): ");
    fgets(input, MAX_SIZE, stdin);

    // Loại bỏ ký tự xuống dòng nếu có
    input[strcspn(input, "\n")] = '\0';

    // Thêm từng ký tự của chuỗi vào ngăn xếp
    for (int i = 0; i < strlen(input); i++)
    {
        push(&stack, input[i]);
    }

    // Lấy các ký tự ra từ ngăn xếp để tạo chuỗi đảo ngược
    printf("Chuỗi đã đảo ngược: ");
    while (!isEmpty(&stack))
    {
        printf("%c", pop(&stack));
    }
    printf("\n");

    return 0;
}