#include <iostream>

struct Node {
    int data;
    Node* next;
};

void addNode(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void createList(Node*& head) {
    int n;
    std::cout << "Enter the number of elements in the list: ";
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        int value;
        std::cout << "Enter element #" << (i + 1) << ": ";
        std::cin >> value;
        addNode(head, value);
    }
}

void printList(Node* head) {
    Node* temp = head;
    std::cout << "List: ";
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

bool hasAdjacentDuplicates(Node* head) {
    if (!head || !head->next) {
        return false;
    }
    
    Node* temp = head;
    while (temp->next) {
        if (temp->data == temp->next->data) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteList(Node*& head) {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;
    
    createList(head);
    
    printList(head);
    
    if (hasAdjacentDuplicates(head)) {
        std::cout << "The list contains adjacent duplicate values." << std::endl;
    } else {
        std::cout << "The list does not contain adjacent duplicate values." << std::endl;
    }
    
    deleteList(head);
    return 0;
}