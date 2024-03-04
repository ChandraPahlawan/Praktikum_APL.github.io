#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

using namespace std;

int main() {    
   int i;  
   string pass_input, user_input;       
   cout << "==========================================="<< endl;    
   cout << "|                 POSTTEST 1              |"<< endl;    
   cout << "==========================================="<< endl;  
   cout << "|        Chandra Adha Rezki Pahlawan      |"<< endl;  
   cout << "|             INFORMATIKA A'2023          |"<< endl;  
   cout << "|                 2309106011              |"<< endl;  
   cout << "===========================================\n"<< endl;
   cout << "Silahkan Login jika ingin menggunakan nya..\n";  
   cout << "===========================================\n"<< endl;
   string username ="Chandra";    //variabel untuk username login
   string password = "11";    //variabel untuk password login
   string login = "block";    //variabel untuk login
   i = 1;    
   
   do {        
       cout << "Username = "; cin>>user_input;        
       cout << "Password = "; cin>>pass_input;        
       if (user_input == username && pass_input == password) {    
           cout << "\n==========================================="<< endl;    
           cout << "|              Login Berhasil             |" << endl;            
           cout << "===========================================\n"<< endl;       
           i = 4;
           login = "berhasil";        } 
       else {            
           cout << "\n=========================================="<< endl;            
           cout << "|  Username / Password Anda Salah!   |("<<i<<"x)"<< endl;
		   cout << "==========================================\n"<< endl;            
           i = i +1;
       }   
    } while (i <= 3);
	
    if(login != "berhasil"){
       cout<<"Anda telah 3x salah login.\n";       
       cout<<"Silahkan coba lagi kalo mood. Terima Kasih..\n"<< endl;  
       return 0;    
	}   
   char lagi;
   int kode,pilih;
   float rupiah, dollar, euro, yen;
   awal:
//    system("cls");        
   cout << "===========================================" <<endl;  
   cout << "|      SILAHKAN KONVERSI mata uang        |" <<endl;    
   cout << "===========================================" <<endl;       
   cout << "|1. Rupiah => Dollar, Euro, Yen           |" <<endl;
   cout << "|2. Dollar => Rupiah, Euro, Yen           |" <<endl;
   cout << "|3. Euro => Rupiah, Dollar, Yen           |" <<endl;
   cout << "|4. Yen => Rupiah, Dollar, Euro           |" <<endl;
   cout << "===========================================\n";       
   cout<<endl;
   cout<<"Pilih  = ";
   cin>>kode;
   switch (kode)
   {
    case 1:
            cout<<"Masukkan Nominal dalam Rupiah = ";
            cin>>rupiah;
            dollar=rupiah*0.000064;
            euro=rupiah*0.00006;
            yen=rupiah*0.0096;
            cout<<"Rupiah dalam dollar = "<<dollar<<endl;
            cout<<"Rupiah dalam euro = "<<euro<<endl;
            cout<<"Rupiah dalam Yen = "<<yen<<endl;
            break;
    case 2:
            cout<<"Masukkan Nominal dalam Dollar = ";
            cin>>dollar;
            rupiah=dollar*16000;
            euro=dollar*0.9222;
            yen=dollar*150.3607;
            cout<<"Dollar dalam rupiah = "<<rupiah<<endl;
            cout<<"Dollar dalam euro = "<<euro<<endl;
            cout<<"Dollar dalam yen = "<<yen<<endl;
            break;
    case 3:
            cout<<"Masukkan Nominal dalam Euro = ";
            cin>>euro;
            rupiah=euro*17064.9629;
            dollar=euro*1.0845;
            yen=euro*163.0366;
            cout<<"Euro dalam Rupiah = "<<rupiah<<endl;
            cout<<"Euro dalam dollar = "<<dollar<<endl;
            cout<<"Euro dalam Yen = "<<yen<<endl;
            break;
    case 4:
            cout<<"Masukkan Nominal dalam Yen = ";
            cin>>yen;
            rupiah=yen*104.6921;
            dollar=yen*0.0067;
            euro=yen*0.0061;
            cout<<"Yen dalam Rupiah = "<<rupiah<<endl;
            cout<<"Yen dalam Dollar = "<<dollar<<endl;
            cout<<"Yen dalam Euro = "<<euro<<endl;
            break;
            default:
        cout<<"Kode tersebut tidak ada dalam menu"<<endl;
    }
   cout << "-----------------------------------------------\n";    
    cout<<"Apakah anda ingin mengkonversi yang lain? (Y/N)";
    cin>>lagi;
        if (lagi=='y' || lagi=='Y'){
                goto awal;
        }
        if (lagi=='n' || lagi=='N'){
                goto selesai;
        }
    selesai:
        cout << "==================================================="<< endl;   
        cout << "|              PROGRAM TELAH SELESAI              |"<< endl;   
        cout << "==================================================="<< endl;   
        cout << "| TERIMAKASIH TELAH MENGGUNAKAN PROGRAM SEDERHANA |"<< endl;   
        cout << "|                YANG DISUSUN OLEH                |"<< endl;   
        cout << "|           Chandra Adha Rezki Pahlawan           |"<< endl;   
        cout << "|                INFORMATIKA A'23                 |"<< endl;   
        cout << "|                   2309106011                    |"<< endl;   
        cout << "==================================================="<< endl;   
    return 0;
}