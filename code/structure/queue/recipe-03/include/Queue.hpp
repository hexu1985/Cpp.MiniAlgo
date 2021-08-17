/**
 * @file Queue.hpp
 * @brief 链表实现的队列
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2021-04-23
 */
#ifndef MINI_ALGO_QUEUE_INC
#define MINI_ALGO_QUEUE_INC

namespace mini_algo {

/**
 * @brief 链表实现的队列
 *
 * @tparam Item 队列元素类型
 */
template <class Item>
class Queue {
private:
    /**
     * 双向循环链表节点
     *            ___  next      
     *           |   |------>
     *     <-----|___|       
     *       prev
     */
    struct Node {
        Node(): prev(nullptr), next(nullptr), item() {} 
        Node(const Item& item_): prev(nullptr), next(nullptr), item(item_) {}

        Node *prev;
        Node *next;
        Item item;
    };

private:
    Node *nil;

private:
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

public:
    /**
     * @brief 构造一个空的队列
     */
    Queue()
    { 
        /**
         * 初始化NIL节点
         *         ____
         *        |    |
         *        V    |
         *   .--[nil]--'
         *   |    A    
         *   |____|     
         */
        nil = new Node();
        nil->prev = nil->next = nil;
    }

    /**
     * @brief 释放动态内存
     */
    ~Queue()
    {
        Node *node = nil->next;
        while (node != nil) {
            Node *next = node->next;
            delete node;
            node = next;
        }
        delete nil;
    }

    /**
     * @brief 获取队列中元素个数
     *
     * @return 当前队列大小
     */
    int size() const
    {
        Node *node = nil->next;
        int n = 0;
        while (node != nil) {
            node = node->next;
            ++n;
        }
        return n;
    }

    /**
     * @brief 判断队列是否为空
     *
     * @return 队列为空返回true, 否则返回false
     */
    bool isEmpty() const
    { 
        return nil->next == nil;
    }

    /**
     * @brief 往队列尾放入一个元素
     *
     * @param item 被放入的元素值
     */
    void push(const Item& item)
    {
        /**
         * 在链表的nil节点前插入node节点
         *            ___                ___
         *           |   |------------->|   |------>
         *    <------|___|<-------------|___|
         *                                ^-nil
         *                  ___        
         *                 |   |------>
         *            <----|___|       
         *                   ^-node
         * =========================================
         *            ___                ___
         *           |   |------------->|   |------>
         *    <------|___|<-------------|___|
         *             A                 A ^-nil
         *             |(1) ___          |(2)
         *             |   |   |---------'
         *             '---|___|       
         *                   ^-node
         * =========================================
         *            ___                ___
         *           |   |--.     .---->|   |------>
         *    <------|___|  |(3)  |  .--|___|
         *             A    |  (4)|  |    ^-nil
         *             |    V__   |  |
         *             |   |   |--'  |
         *             '---|___|<----'
         *                   ^-node
         */
        Node *node = new Node(item);
        node->prev = nil->prev;
        node->next = nil;
        nil->prev->next = node;
        nil->prev = node;
    }

    /**
     * @brief 获取并弹出队列首的元素
     *
     * @return 队列首的元素值
     */
    Item pop()
    {
        if (isEmpty()) {
            return nil->item;
        }

        /**
         * 从链表上删除nil->next节点
         *            ___           ___           ___ 
         *           |   |-------->|   |-------->|   |------>
         *    <------|___|<--------|___|<--------|___|
         *             ^-nil         ^-node
         * ==================================================
         *                    .--------------------.
         *                    |(1)                 |
         *            ___     |     ___           _V_ 
         *           |   |----'    |   |-------->|   |------>
         *    <------|___|<--------|___|    .----|___|
         *             A^-nil        ^-node |   
         *             |                    |(2)
         *             '--------------------'
         */
        Node *node = nil->next;
        Item item = node->item;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        return item;
    }

    /**
     * @brief 获取并弹出队列首的元素
     *
     * @param item 队列首的元素值存入item里
     */
    void pop(Item& item)
    {
        item = pop();
    }

    /**
     * @brief 获取队首元素的引用
     *
     * @return 队首元素值的引用
     */
    Item& front()
    {
        return nil->next->item;
    }

    /**
     * @brief 获取队首元素的常引用
     *
     * @return 队首元素值的常引用
     */
    const Item& front() const
    {
        return nil->next->item;
    }

    /**
     * @brief 获取队尾元素的引用
     *
     * @return 队尾元素的引用
     */
    Item& back()
    {
        return nil->prev->item;
    }

    /**
     * @brief 获取队尾元素的常引用
     *
     * @return 队尾元素的常引用
     */
    const Item& back() const
    {
        return nil->prev->item;
    }
};

}   // namespace mini_algo

#endif
