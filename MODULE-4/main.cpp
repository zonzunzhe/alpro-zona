#include <iostream>
#define cin std::cin
#define cout std::cout
#define endl std::endl
void banner_awal(){
    cout << "|=======================================================|" << endl;
    cout << "|                                                       |" << endl;
    cout << "[                 MODULE 4 FUNCTION                     ]" << endl;
    cout << "|                                                       |" << endl;
    cout << "|=======================================================|" << endl;
}
void header(char a='#',char b='#'){
    cout <<a<<"======================================================="<<b<< endl;
}

void store_menu(){
    cout <<"1. Input Barang"<<endl;
    cout <<"2. Hapus Barang"<<endl;
    cout <<"3. Edit Barang"<<endl;
    cout <<"4. Lihat Barang"<<endl;
    cout <<"0. Kembali"<<endl;
}
// void store_input(){
//     cout <<a<<""<<b<< endl;
//     int
// }
void kalkulator_dasar(double a,double b,char operasi){
    cout <<"Masukan Angka Pertama: ";
    cin >> a;
    cout <<"Masukan Angka Kedua: ";
    cin >> b;
    cout <<"Masukan Operasi: ";
    cin >> operasi;
    if (operasi=='+'){
        double hasil=a+b;
        cout <<"Hasil Operasi "<<a<<operasi<<b<<" = "<<hasil<<endl;
    }
    else if (operasi=='-'){
        double hasil=a-b;
        cout <<"Hasil Operasi "<<a<<operasi<<b<<" = "<<hasil<<endl;
    }
    else if (operasi=='*'){
        double hasil=a*b;
        cout <<"Hasil Operasi "<<a<<operasi<<b<<" = "<<hasil<<endl;
    }
    else if (operasi=='/'){
        if (b != 0) {
            double hasil=a/b;
            cout <<"Hasil Operasi "<<a<<operasi<<b<<" = "<<hasil<<endl;
        } else {
            cout << "Error: Pembagian dengan nol tidak diperbolehkan!" << endl;
        }
    }
    else {
        cout << "Operasi Tidak Valid" << endl;
    }
}
int faktorial(int n){
    cout<<"Masukan Angka: ";
    cin>>n;
    if (n <= 1) {
        return 1;
    }
    return n * faktorial(n - 1);
}
void kalkulator_menu(){
    int pilihan_menu,n;
    char operasi;
    double angka_pertama,angka_kedua;
    bool cihuy=1;
    cout <<"1. Operasi Dasar"<<endl;
    cout <<"2. Faktorial"<<endl;
    cout <<"3. Kembali"<<endl;
    header();
    do{
        cout <<"Pilih Menu: ";
        cin >>pilihan_menu;
        switch (pilihan_menu){
            case 1:
            kalkulator_dasar(angka_pertama,angka_kedua,operasi);
            system("pause");
            system("cls");
            break;
            case 2:
            faktorial(n);
            system("pause");
            system("cls");
            break;
            case 0:
            cihuy=0;
            system("pause");
            system("cls");
        }
    }
while(cihuy != 0);

}
int main(){
    int menu;
    banner_awal();
    cout<<"1. Tivaiz Store"<<endl;
    cout<<"2. Kalkulator"<<endl;
    cout<<"0. Exit"<<endl;
    header();
    cout<<"Pilih Menu: ";
    cin>>menu;
    system("cls");
    switch(menu) {
        case 1:
            header();
            cout << "|                    TIVAIZ STORE                       |" << endl;
            header();
            break;
        case 2:
            header('+','-');
            cout << "|                    K4LKUL4T0R                         |" << endl;
            header('x','/');
            kalkulator_menu();
        case 0:
            cout<<"GoodBye"<<endl;
            return 0;
    }
}