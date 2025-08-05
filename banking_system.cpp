#include <iostream>
using namespace std;

class Payment_method {
public:
    virtual void payment_process(double amount) = 0;
    virtual ~Payment_method() {}
};

class credit_card : public Payment_method {
public:
    int card_number;
    void payment_process(double amount) override {
        cout << "Enter card number: ";
        cin >> card_number;
        if (card_number) {
            cout << "Credit card payment of Rs. " << amount << " successful." << endl;
        }
    }
};

class upi : public Payment_method {
public:
    int upi_number;
    void payment_process(double amount) override {
        cout << "Enter UPI number: ";
        cin >> upi_number;
        if (upi_number) {
            cout << "UPI payment of Rs. " << amount << " successful." << endl;
        }
    }
};

int main() {
    Payment_method* payment;

    payment = new credit_card();
    payment->payment_process(1200.0);
    delete payment;

    payment = new upi();
    payment->payment_process(750.0);
    delete payment;

    return 0;
}