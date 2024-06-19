#include <iostream>
#include <array>
using namespace std;

struct Mahasiswa {
    string npm;
    string nama;
    float ipk;
};

void pengurutan(Mahasiswa arr[], int n) {
    int i, j;
    Mahasiswa key;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].npm > key.npm) { 
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void hasilCari(Mahasiswa hasil) {
    cout << "Hasil Pencarian Data Mahasiswa" << endl;
    cout << "Nama\t: " << hasil.nama << " " << endl;
    cout << "NPM\t: " << hasil.npm << " " << endl;
    cout << "IPK\t: " << hasil.ipk << " " << endl;
}

void cariData(Mahasiswa array[], int n) {
    string npm;
    cout << "Masukkan NPM: ";
    cin >> npm;
    for (int i = 0; i < n; i++) {
        if (array[i].npm == npm) {
            hasilCari(array[i]);
        }
    }
}

int main() {
    int i, n = 0;

    cout << "Masukkan Banyak Data: ";
    cin >> n;

    Mahasiswa* mhs = new Mahasiswa[n];

    for (int i = 0; i < n; i++) {
        cout << "Masukkan data mahasiswa ke- " << i << endl;
        cout << "Nama\t : ";
        cin >> mhs[i].nama;
        cout << "NPM\t : ";
        cin >> mhs[i].npm; 
        cout << "IPK\t : ";
        cin >> mhs[i].ipk;
        cout << endl;
    }

    pengurutan(mhs, n);
    cout << "Hasil pengurutan Data mahasiswa : ";
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nama\t : " << mhs[i].nama << " " << endl;
        cout << "NPM\t : " << mhs[i].npm << " " << endl;
        cout << "IPK\t : " << mhs[i].ipk << " " << endl;
        cout << endl;
    }

    cout << "Cari data Mahasiswa" << endl;
    cariData(mhs, n);

    
    return 0;
}