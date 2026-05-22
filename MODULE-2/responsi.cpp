#include <iostream>
using namespace std;
int main(){
    int n,count=0;
    cout<<"--- CEK BILANGAN PRIMA ---"<<endl;
    do{
        cout<<"masukan angka: ";
        cin>>n;
        cin.ignore(1000, '\n');
        if (cin.fail()) {
            cin.clear();
            cout << "Input harus berupa angka! Coba lagi.\n";
            break;
        }
        else {
        for (int i = 1;i <= n;i++){
            if (n%i == 0){
                ++ count;
            }
        }
        if (count==2){
            cout <<n<<" adalah bilangan prima"<<endl;
            count = 0;
        }
        else {
            cout <<n<<" adalah bukan bilangan prima"<<endl;
            count = 0;
        }
    }
}
    while (true);
}