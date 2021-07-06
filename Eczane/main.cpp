//
//  main.cpp
//  Eczane
//
//  Created by Yusuf Öztürk on 7.05.2021.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Ilac{
    friend class Eczn;
public:
    Ilac(){         //Default Constructor

    };
    Ilac(int id, int sayi, double fiyat, string isim){  //Constructor with Arguments
        ilac_id=id;
        ilac_isim=isim;
        ilac_sayisi=sayi;
        ilac_fiyati=fiyat;
    }
    Ilac(const Ilac &obj){      //copy Constructor
        ilac_id=obj.ilac_id;
        ilac_isim=obj.ilac_isim;
        ilac_sayisi=obj.ilac_sayisi;
        ilac_fiyati=obj.ilac_fiyati;
    }
    Ilac& operator=(const Ilac &obj){ //Copy Assignment Operator
        ilac_id=obj.ilac_id;
        ilac_isim=obj.ilac_isim;
        ilac_sayisi=obj.ilac_sayisi;
        ilac_fiyati=obj.ilac_fiyati;
        return *this;
    }
    
    //Getter ve Setter Fonksiyonları
    int getIlacId(){
        return ilac_id;
    }
    void setIlacId(int id){
        ilac_id=id;
    }
    int getIlacSayi(){
        return ilac_sayisi;
    }
    void setIlacSayi(int sayi){
        ilac_sayisi=sayi;
    }
    double getIlacFiyat(){
        return ilac_fiyati;
    }
    void setIlacFiyat(double fiyat){
        ilac_fiyati=fiyat;
    }
    string getIlacIsim(){
        return ilac_isim;
    }
    void setIlacIsim(string isim){
        ilac_isim=isim;
    }
    
    void ilac_olustur(){    //İlaç objelerini oluşturan fonksiyon
        Ilac ilac[0];
        int sayiI;
        double fiyatI;
        string isimI;
        int k;
        cout<<"Kaç adet ilaç girişi yapacağınızı yazınız.\n"<<endl; //İstenilen ilaç adedi kadar obje oluşturur.
        cin>>k;
        for(int j=0;j<k;j++){
            
            ilac[j].setIlacId(j);
            cout<<"Isim: \n"<<endl;
            cin>>isimI;
            ilac[j].setIlacIsim(isimI);
            cout<<"Sayı: \n"<<endl;
            cin>>sayiI;
            ilac[j].setIlacSayi(sayiI);
            cout<<"Fiyat: \n"<<endl;
            cin>>fiyatI;
            ilac[j].setIlacFiyat(fiyatI);
            ilac[j].ilac_ekle(&ilac[j]);
            cout<<"İlaç eklendi"<<endl;
        }
    }
    void ilac_goster(Ilac obj[]){   //Dosyadan ID yardımıyla ilaç bulur ve ekrana yazdırır.
        int i;
        ifstream file;
        file.open("ilac.dat");
        cout<<"Görmek istediğiniz ilacın ID bilgisini giriniz."<<endl;
        cin>>i;
        file.read((char*)&obj[i],sizeof(obj[i]));
        cout<<"\n Ilac id:"<<obj[i].getIlacId()<<endl;
        cout<<"\nİsim:"<<obj[i].getIlacIsim()<<endl;
        cout<<"\n Sayı:"<<obj[i].getIlacSayi()<<endl;
        cout<<"\n Fiyat:"<<obj[i].getIlacFiyat()<<"\n"<<endl;;
      
            
    }
    void ilac_duzenle(); //Unutup main içerisinde yazmışım. Vaktim kalmadığı için düzeltemiyorum.
   
    
    void ilac_ekle(Ilac obj[]){ //Gelen objeyi dosyaya yazar.
        ofstream file_obj;
        file_obj.open("ilac_listesi.dat");
        file_obj.write((char*)&obj[0], sizeof(obj[0]));
    }

    
private:
    int ilac_id;
    int ilac_sayisi;
    double ilac_fiyati;
    string ilac_isim;
};


class Eczn{ //Eczane Sınıfı
    
    friend class Ilac;
public:
    Eczn(){
}       //default constructor
    Eczn(int id, string isim, string adres, Ilac ilac1){ //const with arg
        
        eczn_id=id;
        eczn_isim=isim;
        eczn_adres=adres;
        ilac=ilac1;
    }
    Eczn(const Eczn& obj){      //copy constructor
        eczn_id=obj.eczn_id;
        eczn_isim=obj.eczn_isim;
        eczn_adres=obj.eczn_adres;
    }
    Eczn& operator=(const Eczn& obj){ //Assignment operator
        eczn_id=obj.eczn_id;
        eczn_isim=obj.eczn_isim;
        eczn_adres=obj.eczn_adres;
        return *this;
    }
    //Getter ve Setter Fonksiyonları
    void setEcznId(int id){
        eczn_id=id;
    }
    int getEcznId(){
        return eczn_id;
    }           //getter setterlar
    
    void setEcznIsim(string isim){
        eczn_isim=isim;
    }
    string getEcznIsim(){
        return eczn_isim;
    }
    
    string getEcznAdres(){
        return eczn_adres;
    }

    void setEcznAdres(string adres){
        eczn_adres=adres;
    }
    
    //İstenilen eczane sayısı kadar eczane objesi oluşturur. Objenin içerisinde ilaç instanceları bulunur.
    void eczn_olustur(){
        string isimE;
        string adresE;
        int i=0;
        int k;
        Eczn eczn[4];
        cout<<"Kaç adet eczane kaydedeceğinizi giriniz. "<<endl;
        cin>>k;
        for(i=0;i<k;i++){
            eczn[i].setEcznId(i); //id otomatik
            cout<<"İsim:  \n"<<endl;
            cin>>isimE;
            eczn[i].setEcznIsim(isimE);
            cout<<"Adresi giriniz. \n"<<endl;
            cin>>adresE;
            eczn[i].setEcznAdres(adresE);
            eczn[i].ilac.ilac_olustur();
            eczn[i].eczn_ekle(&eczn[i]);
        }}
    void eczn_ilac_sayfasi();
    
    
    void eczn_ekle(Eczn obj[]){         //Gelen objeyi dosyaya yazar
        ofstream file_obj;
        file_obj.open("eczane_listesi.dat",ios::app);
        file_obj.write((char*)&obj[0], sizeof(obj[0]));
        file_obj.close();
     
    }
    void eczaneleri_goster(Eczn obj[]){     //Obje arraylerini for kullanarak okur.
        int i;
        ifstream file2;
        file2.open("eczane_listesi.dat",ios::in);
        for(i=0;i<4;i++){
        file2.read((char*)&obj[i],sizeof(obj[i]));
            cout<<"\nEczane id:"<<obj[i].getEcznId();
            cout<<"İsim: \n"<<obj[i].getEcznIsim();
            cout<<"\n Adres:"<<obj[i].getEcznAdres();
            
        }}

    void eczane_goster(){       //Kelimeye göre arama yapıp, kelimenin bulunduğu o satırı ekrana yazdırır
        string search,line;
        ifstream inFile;
        inFile.open("eczane_listesi.dat");
    cout << "Aramak istediğiniz eczaneyi yazınız. "<<endl;
    cin>>search;
        size_t pos;
        while(inFile.good())
          {
              getline(inFile,line); // get line from file
              pos=line.find(search); // search
          }
        cout<<line;
    }
    
    
    
    
private:
    Ilac ilac;      //ilac instance'ı
    int eczn_id;
    string eczn_isim;
    string eczn_adres;
};

int main(int argc, const char * argv[]) {
    Eczn eczane[4];
    Ilac ilac[10];
    int choice;
    int choice2;
    int sifre= 1234;
    int inputSifre;
    
    
    while(true){
    cout<<"Lütfen bir seçim yapınız. \n 1.Eczane Girişi \n 2.Müşteri Girişi \n 3. Çıkış"<<endl;; //Ana menü
    cin>>choice;
    { switch(choice){
            case 1:{
                cout<<"Lütfen şifreyi giriniz. \n"<<endl;
                cin>>inputSifre;
                if(inputSifre==sifre){
                
                    cout<<"1.Eczane Listesi Oluştur\n 2.Eczane Ekle \n 3.İlaç Ekle \n 4.İlaç Düzenle\n 5. Çıkış\n"<<endl; //1.Alt menü
                    cin>>choice2;
                    switch (choice2) {

                        case 1:{
                            eczane[0].eczn_olustur();
                            eczane[0].eczn_ekle(&eczane[0]);

                            break;}
                        case 2:{
                            eczane[0].eczn_olustur();
                            eczane[0].eczn_ekle(&eczane[0]);
                            break;}
                        case 3:{
                            
                            int sayiI;
                            double fiyatI;
                            string isimI;
                            int k;
                            cout<<"Kaç adet ilaç girişi yapacağınızı yazınız.\n"<<endl;
                            cin>>k;
                            for(int j=0;j<k;j++){
                                
                                ilac[j].setIlacId(j);
                                cout<<"Isim: \n"<<endl;
                                cin>>isimI;
                                ilac[j].setIlacIsim(isimI);
                                cout<<"Sayı: \n"<<endl;
                                cin>>sayiI;
                                ilac[j].setIlacSayi(sayiI);
                                cout<<"Fiyat: \n"<<endl;
                                cin>>fiyatI;
                                ilac[j].setIlacFiyat(fiyatI);
                                cout<<"İlaç eklendi"<<endl;
                                ilac[j].ilac_ekle(&ilac[j]);
                                ilac[j].ilac_goster(&ilac[j]);
                            }
                            cout<<"İlaç eklendi"<<endl;
                            
                        break;}
                        case 4:
                        {
                            int id;
                            int choice3;
                            cout<<"Düzenlemek istediğiniz ilacın ID bilgisini giriniz."<<endl;
                            cin>>id;
                            cout<<"Düzenlemek istediğiniz bilgiyi seçiniz.\n 1.İsim\n 2.Sayı \n 3.Fiyat \n"<<endl;
                            cin>>choice3;
                            switch (choice3) {
                                case 1:{
                                    string isim;
                                    cout<<"Lütfen yeni ismi giriniz.\n"<<endl;
                                    ilac[id].setIlacIsim(isim);
                                    
                                    break;}
                                case 2:{
                                    int sayi;
                                    cout<<"Lütfen yeni sayıyı giriniz.\n"<<endl;
                                    cin>>sayi;
                                    ilac[id].setIlacSayi(sayi);
                                    break;}
                                case 3:{
                                  double fiyat;
                                    cout<<"Lütfen yeni fiyatı giriniz.\n"<<endl;
                                    cin>>fiyat;
                                    ilac[id].setIlacFiyat(fiyat);
                                    
                                    
                                    
                                break;}
                                    
                            }
                                    
                              
                            }
                        default:{
                        break; }
                    }//switchi kapattı
                    
                        
                        break; }//ifi kapattı
                else{
                    cout<<"Şifre yanlış"<<endl;
                    break; }
                    
                    break;}//case1'i kapattı
                
            case 2:{
                int choice4;
                cout<<" 1.İlaç Ara\n 2.Eczane Listele \n 3.Herhangi Bir Eczaneyi Göster \n 4.Herhangi bir Eczaneye Ait İlaç Listesi\n 5. Çıkış\n"<<endl; //2. Alt menü
                cin>>choice4;
               
                    switch(choice4){
                            case 1:
                            cout<<"Yapılacak"<<endl;
                            
                            case 2:
                            eczane[0].eczaneleri_goster(&eczane[0]);
                            
                            case 3:
                            eczane[0].eczane_goster();
                        case 4:
                            cout<<"Yapılacak"<<endl;
                        case 5:
                            break;
                    }
            }}}}
    
    
    return 0;
}


