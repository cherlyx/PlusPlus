#include <iostream> 

#include <string> 

using namespace std;

template <typename T>

class List {

private:

    class Node {

    public:

        T data;

        Node* next;



        Node(T data) : data(data), next(nullptr) {}

    };



    Node* head;

    int size;



public:

    List() : head(nullptr), size(0) {}

    void pushBack(T data) {

        Node* newNode = new Node(data);

        if (head == nullptr) {

            head = newNode;

        }

        else {

            Node* temp = head;

            while (temp->next != nullptr) {

                temp = temp->next;

            }

            temp->next = newNode;

        }

        size++;

    }

    void popBack() {

        if (head == nullptr) {

            return;

        }

        else if (head->next == nullptr) {

            delete head;

            head = nullptr;

            size--;

        }

        else {

            Node* temp = head;

            while (temp->next->next != nullptr) {

                temp = temp->next;

            }

            delete temp->next;

            temp->next = nullptr;

            size--;

        }

    }

    void display() {

        Node* temp = head;

        while (temp != nullptr) {

            std::cout << temp->data << " ";

            temp = temp->next;

        }

        std::cout << std::endl;

    }

    T at(int index) {

        if (index < 0 || index >= size) {

            throw std::out_of_range("Index out of range");

        }

        Node* temp = head;

        for (int i = 0; i < index; i++) {

            temp = temp->next;

        }

        return temp->data;

    }

    int find(T value) {

        int index = 0;

        Node* temp = head;

        while (temp != nullptr) {

            if (temp->data == value) {

                return index;

            }

            temp = temp->next;

            index++;

        }

        return -1;

    }

    int getSize() {

        return size;

    }

};

int main() {

    setlocale(LC_ALL, "ru");

    List<int> list;

    cout << "Введите кол-во элементов " << endl;

    int k, q;

    int n = 1;

    cin >> k;

    for (int i = 0; i < k; i++) {

        cout << "Введите данные элемента под номером: " << n << " " << endl;

        cin >> q;

        list.pushBack(q);

        n += 1;

    }

    list.display();

    list.popBack();

    return 0;

}