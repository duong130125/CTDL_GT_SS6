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

// Kiểm tra ngăn xếp có rỗng không
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Kiểm tra ngăn xếp có đầy không
int isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
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
        return '\0';
    }
    return stack->data[stack->top--];
}

// Lấy phần tử trên cùng của ngăn xếp mà không xóa
char peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        return '\0';
    }
    return stack->data[stack->top];
}

// Kiểm tra dấu ngoặc có khớp không
int isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Hàm kiểm tra tính hợp lệ của biểu thức
int isValidExpression(const char *expression)
{
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < strlen(expression); i++)
    {
        char ch = expression[i];

        // Nếu là dấu ngoặc mở, đẩy vào ngăn xếp
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(&stack, ch);
        }
        // Nếu là dấu ngoặc đóng, kiểm tra với dấu ngoặc mở trên cùng của ngăn xếp
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (isEmpty(&stack) || !isMatchingPair(peek(&stack), ch))
            {
                return 0; // Không hợp lệ
            }
            pop(&stack); // Dấu ngoặc khớp, bỏ dấu ngoặc mở khỏi ngăn xếp
        }
    }

    // Nếu ngăn xếp rỗng, tất cả dấu ngoặc đã khớp
    return isEmpty(&stack);
}

int main()
{
    char expression[MAX_SIZE];

    printf("Nhập biểu thức: ");
    fgets(expression, MAX_SIZE, stdin);

    // Loại bỏ ký tự xuống dòng nếu có
    expression[strcspn(expression, "\n")] = '\0';

    if (isValidExpression(expression))
    {
        printf("Biểu thức hợp lệ\n");
    }
    else
    {
        printf("Biểu thức không hợp lệ\n");
    }

    return 0;
}
