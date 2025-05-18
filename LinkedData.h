#ifndef LINKEDDATA_H
#define LINKEDDATA_H

#include <stdexcept>

template <typename T>
class LinkedData {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& d) : data(d), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    Node* current;
    int length;

public:
    // Constructor
    LinkedData() : head(nullptr), tail(nullptr), current(nullptr), length(0) {}

    // Destructor
    ~LinkedData() {
        clear();
    }

    // Añade un nuevo elemento al final de la lista
    void add(const T& item) {
        Node* newNode = new Node(item);
        if (!head) {
            head = tail = current = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++length;
    }

    // Devuelve el tamaño de la lista
    int size() const {
        return length;
    }

    // Devuelve el elemento en la posición idx
    T get(int idx) const {
        Node* node = getNode(idx);
        return node->data;
    }

    // Elimina el nodo en la posición idx y devuelve su dato
    T remove(int idx) {
        Node* node = getNode(idx);
        T value = node->data;

        if (node == head) head = node->next;
        if (node == tail) tail = node->prev;
        if (node == current) current = node->next ? node->next : node->prev;

        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;

        delete node;
        --length;

        if (length == 0) head = tail = current = nullptr;
        return value;
    }

    // Mueve al siguiente nodo y devuelve su valor
    T next() {
        if (!current || !current->next)
            throw std::out_of_range("No hay siguiente elemento");
        current = current->next;
        return current->data;
    }

    // Mueve al nodo anterior y devuelve su valor
    T prior() {
        if (!current || !current->prev)
            throw std::out_of_range("No hay elemento anterior");
        current = current->prev;
        return current->data;
    }

    // Mueve el cursor al primer nodo y devuelve su valor
    T first() {
        if (!head)
            throw std::out_of_range("Lista vacía");
        current = head;
        return current->data;
    }

    // Mueve el cursor al último nodo y devuelve su valor
    T last() {
        if (!tail)
            throw std::out_of_range("Lista vacía");
        current = tail;
        return current->data;
    }

private:
    // Limpia toda la lista
    void clear() {
        Node* temp = head;
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        head = tail = current = nullptr;
        length = 0;
    }

    // Devuelve el puntero al nodo en la posición idx
    Node* getNode(int idx) const {
        if (idx < 0 || idx >= length)
            throw std::out_of_range("Índice fuera de rango");

        Node* temp;
        if (idx < length / 2) {
            temp = head;
            for (int i = 0; i < idx; ++i) temp = temp->next;
        } else {
            temp = tail;
            for (int i = length - 1; i > idx; --i) temp = temp->prev;
        }
        return temp;
    }
};

#endif // LINKEDDATA_H
