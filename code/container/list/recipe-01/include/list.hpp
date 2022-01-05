
/**
 * @brief 链表：头指针，尾节点为空
 *
 * @tparam Item
 */
template <typename Item>
class List {
public:
    struct Node {
        Node* next = NULL;
        Item item;
    };

    using Link = Node*;

private:
    Node* head = NULL;

public:
    List(): head(NULL) {}

    static Link NewNode() { return new Node(); }
    static Link NewNode(const Item& item)
    {
        Link node = NewNode();
        node->item = item;
    }

    /**
     * @brief 删除节点
     *
     * @param node 被释放的节点
     */
    static void DeleteNode(Link node) { delete node; }

    /**
     * @brief 在x节点后插入t节点
     *
     * @param x 节点x
     * @param t 节点t
     */
    static void InsertAfter(Link x, Link t)
    {
        assert(x != NULL);
        t->next = x->next;
        x->next = t;
    }

    /**
     * @brief 删除x后的节点
     *
     * @param x 节点x
     *
     * @return 被删除的节点
     */
    static Link RemoveAfter(Link x)
    {
        assert(x != NULL);
        Link t = x->next;
        if (t) x->next = t->next;
        return t;
    }

    /**
     * @brief 测试链表是否为空
     *
     * @return 如果为空，返回true，否则返回false
     */
    bool IsEmpty()
    {
        return head == NULL;
    }

    /**
     * @brief 在链表头插入t节点
     *
     * @param t 节点t
     */
    void InsertHead(Link t)
    {
        if (head == NULL) {
            head = t;
            t->next = NULL;
        } else {
            t->next = head->next;
            head = t;
        }
    }

    /**
     * @brief 循环遍历列表
     *
     * @param fn 函数对象，处理节点元素
     */
    template <typename Function>
    void ForEach(Function fn)
    {
        for (Link t = head; t != NULL; t = t->next) {
            fn(t->item);
        }
    }
};
