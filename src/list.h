#ifndef LIST_H
#define LIST_H
#include <functional>
#include <iostream>
/**
 * 双向链表实现
 *
 */
#define DEBUG_MODE true
namespace mystl {
    template<typename T>
    struct list_node {
        // 指向前一个节点
        list_node *prev;
        // 指向后一个节点
        list_node *next;
        // 保存数据
        T data;

        // 构造函数
        list_node(list_node *p, list_node *n, T d) : prev(p), next(n), data(d) {
        }

        // 析构函数
        ~list_node() = default;
    };

    template<typename T>
    class list {
        // 永远指向列表的头节点
        list_node<T> *head;
        // 永远指向列表的尾节点
        list_node<T> *tail;
        // 保存列表的大小
        size_t _size{0};

    public:
        // 空构造函数
        list() : head(nullptr), tail(nullptr), _size(0) {
        }

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

        void debug_info() {
            if (DEBUG_MODE) {
                std::cout << "[DEBUG] size = " << _size << "\t";
                std::cout << "[DEBUG] head->data = " << head->data << "\t";
                std::cout << "[DEBUG] tail->data = " << tail->data << "\t";
                std::cout << "[DEBUG] 列表当前结构如下 " << std::endl;
                ite_from_head([](int data) {
                    std::cout << data << " -> ";
                });
                std::cout << std::endl;
            }
        }

        // 尾插元素
        void push_back(const T &data) {
            if (head == nullptr) {
                head = tail = new list_node<T>(nullptr, nullptr, data);
            } else {
                auto *new_node = new list_node<T>(tail, nullptr, data);
                tail->next = new_node;
                tail = new_node;
            }
            _size++;
            debug_info();
        }

        // 头插元素
        void push_front(const T &data) {
            if (head == nullptr) {
                head = tail = new list_node<T>(nullptr, nullptr, data);
            } else {
                auto *new_node = new list_node<T>(nullptr, head, data);
                head->prev = new_node;
                head = new_node;
            }
            _size++;
            debug_info();
        }

        T pop_back() {
            if (tail == nullptr) {
                throw std::underflow_error("pop_back called on empty list");
            }
            T popped = tail->data;
            auto prev = tail->prev;
            delete tail;
            tail = prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
            _size--;

            if (_size != 0) {
                debug_info();
            }
            return popped;
        }

        // 头删除元素
        T pop_front() {
            if (head == nullptr) {
                throw std::underflow_error("pop_front called on empty list");
            }
            T popped = head->data;
            auto next = head->next;
            delete head;
            head = next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            _size--;

            if (_size != 0) {
                debug_info();
            }
            return popped;
        }

        // 判断列表为空
        bool is_empty() {
            return _size == 0 || head == nullptr || tail == nullptr;
        }

        // 获取列表大小
        size_t size() {
            return _size;
        }

        // 清空列表
        void clear() {
            while (size() > 0) {
                pop_front();
            }
        }

        // 从头遍历
        void ite_from_head(std::function<void(const T &)> current) {
            list_node<T> *tmp = head;
            while (tmp != nullptr) {
                current(tmp->data);
                tmp = tmp->next;
            }
        }

        // 迭代器相关实现
        struct iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
            explicit iterator(list_node<T>* ite_beg): current(ite_beg) {}

            iterator& operator++() {
                current = current->next;
                return *this;
            }

            iterator operator++(int step) {
                // do nothing
            }

            iterator& operator--() {
                current = current->prev;
                return *this;
            }

            iterator& operator--(int step) {
                // do nothing
            }

            bool operator==(const iterator &other) {
                return current == other.current;
            }

            bool operator!=(const iterator &other) {
                return current != other.current;
            }

            T& operator*() {
                return current->data;
            }

        private:
            list_node<T> *current{nullptr};
        };

        iterator begin() {
            return iterator(head);
        }

        iterator end() {
            return iterator(nullptr);
        }

        iterator rbegin() {
            return iterator(tail);
        }

        iterator rend() {
            return iterator(nullptr);
        }
    };
}

#endif //LIST_H
