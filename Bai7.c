#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 1000

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

// Làm sạch chuỗi: loại bỏ khoảng trắng và chuyển sang chữ thường
void cleanString(const char *input, char *cleaned)
{
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isalnum(input[i]))
        { // Giữ lại chữ cái và số
            cleaned[j++] = tolower(input[i]);
        }
    }
    cleaned[j] = '\0'; // Kết thúc chuỗi sạch
}

// Kiểm tra tính đối xứng (palindrome) bằng ngăn xếp
int isPalindrome(const char *str)
{
    Stack stack;
    initStack(&stack);
    int len = strlen(str);

    // Đẩy nửa đầu chuỗi vào ngăn xếp
    for (int i = 0; i < len / 2; i++)
    {
        push(&stack, str[i]);
    }

    // So sánh nửa sau của chuỗi với các phần tử trong ngăn xếp
    for (int i = (len + 1) / 2; i < len; i++)
    {
        if (str[i] != pop(&stack))
        {
            return 0; // Không đối xứng
        }
    }
    return 1; // Đối xứng
}

int main()
{
    char input[MAX_SIZE], cleaned[MAX_SIZE];

    printf("Nhập câu: ");
    fgets(input, MAX_SIZE, stdin);

    // Loại bỏ ký tự xuống dòng nếu có
    input[strcspn(input, "\n")] = '\0';

    // Làm sạch chuỗi
    cleanString(input, cleaned);

    // Kiểm tra tính đối xứng
    if (isPalindrome(cleaned))
    {
        printf("Câu này là đối xứng\n");
    }
    else
    {
        printf("Câu này không phải là đối xứng\n");
    }

    return 0;
}
