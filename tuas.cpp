#include <iostream>
using namespace std;

class BankGibranJaya {
protected:
    string nama;
    double saldo;

public:
    BankGibranJaya(string nama, double saldo) {
        this->nama = nama;
        this->saldo = saldo;
    }

    virtual void potongAdmin() = 0;

    void tampilkanData() {
        cout << "Nama  : " << nama << endl;
        cout << "Saldo : Rp " << saldo << endl;
    }

};

class RekeningSyariah : public BankGibranJaya {
public:
    RekeningSyariah(string nama, double saldo) : BankGibranJaya(nama, saldo) {}

    void potongAdmin() {
        cout << "Rekening Syariah bebas biaya admin.\n";
    }
};

class RekeningKonvensional : public BankGibranJaya {
public:
    RekeningKonvensional(string nama, double saldo) : BankGibranJaya(nama, saldo) {}

    void potongAdmin() {
        saldo -= 15000;
        cout << "Biaya admin Rp 15.000 berhasil dipotong.\n";
    }
};

class RekeningPremium : public BankGibranJaya {
public:
    RekeningPremium(string nama, double saldo) : BankGibranJaya(nama, saldo) {}

    void potongAdmin() {
        if (saldo > 10000000) {
            cout << "Saldo di atas Rp 10.000.000, bebas biaya admin.\n";
        } else {
            saldo -= 50000;
            cout << "Biaya admin premium Rp 50.000 berhasil dipotong.\n";
        }
    }
};

int main() {
    BankGibranJaya* rekening[3];

    rekening[0] = new RekeningSyariah("Alya", 5000000);
    rekening[1] = new RekeningKonvensional("Budi", 3000000);
    rekening[2] = new RekeningPremium("Citra", 10000000);

    for (int i = 0; i < 3; i++) {
        cout << "\n=== Data Sebelum Potong Admin ===\n";
        rekening[i]->tampilkanData();

        cout << "\nProses potong admin:\n";
        rekening[i]->potongAdmin();

        cout << "\n=== Data Setelah Potong Admin ===\n";
        rekening[i]->tampilkanData();
    }

    return 0;
}