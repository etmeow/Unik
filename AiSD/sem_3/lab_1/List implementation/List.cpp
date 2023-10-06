#include <iostream>


template<typename T>
class List {

    // Node ----------------------------------
    template<typename B>
    struct Node {

        Node* pNext;
        B data;

        Node(B data = B(), Node *pNext = nullptr) {

            this->data = data;
            this->pNext = pNext;
        }
    };
    // -----------------------------------------

    Node<T> *head;
    int size;

public:

    List();
    ~List();

    Node<T>* begin() {

        return head;
    }

    void out();
    void out_f(Node<T> *p);
    void out_l(Node<T> *p);


    

    void push_back(T data);
    T& operator[](const int index);
    

};

template<typename T>
void List<T>::out_f(Node<T> *p) {

    if (p == nullptr) return;
    std::cout << p->data << " ";
    out_f(p->pNext);
}

template<typename T>
void List<T>::out_l(Node<T> *p) {

    if (p == nullptr) return;
    out_l(p->pNext);
    std::cout << p->data << " ";
}



template<typename T>
void List<T>::out() {

    Node<T> *curr = head;

    while (curr->pNext != nullptr) {

        std::cout << curr->data << " ";
        curr = curr->pNext;   
    }

    std::cout << curr->data << std::endl;

}

template<typename T>
List<T>::List() {

    size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List() {

    Node<T> curr = *head;
    
}

template<typename T>
void List<T>::push_back(T data) {

    if (head == nullptr) head = new Node<T>(data);

    else {

        Node<T> *curr = head;

        while (curr->pNext != nullptr) 
            curr = curr->pNext;

        curr->pNext = new Node<T>(data);
    }

    size += 1;

}

template<typename T>
T& List<T>::operator[](const int index) {

    int cnt = 0;
    Node<T> *curr = head;

    while(curr != nullptr) {

        if (cnt == index) return curr->data;
        curr = curr->pNext;
        cnt++;
    }

    throw std::runtime_error {"Index out of range"};

    //return head->data;

}

using namespace std;


int main() {    

    List<int> lst;

    lst.push_back(5);
    lst.push_back(3);

    lst.out_l(lst.begin());



    return 0;
}