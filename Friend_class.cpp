// Online C++ compiler to run C++ program online

// How a friend class is declaring an entire class as a friend gives all of its member functions access to the private parts of the original class.
#include <iostream>
using namespace std;
class Node{
    int data;
    Node *next;
    
    friend class Linkedlist;
    
    public:
    Node(int value):data(value),next(nullptr){}
};
class Linkedlist{
    public:
    void print_node(Node &n){
        cout<<"Node Data: "<<n.data<<endl;
    }
};

int main() {
  Node n1(10);
  Node n2(11);
  Linkedlist l1;
  l1.print_node(n1);
  l1.print_node(n2);
    // Write C++ code here
    //std::cout << "Try programiz.pro";

    return 0;
}
