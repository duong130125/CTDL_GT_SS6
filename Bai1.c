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

// Lấy phần tử ra khỏi ngăn xếp (không dùng trong bài tập này)
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Ngăn xếp rỗng!\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// In các phần tử trong ngăn xếp từ trên xuống dưới
void printStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Ngăn xếp rỗng!\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d\n", stack->data[i]);
    }
}

int main()
{
    Stack stack;
    initStack(&stack);

    int n;
    printf("Nhập số lượng phần tử cần thêm vào ngăn xếp (tối đa 100): ");
    scanf("%d", &n);

    if (n > MAX_SIZE)
    {
        printf("Số lượng phần tử vượt quá kích thước ngăn xếp!\n");
        return 1;
    }

    printf("Nhập các phần tử:\n");
    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        push(&stack, value);
    }

    printf("Các phần tử trong ngăn xếp từ trên xuống dưới:\n");
    printStack(&stack);

    return 0;
}
