//a static member function is a function that belongs to the class itself rather than to any specific object (instance) of that class. 
//Because it is a class-level function, it exists independently of any object and can be called even if no objects have been created
#include <iostream>
using namespace std;
class Counter{
    private:
    static int objcount;
    
    public:
    Counter(){objcount++;};
    ~Counter(){objcount--;};
    
    static int getcount(){
        return objcount;
    }
};
int Counter::objcount=0;

int main() {
    cout<<"1st count - > "<<Counter::getcount()<<endl;
    Counter c1,c2;
     cout<<"count - > "<<Counter::getcount()<<endl;
    // Write C++ code here
    std::cout << "Try programiz.pro";

    return 0;
}
