#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Pasien {
    string nama, jenis;
    int umur, tingkatDarurat;
};

void tampilkanAntrean(const vector<Pasien>& antrean) {
    cout << "\n\n";
    for (int i = 0; i < antrean.size(); i++) {
        cout << i + 1 << ". "  << antrean[i].nama << " (" << antrean[i].umur << " tahun) - Darurat " << antrean[i].tingkatDarurat << endl;
    }
}

int main() {
    int jumlah;
    cout << "Masukkan jumlah pasien: ";
    cin >> jumlah;
    cin.ignore(); 

    vector<Pasien> antrean;

    for (int i = 0; i < jumlah; i++) {
        Pasien p;
        cout << "\nPasien " << i + 1 << ":\n";
        cout << "Nama hewan: ";
        getline(cin, p.nama);
        cout << "Jenis hewan: ";
        getline(cin, p.jenis);
        cout << "Umur: ";
        cin >> p.umur;
        cout << "Tingkat darurat (1-5): ";
        cin >> p.tingkatDarurat;
        cin.ignore();
        antrean.push_back(p);
    }

    for (int i = 0; i < antrean.size() - 1; i++) {
        for (int j = i + 1; j < antrean.size(); j++) {
            if (antrean[j].tingkatDarurat > antrean[i].tingkatDarurat) {
                swap(antrean[i], antrean[j]);
            }
        }
    }

    tampilkanAntrean(antrean);
    return 0;
}