#ifndef LIST_H
#define LIST_H
#include <functional>
#include <iostream>
/**
 * 双向链表实现
 *
 */
namespace mystl {
    template <typename T>
 struct list_node {
        // 指向前一个节点
        list_node *prev;
        // 指向后一个节点
        list_node *next;
        // 保存数据
        T data;

        // 构造函数
        list_node(list_node *p, list_node *n, T d) : prev(p), next(n), data(d) {}
    };

    template <typename T>
    class list {
        // 永远指向列表的头节点
        list_node<T> *head;
        // 永远指向列表的尾节点
        list_node<T> *tail;
        // 保存列表的大小
        size_t _size {0};
    public:
        // 空构造函数
        list() : head(nullptr), tail(nullptr), _size(0) {}

        // 析构函数
        ~list() {
            list_node<T> *tmp = head;
            while (head != nullptr) {
                std::cout << "[DEBUG] list的析构函数被执行，当前节点保存数据为[" << tmp->data << "]。" << std::endl;
                tmp = head->next;
                delete head;
                head = tmp;
            }
        }

        void push_back(const T& data) {
            if (head == nullptr) {
                head = tail = new list_node<T>(nullptr, nullptr, data);
            } else {
                auto *new_node = new list_node<T>(tail, nullptr, data);
                tail->next = new_node;
                tail = new_node;
            }
            _size++;
        }

        // TODO 头插元素
        void push_front(const T& data) {

        }

        // TODO 尾删除元素
        T pop_back() {

        }

        // TODO 头删除元素
        T pop_front() {

        }

        // TODO 判断列表为空
        bool is_empty() {

        }

        // TODO 获取列表大小
        size_t size() {
            return _size;
        }

        // TODO 清空列表
        void clear() {

        }

        // TODO 从头遍历
        void ite_from_head(std::function<void(const T&)> current) {
            list_node<T> *tmp = head;
            while (tmp != nullptr) {
                current(tmp->data);
                tmp = tmp->next;
            }
        }

        // TODO 从尾遍历

    };
}

#endif //LIST_H
