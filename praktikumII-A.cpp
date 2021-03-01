#include <iostream>
#include "data_classes.cpp"

using namespace std;

DataPembeli data_pembeli;
DataBarang data_barang;
DataKeranjang data_keranjang;
DataExecution dEx;

int main(int argc, char const *argv[]){

    string kode_pembeli, kode_barang;
    int jumlah_barang;

    dEx.onInit();
    pembeliInput:
    cout << "Kode pembeli(menggunakan huruf kapital) : "; cin >> kode_pembeli;
    if(kode_pembeli.length() < 4 )
    {
        cout<<endl<<"Kode Pembeli Salah. Mohon masukkan ulang." << endl << endl;
        goto pembeliInput;
    }

    dEx.findPembeliByKodePbl(kode_pembeli);
    
    cout << "Nama pembeli : " << dEx.getPembeliNama() << endl;
    cout << "Status pembeli : " << dEx.getStatusPembeli() << endl;
    
    barangInput:
    cout << endl << endl << "Kode barang(menggunakan huruf kapital) : "; cin >> kode_barang;
    if(kode_barang.length() < 6)
    {
        cout<<endl<<"Kode Barang Salah. Mohon masukkan ulang." << endl << endl;
        goto barangInput;
    }

    dEx.findBarangByKodeBarang(kode_barang);
    cout << "Nama barang : " << dEx.getNamaBarang() << endl;
    cout << "Harga barang : " << dEx.getHarga() << endl;

    inputJumlahBarang:
    cout << "Jumlah barang : "; cin >> jumlah_barang;
    if (jumlah_barang != 0 && jumlah_barang < 0)
    {
        cout<<endl<<"Jumlah barang Salah. Mohon masukkan ulang." << endl << endl;
        goto inputJumlahBarang;
    }

    string konfirmasi;
    cout << "Apakah anda ingin menambahkan di keranjang ? y/n : "; cin >> konfirmasi;
    if(konfirmasi == "y")
    {
        if(!dEx.masukkanKeranjang(jumlah_barang)){
            cout << "Mohon Maaf Keranjang Penuh" << endl;
            goto checkout;
        }else{
            addPrompt:
            string tambah_barang_again;
            cout << "Apakah anda ingin menambahkan barang lagi ? y/n : "; cin >> tambah_barang_again;
            if(tambah_barang_again == "y")
            {
                goto barangInput;
            }
            goto checkout;
        }
    }else{
        goto addPrompt;
    }

    checkout:
    int uang = 0;
    int subTotal = 0;
    cout<<endl<<"Masukkan Uang Pembayaran : "; cin >> uang;
    cout <<endl<<endl<<endl;
    cout << "TOKO INDO APRIL" << endl << "Jl. DI Panjaitan 128 Purwokerto" << endl << endl;
    cout << "Kode barang      Nama barang      Jumlah      Harga       Total" << endl;
    for (int t = 0; t < dEx.getKeranjangSize(); t++)
    {
        string kodebarang = dEx.getKeranjangKode(t);
        string namabarang = dEx.getKeranjangNama(t);
        int jumlahbarang = dEx.getKeranjangQty(t);
        int harga = dEx.getKeranjangHarga(t);
        int sub = harga * jumlahbarang;
        subTotal += sub;
        cout << kodebarang;
        cout << "           ";
        cout << namabarang;
        cout << "            ";
        cout << jumlahbarang;
        cout << "            ";
        cout << harga;
        cout << "       ";
        cout << sub;
        cout << "\n";

    }
    cout << "===============================================================" << endl;
    cout << "Subtotal                                               " << subTotal << endl;
    cout << "Diskon                                                 " << dEx.getDisc(subTotal) << endl;
    cout << "Total                                                  " << subTotal - dEx.getDisc(subTotal) << endl;
    cout << "===============================================================" << endl;
    cout << "Total Bayar                                            " << uang << endl;
    cout << "Kembalian                                              ";
    if(uang < subTotal - dEx.getDisc(subTotal)){
        cout << "Anda Hutang "<< subTotal - dEx.getDisc(subTotal) + uang - uang << endl;
    }else{
        cout << uang - subTotal << endl;
    }
    cout << endl << endl << endl;
    cout << "Data pembeli" << endl;
    cout << "Kode pembeli : " << kode_pembeli << endl;
    cout << "Nama pembeli : " << dEx.getPembeliNama() << endl;
    cout << "Status pembeli : " << dEx.getStatusPembeli() << endl;

    return 0;
}

