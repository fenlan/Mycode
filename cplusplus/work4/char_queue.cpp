/* *************************************************
    Author: fenlan
    Date: 2017.5.15

    Define a class Char_queue so that the public
   interface does not depend on the representation.
   Implement Char_queue(a) as a linked list and (b)
   as a vector. On not worry about concurrency.
  **************************************************
  */


#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char value;
    Node* next;
};

class Char_queue {
private:
    char queue_type;
    Node* list_head;
    vector<char> queue;
public:
    Char_queue(char type) {
        queue_type = type;
        Node* t = new Node;
        t->value = 0;
        t->next = NULL;
        list_head = t;

    };
    void insert_value(char value) {
        if (queue_type == 'a') {
            if (list_head->value == 0) {
                list_head->value = value;
                list_head->next = NULL;
            }
            else {
                Node* p = list_head;
                while (p->next != NULL) {
                    p = p->next;
                }
                Node* t = new Node;
                t->value = value;
                t->next = NULL;
                p->next = t;
            }
        }
        else if (queue_type == 'b')
            queue.push_back(value);
    };
    void print_queue() {
        if (queue_type == 'a') {
            Node *p = list_head;
            if (p->value == 0) {
                cout << "The queue is empty!\n";
            }
            else {
                while (p != NULL) {
                    cout << p->value << " ";
                    Node* q = p;
                    p = p->next;
                    delete q;
                }
            }
            cout << endl;
        }
        else if (queue_type == 'b') {
            for (int i = 0; i < queue.size(); i++)
                cout << queue[i] << " ";
            cout << endl;
        }
    };
};

int main()
{
    Char_queue queue1('a');
    queue1.insert_value('a');
    queue1.insert_value('b');
    queue1.insert_value('c');
    queue1.print_queue();
    Char_queue queue2('b');
    queue2.insert_value('a');
    queue2.insert_value('b');
    queue2.insert_value('c');
    queue2.print_queue();
    return 0;
}
