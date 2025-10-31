#include <iostream>
#include <string>
using namespace std;

struct Film {
    string judul;
    int tahun, rating;
    Film* next;
};

Film* head = nullptr;

void tambahBelakang(string judul, int tahun, int rating) {
    Film* baru = new Film;
    baru->judul = judul;
    baru->tahun = tahun;
    baru->rating = rating;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Film* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void tampilkanFilm() {
    if (head == nullptr) {
        cout << "Tidak ada film dalam daftar.\n";
        return;
    }

    Film* temp = head;
    while (temp != nullptr) {
        cout << temp->judul << " (" << temp->tahun << ") - " << temp->rating << endl;
        temp = temp->next;
    }
}

void hapusFilm(string judulHapus) {
    if (head == nullptr) {
        cout << "Daftar film kosong!\n";
        return;
    }

    Film* temp = head;
    Film* prev = nullptr;

    if (temp != nullptr && temp->judul == judulHapus) {
        head = temp->next;
        delete temp;
        cout << "Film '" << judulHapus << "' berhasil dihapus.\n";
        return;
    }

    while (temp != nullptr && temp->judul != judulHapus) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Film dengan judul '" << judulHapus << "' tidak ditemukan.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Film '" << judulHapus << "' berhasil dihapus.\n";
}

int hitungFilm() {
    int count = 0;
    Film* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int jumlah;
    cout << "Masukkan jumlah film awal: ";
    cin >> jumlah;
    cin.ignore();

    for (int i = 0; i < jumlah; i++) {
        string judul;
        int tahun, rating;
        cout << "\nFilm " << i + 1 << ":\n";
        cout << "Judul: ";
        getline(cin, judul);
        cout << "Tahun: ";
        cin >> tahun;
        cout << "Rating: ";
        cin >> rating;
        cin.ignore();

        tambahBelakang(judul, tahun, rating);
    }

    char hapus;
    cout << "\nApakah ingin menghapus film? (y/n): ";
    cin >> hapus;
    cin.ignore();

    if (hapus == 'y' || hapus == 'Y') {
        string judulHapus;
        cout << "Masukkan judul film yang sudah ditonton: ";
        getline(cin, judulHapus);
        hapusFilm(judulHapus);
    }

    cout;
    tampilkanFilm();

    cout << "\nTotal film tersisa: " << hitungFilm() << endl;

    return 0;
}
