#include <iostream>

template <typename T>
struct node {
    T value;
    node* next;
    node* prev;

    explicit node(T const &value, node* next = nullptr, node* prev = nullptr)
            : value(value), next(next), prev(prev) {
    }

    node() = default;
};

template <typename T>
class LinkedList {
private:
    node<T>* head;
    node<T>* tail;

    size_t listSize = 0;

public:
    LinkedList();

    virtual ~LinkedList();

    LinkedList<T> &operator=(const LinkedList<T> &) = delete;

    LinkedList(LinkedList const &) = delete;

    void push_back(const T &value);

    void pop_back();

    void show();

    node<T> &operator[](size_t idx);

    void sort();

    void swap(node<T> &node1, node<T> &node2);
};

template <typename T>
LinkedList<T>::LinkedList()
        : head(nullptr), tail(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    node<T>* tmp;
    while (head) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    listSize = 0;
}

template <typename T>
void LinkedList<T>::push_back(const T &value) {
    auto* newNode = new node<T>(value, nullptr, tail);
    if (head == nullptr) {
        head = newNode;
    }
    if (tail != nullptr) {
        tail->next = newNode;
    }
    listSize++;
    tail = newNode;
}

template <typename T>
void LinkedList<T>::pop_back() {
    if (tail == nullptr) {
        return;
    }
    node<T>* tmp = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    }
    listSize--;
    delete tmp;
}

template <typename T>
node<T> &LinkedList<T>::operator[](size_t idx) {
    int cnt = 0;
    node<T>* curr = head;
    while (curr) {
        if (cnt == idx) {
            return curr;
        }
        curr = curr->next;
        ++cnt;
    }
    return nullptr;
}

template <typename T>
void LinkedList<T>::show() {
    node<T>* tmp;
    tmp = head;
    while (tmp) {
        std::cout << tmp->value << std::endl;
        tmp = tmp->next;
    }
}

template <typename T>
void LinkedList<T>::swap(node<T> &node1, node<T> &node2) {
    std::swap(node1.value, node2.value);
    std::swap(node1.next, node2.next);
    std::swap(node1.prev, node2.prev);
}

template <typename T>
void LinkedList<T>::sort() {
    node<T>* left = head;
    node<T>* right = head->next;

    auto* tmp = new node<T>;
    while (left->next) {
        while (right) {
            if ((left->value) > (right->value)) {
                tmp->value = left->value;
                left->value = right->value;
                right->value = tmp->value;
            }
            right = right->next;
        }
        left = left->next;
        right = left->next;
    }
}

void test() {
    LinkedList<int> list;
    list.push_back(10);
    list.push_back(7);
    list.push_back(8);
    list.show();
    list.sort();
    list.show();
    list.pop_back();
    list.pop_back();
    list.pop_back();
}

int main() {
    test();
    return 0;
}
