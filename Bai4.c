#include <stdio.h>
#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
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
void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Ngăn xếp đầy!\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Lấy phần tử trên cùng của ngăn xếp (peek)
int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Ngăn xếp rỗng!\n");
        return -1;
    }
    return stack->data[stack->top];
}

int main()
{
    Stack stack;
    initStack(&stack);

    int n;
    printf("Nhập số lượng phần tử cần thêm vào ngăn xếp (tối đa 100): ");
    scanf("%d", &n);

    if (n < 0 || n > MAX_SIZE)
    {
        printf("Số lượng phần tử không hợp lệ!\n");
        return 1;
    }

    printf("Nhập các phần tử:\n");
    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        push(&stack, value);
    }

    // Thực hiện thao tác peek
    int topValue = peek(&stack);
    if (topValue != -1)
    {
        printf("Phần tử trên cùng: %d\n", topValue);
    }

    return 0;
}
