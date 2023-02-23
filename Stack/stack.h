#pragma once
#include <iostream>

class Stack
{
private:
    //int stack_size;
    int stack_count;
    int* p_stack;
    const int STACK_SIZE = 10;

public:
    // 생성자
    Stack() :stack_count(0) { p_stack = new int[STACK_SIZE]; };
    // 데이터 추가
    void Push(int data);
    // 최상단 값 삭제
    void Pop();
    // 최상단 값 출력
    void Top();
    // 모든 값 보기
    void Show_Data();


    // 마지막 값 반환
    int peek();
    // 크기 반환
    int Size() {return stack_count;}
    // 생성 가능 여부 확인
    bool isEmpty();

    // 소멸자
    ~Stack() { delete[] p_stack; }

};
