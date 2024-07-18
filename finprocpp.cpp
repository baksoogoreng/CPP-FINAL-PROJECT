#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

void menu()
{   
    cout << endl;
    cout << "Selamat Datang di Sistem Informasi Panitia!" << endl;
    cout << "=============================" << endl;
    cout << "Silakan Memilih Menu" << endl;
    cout << "1. Tambah Data Panitia" << endl;
    cout << "2. Hapus Data Panitia" << endl;
    cout << "3. Edit Data Panitia" << endl;
    cout << "4. Tampilkan Data Panitia" << endl;
    cout << "5. Keluar" << endl;
    cout << "=============================" << endl;
}

struct Panit
{
    string nama;
    string div;
    int kelas;
    int NIS;
    string nomortelp;
};

void tambah(vector<Panit>& datapanit)
{
    Panit panit;
    cout << "Masukkan Nama: ";
    getline(cin, panit.nama);
    cout << "Masukkan Divisi: ";
    getline(cin, panit.div);
    cout << "Masukkan Kelas: ";
    cin >> panit.kelas;
    cout << "Masukkan NIS: ";
    cin >> panit.NIS;
    cout << "Masukkan Nomor Telepon: ";
    cin >> panit.nomortelp;
    datapanit.push_back(panit);
    cout << "Data berhasil ditambahkan!" << endl;
}

void hapus(vector<Panit>& datapanit)
{
    int indeks;
    cout << "!!!!! HAPUS DATA PANITIA !!!!!" << endl;
    cout << "Masukkan nomor panitia yang ingin dihapus : ";
    cin >> indeks;
    cin.clear();
    cin.ignore();
    char pilih;
    cout << "Apakah kamu yakin akan menghapus data panitia ke " << indeks << " ? (Y/N) ";
    cin >> pilih;
    if (indeks>0 && indeks<=datapanit.size())
    {   if (pilih=='Y'||pilih=='y')
        {
        datapanit.erase(datapanit.begin() + (indeks - 1));
        cout << "Data berhasil dihapus!" << endl;
        }
    }
    else
    {
        cout << "Mohon masukkan nomor panitia dengan benar!" << endl;
    }
}

void edit(vector<Panit>& datapanit)
{
    Panit panit;
    int indeks;
    cout << "## EDIT DATA PANITIA ##" << endl;
    cout << "Masukkan nomor panitia yang ingin diedit : ";
    cin >> indeks;
    cin.clear();
    cin.ignore();
    if (indeks>0 && indeks<=datapanit.size())
    {   
        cout << "Masukkan Nama: ";
        getline(cin, datapanit[indeks-1].nama);
        cout << "Masukkan Divisi: ";
        getline(cin, datapanit[indeks-1].div);
        cout << "Masukkan Kelas: ";
        cin >> datapanit[indeks-1].kelas;
        cin.clear();
        cin.ignore();
        cout << "Masukkan NIS: ";
        cin >> datapanit[indeks-1].NIS;
        cin.clear();
        cin.ignore();
        cout << "Masukkan Nomor Telepon: ";
        cin >> datapanit[indeks-1].nomortelp;
        cin.clear();
        cin.ignore();
        cout << "Data berhasil diedit!" << endl;
    }
    else
    {
        cout << "Mohon masukkan nomor panitia dengan benar!" << endl;
    }
}

void tampilkan(vector<Panit>& datapanit)
{
    cout << "| | Data Panitia | |" << endl;
    cout << "=============================" << endl;
    for (int i = 0; i < datapanit.size(); i++)
    {
        const Panit& panit = datapanit[i];
        cout << endl;
        cout << "Data Panitia " << i + 1 << endl;
        cout << "Nama : " << panit.nama << endl;
        cout << "Divisi : " << panit.div << endl;
        cout << "Kelas : " << panit.kelas << endl;
        cout << "NIS : " << panit.NIS << endl;
        cout << "No. Telp : " << panit.nomortelp << endl;
        cout << endl;
        cout << "=============================" << endl;
    }
}

int main()
{   
    int pilihanmenu;
    vector<Panit> datapanit;
    Panit panit1 = {"chiquita", "publikasi", 12, 13322, "08123432453"};
    datapanit.push_back(panit1);
    do{
        menu();
        cout << "\nPilih Menu : ";
        cin >> pilihanmenu;
        cin.clear();
        cin.ignore();
        if (pilihanmenu == 1)
        {
            tambah(datapanit);
        }
        else if (pilihanmenu == 2)
        {
            hapus(datapanit);
        }
        else if (pilihanmenu == 3)
        {
            edit(datapanit);
        }
        else if (pilihanmenu == 4)
        {
            tampilkan(datapanit);
        }
        else if (pilihanmenu == 5)
        {
            break;
        }
        system("pause");
        system("cls");
    }
    while (pilihanmenu != 5);
    return 0;
}
