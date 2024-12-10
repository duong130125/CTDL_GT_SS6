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

// Kiểm tra ngăn xếp có rỗng không
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Thêm phần tử vào ngăn xếp
void push(Stack *stack, int value)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Ngăn xếp đầy!\n");
        return;
    }
    stack->data[++stack->top] = value;
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

    if (n == 0)
    {
        printf("Ngăn xếp rỗng\n");
        return 0;
    }

    printf("Nhập các phần tử:\n");
    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        push(&stack, value);
    }

    if (isEmpty(&stack))
    {
        printf("Ngăn xếp rỗng\n");
    }
    else
    {
        printf("Ngăn xếp không rỗng\n");
    }

    return 0;
}
