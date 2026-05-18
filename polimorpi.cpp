#include <iostream>
using namespace std;

class seseorang
{
public:
    virtual void pessan() = 0;
    // virtual void pesan() {
    //     cout << "Pesan dari seseorang" << endl;
    // }
};

class joko :public seseorang {
    virtual void pesan() {
        cout << "Pesan dari Joko" << endl;
    }
};