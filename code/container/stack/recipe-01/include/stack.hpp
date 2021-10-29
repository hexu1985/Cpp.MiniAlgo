/**
 * @file stack.hpp
 * @brief 数组实现的栈
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-03-06
 *
 * @see 算法I~IV(C++实现): 章节4.4
 *
 */
#ifndef MINI_ALGO_STACK_INC
#define MINI_ALGO_STACK_INC

namespace mini_algo {

/**
 * @brief 数组实现的栈
 *
 * @tparam Item 栈元素类型
 */
template <typename Item, size_t maxN>
class Stack {
// 索引:   [0][1][2]...[7][8][9]...[N-1][N]
// 数组:   [x][x][x]...[x][x][x]...[xxx]
//                         ^top
private:
    Item A[maxN];   // 数组空间, A[0], ..., A[N-1]
    int top;        // 栈顶下标, 指向栈顶元素的下一个位置
    int N;          // 栈大小

private:
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

public:
    /**
     * @brief 构造一个可以最多容纳maxN个元素的栈
     *
     * @param maxN 栈最多能容纳元素个数
     */
    Stack()
    {
        N = maxN;
        top = 0;
    }

    /**
     * @brief 空析构函数
     */
    ~Stack()
    {
    }

    /**
     * @brief 获取当前栈中元素个数
     *
     * @return 当前栈大小
     */
    size_t Size() const
    {
        return top;
    }

    /**
     * @brief 获取栈最大能容纳元素个数
     *
     * @return 栈容量
     */
    size_t Capacity() const
    {
        return N;
    }

    /**
     * @brief 判断栈是否为空
     *
     * @return 栈为空返回true, 否则返回false
     */
    bool IsEmpty() const
    {
        return top == 0;
    }

    /**
     * @brief 判断栈是否已满
     *
     * @return 如果栈已满返回true, 否则返回false
     */
    bool IsFull() const
    {
        return top == N;
    }

    /**
     * @brief 往栈顶放入一个元素
     *
     * @param item 被放入的元素值
     */
    void Push(const Item& item)
    {
        A[top++] = item;
    }

    /**
     * @brief 获取并弹出栈顶的元素
     *
     * @return 栈顶首的元素值
     */
    Item Pop()
    {
        return A[--top];
    }

    /**
     * @brief 获取栈顶元素的引用
     *
     * @return 栈顶元素值的引用
     */
    Item& Top()
    {
        return A[top-1];
    }

    /**
     * @brief 获取栈顶元素的常引用
     *
     * @return 栈顶元素值的常引用
     */
    const Item& Top() const
    {
        return A[top-1];
    }
};

}   // namespace mini_algo

#endif
