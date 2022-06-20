#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 10

using namespace std;

////Pemdeklarasian variabel Global

int jml_mhs, j, i, temp, pil, pil2, pil3;

// DIka Isnaida 21.11,4292
// struc data mahasiswa
struct DataMahasiswa
{
    string nama;
    int nim;
    float ipk;
};
DataMahasiswa dtmhs[100];
// Pendeklarasian Function
float HitungIpk(int *jmlh, int *banyak); // Function dengan parameter pointer unutk menerima alamat
void DataMhs(int *byk_mhs);
void InputData(); // Functioon dengan parameter pointer.
void TampilData();

// struct for stack
struct tumpukan
{
    int atas;
    string data[max];
} T;

// Pungsi stack / tumpukan
void awal();
int kosong();
int penuh();
void input(string data);
void tampil();
void hapus();
void bersih();
// Sortingg!!
void SortAndSearch();
void BubbleSortNim();
void SelectionSortNim();
void InsertionSortNim();
void BubbleSortIpk();
void SelectionSortIpk();
void InsertionSortIpk();

int main()
{

    int ketemu, posisi, cari;
    int Menu;

    // variable untuk data di stack
    string nama;

utama:

    cout << "===========> AMIKOM UNIVERSITY <===========" << endl;
    cout << "             === MAIN MENU ===" << endl;
    cout << "1. Data mahasiswa\n2. Tumpukan (Stack)\n3. OUt\n";
    cout << "Enter option: ";
    cin >> Menu;

    system("cls");
    switch (Menu)
    {
    case 1:
    A:
        cout << "<<=============================>>" << endl;
        cout << "           Data Mahasiswa        " << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Inputkan Data Mahasiswa\n2. Tampilkan Data Mahasiswa\n";
        cout << "3. Urutkan Data atau Cari Data Mahasiswa\n4. Return To Menu\n";
        cout << "Enter Your Option: ";
        cin >> pil;
        system("cls");
        switch (pil)
        {
        case 1:
            InputData();
            goto A;
        case 2:
            TampilData();
            goto A;
        case 3:
            SortAndSearch();
            goto A;
        case 4:
            system("cls");
            goto utama;
        default:
            cout << "Masukkan salah, Jika mau ke kembali tekan enter... ";
            goto A;
        }

    case 2:
    B:
        do
        {
            cout << "<<=============================>>" << endl;
            cout << "   STACK UNTUK DATA MAHASISWA    " << endl;
            cout << "---------------------------------" << endl;
            cout << "1. Input\n2. Hapus\n3. Tampil\n4. Bersihkan\n";
            cout << "5. Kembali ke Menu\n";
            cout << " Masukkan: ";
            cin >> pil;

            switch (pil)
            {
            case 1:
                cout << "Masukkan Nama Mahasiswa: ";
                cin >> nama;
                input(nama);
                break;
            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                bersih();
            }
            cout << "\n\n";
        } while (pil != 5);
        system("cls");
        goto utama;

    case 3:
        goto end;
    default:
        cout << "Pilihan salah!!!!!!" << endl;
        cout << "tekan enter untuk kembali ke menu..." << endl;
        cin.get();
        cin.ignore();
        system("cls");
        goto utama;
    }

end:
    cout << endl;
    // Mengambil dana menampilkan data yang telah diInputkan dari function
}

// Inisialisasi Function
float HitungIpk(int *jmlh, int *banyak)
{
    dtmhs[j].ipk = *jmlh / *banyak;
}

void InputData()
{
    cout << "========================" << endl;
    cout << "= Input Data Mahasiswa =" << endl;
    cout << "========================" << endl;
    cout << "Input banyak mahasiswa : ";
    cin >> jml_mhs;
    DataMhs(&jml_mhs); // Mengirim alamat ke pointer
}

void DataMhs(int *byk_mhs)
{
    int i, nilai[100], jml_nilai, jmlh_matkul;

    for (j = 0; j < jml_mhs; j++)
    {
        jml_nilai = 0;

        cout << "========================" << endl;
        cout << "Data Mahasiswa ke-" << j + 1 << endl;
        cout << "Nama: ";
        cin >> dtmhs[j].nama;
        cout << "NIM: ";
        cin >> dtmhs[j].nim;
        cout << "Berapa Matkul? : ";
        cin >> jmlh_matkul;

        for (i = 0; i < jmlh_matkul; i++)
        {
            cout << "Nilai matkul ke-" << i + 1 << " : ";
            cin >> nilai[i];

            jml_nilai = jml_nilai + nilai[i];
        }

        HitungIpk(&jml_nilai, &jmlh_matkul);
    }
    cout << "\nTekan enter Untuk kembali ke menu....  ";
    getch();
    system("cls");
}

void TampilData()
{
    cout << "==================" << endl;
    cout << "= Data Mahasiswa =" << endl;
    cout << "==================" << endl;
    for (i = 0; i < jml_mhs; i++)
    {
        cout << endl;

        cout << "Biodata Mahasiswa ke- " << i + 1 << endl;
        cout << "Nama Mahasiswa: " << dtmhs[i].nama << endl;
        cout << "Nim Mahasiswa: " << dtmhs[i].nim << endl;
        cout << "Ipk Mahasiswa: " << dtmhs[i].ipk << endl;
    }
    cout << "\nTekan enter Untuk kembali ke menu....  ";
    getch();
    system("cls");
}

void SortAndSearch()
{
    int pilsort;
sortmenu:
    cout << "<<=============================>>" << endl;
    cout << "  Bagian Sorting dan Searching  " << endl;
    cout << "---------------------------------" << endl;

    cout << "1.NIM(Nomor Induk Mahasiswa)" << endl;
    cout << "2.Ipk(Indeks Prestasi Kumulatif)" << endl;
    cout << "3.Searching Nim mahasiswa" << endl;
    cout << "Pilih Menu : ";
    cin >> pil;

    if (pil == 1)
    {
    sortingnim:
        cout << "\n<=== Menu Pilihan Sorting  ===>" << endl;
        cout << "1.Sorting by Bubble Sort." << endl;
        cout << "2.Sorting by Selection Sort." << endl;
        cout << "3.Sorting by Insertion Sort." << endl;
        cout << "Masukkan pilihan[1/2/3]: ";
        cin >> pil2;

        switch (pil2)
        {
        case 1:
            BubbleSortNim();
            getch();
            system("cls");
            break;
        case 2:
            SelectionSortNim();
            getch();
            system("cls");
            break;
        case 3:
            InsertionSortNim();
            getch();
            system("cls");
            break;
        default:
            cout << "\nInputan salah!!, Tekan enter Untuk kembali ke menu....  ";
            getch();
            system("cls");
            goto sortingnim;
        }
    }
    else if (pil == 2)
    {
        cout << "\n<=== Menu Pilihan Sorting  ===>" << endl;
        cout << "1.Sorting by Bubble Sort" << endl;
        cout << "2.Sorting by Selection Sort" << endl;
        cout << "3.Sorting by Insertion Sort2" << endl;
        cout << "Masukkan pilihan[1/2/3]: ";
        cin >> pil2;

        switch (pil2)
        {
        case 1:
            BubbleSortIpk();
            getch();
            system("cls");
            break;
        case 2:
            SelectionSortIpk();
            getch();
            system("cls");
            break;
        case 3:
            InsertionSortIpk();
            getch();
            system("cls");
            break;
        default:
            cout << "Pilihan anda salah!!!!!!!!!" << endl;
            cout << "\nTekan enter Untuk kembali ke menu....  ";
            getch();
            system("cls");
            goto sortmenu;
            cout << "Inputan salah maszeh !!!!!!!!!" << endl;
        }
    }
    else if (pil == 3)
    {
        int cari, ketemu, posisi;
        cout << "Masukkan nim yang anda cari: ";
        cin >> cari;

        ketemu = 0;
        for (i = 0; i < jml_mhs; i++)
        {
            if (dtmhs[i].nim == cari)
            {
                ketemu = 1;
                posisi = i;
                i = jml_mhs;
            }
        }
        if (ketemu == 0)
        {
            cout << "Data tidak ditemukan !!" << endl;
        }
        else
        {
            cout << "Data ditemukan pada mahasiswa ke-" << posisi + 1 << endl;
        }
    }
    else
    {
        cout << "Inputan tidak ada maszezh" << endl;
        cout << "Tekan untuk kembali ke menu...... ";
        getch();
        system("cls");
        goto sortmenu;
    }
}

void BubbleSortNim()
{
    for (i = 0; i < (jml_mhs - 1); i++)
    {
        for (j = 0; j < (jml_mhs - 1); j++)
        {
            if (dtmhs[j].nim > dtmhs[j + 1].nim)
            {
                temp = dtmhs[j].nim;
                dtmhs[j].nim = dtmhs[j + 1].nim;
                dtmhs[j + 1].nim = temp;
            }
        }
    }
    cout << "\nnim setelah diuturutkan dengan bubble sort" << endl;
    cout << "-----------------------------------------" << endl;
    for (i = 0; i < jml_mhs; i++)
    {
        cout << dtmhs[i].nim << endl;
    }
    cout << "-----------------------------------------" << endl;
    cout << "Tekan enter unutk kembali kemenu Menu.... ";
}
void SelectionSortNim()
{
    for (i = 0; i < jml_mhs; i++)
    {
        int min = i;
        for (j = i + 1; j < jml_mhs; j++)
        {
            if (dtmhs[min].nim > dtmhs[j].nim)
                min = j;
        }
        if (dtmhs[i].nim != dtmhs[min].nim)
        {
            temp = dtmhs[i].nim;
            dtmhs[i].nim = dtmhs[min].nim;
            dtmhs[min].nim = temp;
        }
    }
    cout << "\nnim setelah diuturutkan dengan Selection sort" << endl;
    cout << "-----------------------------------------" << endl;
    for (i = 0; i < jml_mhs; i++)
    {
        cout << dtmhs[i].nim << endl;
    }
    cout << "-----------------------------------------" << endl;
    cout << "Tekan enter unutk kembali kemenu Menu.... ";
}
void InsertionSortNim()
{
    for (i = 0; i < jml_mhs; i++)
    {
        temp = dtmhs[i].nim;
        j = i - 1;

        while (dtmhs[j].nim > temp && j >= 0)
        {
            dtmhs[j + 1].nim = dtmhs[j].nim;
            j--;
        }
        dtmhs[j + 1].nim = temp;
    }
    cout << "\nnim setelah diuturutkan dengan  sort" << endl;
    cout << "-----------------------------------------" << endl;
    for (i = 0; i < jml_mhs; i++)
    {
        cout << dtmhs[i].nim << endl;
    }
    cout << "-----------------------------------------" << endl;
    cout << "Tekan enter unutk kembali kemenu Menu.... ";
}
void BubbleSortIpk()
{
    for (i = 0; i < (jml_mhs - 1); i++)
    {
        for (j = 0; j < (jml_mhs - 1); j++)
        {
            if (dtmhs[j].ipk > dtmhs[j + 1].ipk)
            {
                temp = dtmhs[j].ipk;
                dtmhs[j].ipk = dtmhs[j + 1].ipk;
                dtmhs[j + 1].ipk = temp;
            }
        }
    }
    cout << "\nipk setelah diuturutkan dengan bubble sort" << endl;
    cout << "-----------------------------------------" << endl;
    for (i = 0; i < jml_mhs; i++)
    {
        cout << dtmhs[i].ipk << endl;
    }
    cout << "-----------------------------------------" << endl;
    cout << "Tekan enter unutk kembali kemenu Menu.... ";
}

void SelectionSortIpk()
{
    for (i = 0; i < jml_mhs; i++)
    {
        int min = i;
        for (j = i + 1; j < jml_mhs; j++)
        {
            if (dtmhs[min].ipk > dtmhs[j].ipk)
                min = j;
        }
        if (dtmhs[i].ipk != dtmhs[min].ipk)
        {
            temp = dtmhs[i].ipk;
            dtmhs[i].ipk = dtmhs[min].ipk;
            dtmhs[min].ipk = temp;
        }
    }
    cout << "\nipk setelah diuturutkan dengan Selection sort" << endl;
    cout << "-----------------------------------------" << endl;
    for (i = 0; i < jml_mhs; i++)
    {
        cout << dtmhs[i].ipk << endl;
    }
    cout << "-----------------------------------------" << endl;
    cout << "Tekan enter unutk kembali kemenu Menu.... ";
}

void InsertionSortIpk()
{
    for (i = 0; i < jml_mhs; i++)
    {
        temp = dtmhs[i].ipk;
        j = i - 1;

        while (dtmhs[j].ipk > temp && j >= 0)
        {
            dtmhs[j + 1].ipk = dtmhs[j].ipk;
            j--;
        }
        dtmhs[j + 1].ipk = temp;
    }
    cout << "\nipk setelah diuturutkan dengan  sort" << endl;
    cout << "-----------------------------------------" << endl;
    for (i = 0; i < jml_mhs; i++)
    {
        cout << dtmhs[i].ipk << endl;
    }
    cout << "-----------------------------------------" << endl;
    cout << "Tekan enter unutk kembali kemenu Menu.... ";
}

// Fungsi Stack
void awal()
{
    T.atas = -1;
}

int kosong()
{
    if (T.atas == -1)
        return 1;
    else
        return 0;
}

int penuh()
{
    if (T.atas == max - 1)
        return 1;
    else
        return 0;
}

void input(string data)
{
    if (kosong() == 1)
    {
        T.atas++;
        T.data[T.atas] = data;
        cout << "Nama " << T.data[T.atas] << " Masuk ke stack";
    }

    else if (penuh() == 0)
    {
        T.atas++;
        T.data[T.atas] = data;
        cout << "Nama " << T.data[T.atas] << " Masuk ke stack";
    }
    else
        cout << "Tumpukan penuh";
}

void hapus()
{
    if (kosong() == 0)
    {
        cout << "Nama teratas sudah terambil";
        T.atas--;
    }
    else
        cout << "Data nama kosong";
}

void tampil()
{
    if (kosong() == 0)
    {
        for (int i = T.atas; i > 0; i--)
        {
            cout << "Tumpukan ke-" << i << " = " << T.data[i] << endl;
        }
    }
    else
        cout << "Tumpukan nama kosong!";
}

void bersih()
{
    T.atas = -1;
    cout << "Tumpukann nama kosong!";
}