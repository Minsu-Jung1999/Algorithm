#include <iostream>
#include "Stack_Implementing.h"
using namespace std;

// 값 추가하기
void Stack::Push(int data)
{
    if (isEmpty()) // 데이터 추가가 가능하다면
    {
        *(p_stack + stack_count) = data;
        stack_count++;
    }
    else
    {
        cout << "Stack is full..." << endl << "Use Pop to delete data" << endl;
    }
}

/** 최상단 값을 출력한다. */
void Stack::Top()
{
    if (stack_count == 0) cout << "Stack is empty..." << endl;
    else
        cout<< *(p_stack + stack_count - 1)<<endl;
}

// 모든 값 순서대로 보기
void Stack::Show_Data()
{
    cout << "stack_count = " << stack_count << endl;
    for (int i = 0; i < stack_count; i++)
    {
        cout << "*p_stack " << i << " data = " << p_stack[i] << endl;
    }
}

// 마지막 값 반환
int Stack::peek()
{
    // 사이즈가 다 차지 않았다면
    if (isEmpty()) 
        return *(p_stack + stack_count);
    else
        return 0;
}

// Stack Count 반환
int Stack::Size()
{
    return stack_count;
}

// 설정된 스택 최대 사이즈를 넘는지 stack_counter 로 판단한다.
bool Stack::isEmpty()
{
    if (stack_count >= STACK_SIZE) return false;
    return true;
}

// 사이즈를 하나 줄인다.
void Stack::Pop()
{
    if (stack_count > 0) stack_count--;
}

int main()
{
    Stack stack;
    while (true)
    {
        int choice;
        int data;
        cout << "1. Push data" << endl;
        cout << "2. Pop data" << endl;
        cout << "3. Peek data" << endl;
        cout << "4. Size data" << endl;
        cout << "5. Show all data" << endl;
        cout << "6. EXIT" << endl;
        cin >> choice;
        switch (choice)
        {
            // 추가
        case 1:
            if (!stack.isEmpty())
            {
                cout << "stack is full" << endl;
                break;
            }
            cout << "Data = ";
            cin >> data;
            stack.Push(data);
            break;
            // 삭제
        case 2:
            stack.Pop();
            cout << "Pop stack successfully.." << endl;
            break;
            // 마지막 값 출력
        case 3:
            cout << endl;
            cout << "Last Data = " << stack.peek() << endl;;
            cout << "Peek stack successfully.." << endl;
            break;
            // 크기 출력
        case 4:
            cout << "Stack Size = "<< stack.Size();
            break;
        case 5:
            // 값 모두 출력
            cout << "========================Data========================" << endl;
            stack.Show_Data();
            break;
        case 6:
            // 나가기
            return 0;
            break;
            // 예외 처리
        default:
            cout << "Answer again.." << endl;
            break;
        }
    }

    stack.Show_Data();




    cout << endl;
    cout << endl;
    cout << endl;
}
