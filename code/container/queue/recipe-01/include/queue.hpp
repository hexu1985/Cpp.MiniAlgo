/**
 * @file queue.hpp
 * @brief 数组实现的队列
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-02-28
 *
 * @see 算法I~IV(C++实现): 章节4.6
 *
 */
#ifndef MINI_ALGO_QUEUE_INC
#define MINI_ALGO_QUEUE_INC

namespace mini_algo {

/**
 * @brief 数组实现的队列
 *
 * @tparam Item 队列元素类型
 * @tparam maxN 队列最多容纳元素个数
 */
template <class Item, size_t maxN>
class Queue {
// 索引:   [0][1][2]...[7][8][9]...[N-1][N]
// 数组:   [x][x][x]...[x][x][x]...[xxx]
//             ^head          ^tail
private:
    Item A[maxN+1];  // 数组空间, A[0], ..., A[N-1]
    int N;           // 数组容量
    int head;        // 队首元素的下标, head的取值范围[1, N]
    int tail;        // 队尾元素的下一个位置的下标, tail的取值范围[0, N-1]

private:
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

public:
    /**
     * @brief 构造一个可以最多容纳maxN个元素的队列
     *
     * @param maxN 队列最多能容纳元素个数
     */
    Queue()
    { 
        N = maxN+1; 
        head = N; 
        tail = 0; 
    }

    /**
     * @brief 空析构函数
     */
    ~Queue() {}

    /**
     * @brief 获取队列中元素个数
     *
     * @return 当前队列大小
     */
    int Size() const
    {
        return (tail-head+N) % N;
    }

    /**
     * @brief 获取队列最大能容纳元素个数
     *
     * @return 队列容量
     */
    int Capacity() const
    {
        return N-1;
    }

    /**
     * @brief 判断队列是否为空
     *
     * @return 队列为空返回true, 否则返回false
     */
    bool IsEmpty() const
    { 
        return (head%N) == tail;
    }

    /**
     * @brief 判断队列是否已满
     *
     * @return 如果队列已满返回true, 否则返回false
     */
    bool IsFull() const
    {
        return (tail+1) == head;
    }

    /**
     * @brief 往队列尾放入一个元素
     *
     * @param item 被放入的元素值
     */
    void Push(const Item& item)
    { 
        A[tail++] = item; 
        tail = tail % N; 
    }

    /**
     * @brief 获取并弹出队列首的元素
     *
     * @return 队列首的元素值
     */
    Item Pop()
    { 
        head = head % N; 
        return A[head++]; 
    }

    /**
     * @brief 获取并弹出队列首的元素
     *
     * @param item 队列首的元素值存入item里
     */
    void Pop(Item& item)
    {
        head = head % N; 
        item = A[head++];
    }

    /**
     * @brief 获取队首元素的引用
     *
     * @return 队首元素值的引用
     */
    Item& Front()
    {
        return A[head%N];           // head == N ? A[0] : A[head]
    }

    /**
     * @brief 获取队首元素的常引用
     *
     * @return 队首元素值的常引用
     */
    const Item& Front() const
    {
        return A[head%N];           // head == N ? A[0] : A[head]
    }

    /**
     * @brief 获取队尾元素的引用
     *
     * @return 队尾元素的引用
     */
    Item& Back()
    {
        return A[(tail-1+N)%N];     // tail == 0 ? A[N-1] : A[tail-1];
    }

    /**
     * @brief 获取队尾元素的常引用
     *
     * @return 队尾元素的常引用
     */
    const Item& Back() const
    {
        return A[(tail-1+N)%N];     // tail == 0 ? A[N-1] : A[tail-1];
    }
};

}   // namespace mini_algo

#endif
