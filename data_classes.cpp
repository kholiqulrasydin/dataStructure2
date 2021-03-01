#include <iostream>

using namespace std;

const int arraySize = 5;

class DataPembeli
{
private:
    struct DataPembeliModel
    {
        string kode_pbl;
        string status;
        string nama;
    };    
    
public:
    
    DataPembeliModel dataList[arraySize];

};

class DataBarang
{
private:
    struct DataBarangModel
    {
        string kode_barang;
        string nama_barang;
        int harga;
    };
    
public:
    
    DataBarangModel dataList[arraySize];

};

class DataKeranjang
{
private:
    struct DataKeranjangModel
    {
        string kode_barang;
        string nama_barang;
        int harga;
        int jumlah_barang;
    };
public:
    DataKeranjangModel dataKeranjang[arraySize];

};

class DataExecution
{
private:

    DataBarang dataBarang;
    DataPembeli dataPembeli;
    DataKeranjang dataKeranjang;
    int keranjangIndex = 0;
    int barangIndex = 0;
    int pembeliIndex = 0;
public:

    void onInit(){
        dataPembeli.dataList[0].kode_pbl = "P001";
        dataPembeli.dataList[0].status = "M";
        dataPembeli.dataList[0].nama = "Diana";

        dataPembeli.dataList[1].kode_pbl = "P002";
        dataPembeli.dataList[1].status = "M";
        dataPembeli.dataList[1].nama = "Rina";

        dataPembeli.dataList[2].kode_pbl = "P003";
        dataPembeli.dataList[2].status = "BM";
        dataPembeli.dataList[2].nama = "Lina";

        dataPembeli.dataList[3].kode_pbl = "P004";
        dataPembeli.dataList[3].status = "BM";
        dataPembeli.dataList[3].nama = "Doni";

        dataPembeli.dataList[4].kode_pbl = "P005";
        dataPembeli.dataList[4].status = "M";
        dataPembeli.dataList[4].nama = "Dodi";

        dataBarang.dataList[0].kode_barang = "BRG001";
        dataBarang.dataList[0].nama_barang = "Pensil";
        dataBarang.dataList[0].harga = 2000;

        dataBarang.dataList[1].kode_barang = "BRG002";
        dataBarang.dataList[1].nama_barang = "Buku Tulis";
        dataBarang.dataList[1].harga = 3500;

        dataBarang.dataList[2].kode_barang = "BRG003";
        dataBarang.dataList[2].nama_barang = "Penghapus";
        dataBarang.dataList[2].harga = 1000;

        dataBarang.dataList[3].kode_barang = "BRG004";
        dataBarang.dataList[3].nama_barang = "Penggaris";
        dataBarang.dataList[3].harga = 1500;

        dataBarang.dataList[4].kode_barang = "BRG005";
        dataBarang.dataList[4].nama_barang = "Ballpoint";
        dataBarang.dataList[4].harga = 2500;
    }

    string getStatusPembeli(){
        string status = dataPembeli.dataList[pembeliIndex].status;
        string sts = "Bukan Member";
        if (status == "M")
        {
            sts = "Member";
        }

        return sts;
        
    }

    int getKeranjangSize(){

        int keranjangSize = keranjangIndex + 1;
        return keranjangSize;

    }

    int getPembeliIndex(){
        return pembeliIndex;
    }

    int getBarangIndex(){
        return barangIndex;
    }

    void findPembeliByKodePbl(string kodePbl){
        int retr = -1;
        for (int i = 0; i < arraySize; i++)
        {
            if (kodePbl == dataPembeli.dataList[i].kode_pbl)
            {
                retr = i;
                break;
            }
        }
        
        pembeliIndex = retr;
    }

    void findBarangByKodeBarang(string kodeBarang){
        int retr = -1;
        for (int i = 0; i < arraySize; i++)
        {
            if (kodeBarang == dataBarang.dataList[i].kode_barang)
            {
                retr = i;
                break;
            }
        }
        
        barangIndex = retr;
    }

    bool masukkanKeranjang(int jumlahBarang){
        if(keranjangIndex < arraySize){
            string kodeBarang = dataBarang.dataList[barangIndex].kode_barang; 
            string namaBarang = dataBarang.dataList[barangIndex].nama_barang;  
            int harga = dataBarang.dataList[barangIndex].harga;
            dataKeranjang.dataKeranjang[keranjangIndex].kode_barang = kodeBarang;
            dataKeranjang.dataKeranjang[keranjangIndex].nama_barang = namaBarang;
            dataKeranjang.dataKeranjang[keranjangIndex].harga = harga;
            dataKeranjang.dataKeranjang[keranjangIndex].jumlah_barang = jumlahBarang;
            keranjangIndex++;
            return true;
        }else{
            return false;
        }
    }

    int getDisc(int subTotal){
        int disc = 0;
        string status = dataPembeli.dataList[pembeliIndex].status;
        if(status == "M"){
            disc = 0.1 * subTotal;
        }

        return disc;

    }

    string getPembeliNama(){
        return dataPembeli.dataList[pembeliIndex].nama;
    }

    string getNamaBarang(){
        return dataBarang.dataList[barangIndex].nama_barang;
    }

    int getHarga(){
        return dataBarang.dataList[barangIndex].harga;
    }

    string getKeranjangNama(int index){
        return dataKeranjang.dataKeranjang[index].nama_barang;
    }
    string getKeranjangKode(int index){
        return dataKeranjang.dataKeranjang[index].kode_barang;
    }
    int getKeranjangHarga(int index){
        return dataKeranjang.dataKeranjang[index].harga;
    }
    int getKeranjangQty(int index){
        return dataKeranjang.dataKeranjang[index].jumlah_barang;
    }

};




