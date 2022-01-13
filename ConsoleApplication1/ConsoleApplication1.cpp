#include <iostream>
template<typename T>
struct Node {
    T value;
    Node* next;

    Node() {
    }

    Node(Node* node) {
        next = NULL;
        value = node->value;
    }
};

template <typename T>
class FIFO {
private:
    Node<T>* first;
    unsigned long size;
public:
    explicit FIFO() {
        this->first = NULL;
        this->size = 0;
    }

    void add(T value) {
        if (this->first == NULL) {
            this->first = new Node<T>();
            this->first->value = value;
            this->first->next = NULL;
        }
        else {
            Node<T>* tmp = this->first;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = new Node<T>();
            tmp->next->value = value;
            tmp->next->next = NULL;
        }
        this->size++;
    }

    Node<T>* remove() {
        Node<T>* tmp = NULL;
        tmp = this->first;
        this->first = this->first->next;
        Node<T>* forReturn = new Node<T>(tmp);
        delete tmp;
        this->size--;
        return forReturn;
    }

    void show() {
        Node<T>* tmp = this->first;
        while (tmp != NULL) {
            std::cout << tmp << " " << tmp->value << " " << tmp->next << "\n";
            tmp = tmp->next;
        }
    }
};
int main()
{
    FIFO<int> num;
    for (int i = 1; i < 6; i++) {
        num.add(i);
    }
    num.show();
    Node<int>* first = num.remove();
    std::cout << "\n" <<"Removed " << first << " " << first->value << "\n";
    num.show();
    num.add(0);
    std::cout << "\n";
    num.show();
    first = num.remove();
    std::cout << "\n" << "Removed " << first << " " << first->value << "\n";
    num.show();
}