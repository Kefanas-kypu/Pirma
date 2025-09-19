#include <iostream>
#include <iomanip> //nes reikia setw, left, right
#include <vector>
#include <string>
#include <algorithm>


using namespace std;//komanda privercia kompiliatoriu ziureti i ...
//nepataria naudoti using namespace std;
//patogu, bet jei naudosim kitus kintamuosius, tai tada gali susigadinti
//pataria naudoti using std::cout;
//taip pat su visais pvz cin, endl;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;

//struktura aprasoma rasant struct
struct studentas{
    string vardas;
    string pavarde;
    vector <int> paz; //kadangi saugosiu masyvus, tai reikia
    int egzaminas;
    double gal_rezultatas;//galima naudoti ir double, pagal nora ir reikala. galutinis pazymys sveikas, todel int
    double mediana;
    };
 studentas stud_iv();

int main(){
    vector<studentas> grupe;
    cout<<"Kiek studentu grupeje? ";
    int m;
    cin>>m;
    for(auto z=0;z<m;z++)
      grupe.push_back(stud_iv());
//    studentas pastovus;
//    pastovus = stud_iv();
    cout<<setw(10)<<left<<"Vardas"<<"|"<<setw(15)<<right<<"Pavarde"<<"|"<<setw(20)<<right<<"Galutinis (Vid.)"<<"|"<<setw(20)<<right<<"Galutinis (Med.)"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    for (auto pastovus:grupe)
    {
        cout<<setw(10)<<left<<pastovus.vardas<<"|"<<setw(15)<<right<<pastovus.pavarde<<"|";
        // for (auto& a : pastovus.paz) cout<<setw(5)<<a<<"|";
        cout/*<<setw(5)<<pastovus.egzaminas<<"|"*/<<fixed<<setprecision(2)<<setw(20)<<right<<pastovus.gal_rezultatas<<"|";
        cout<<fixed<<setprecision(2)<<setw(20)<<right<<pastovus.mediana<<endl;
    }
    }
    //mes turim viena studenta. mums reikia kazkokio ciklo, kad butu daugiau studentu. sugalvoti kaip suvesti, ka padaryti.
    studentas stud_iv(){
        int n, laik_paz, sum=0;
        cout<<"Sveiki"<<endl;
        studentas pirmas;
        cout<<"Ivesk studento duomenis"<<endl;
        cout<<"Vardas: "; cin>>pirmas.vardas;
        cout<<"Pavarde: "; cin>>pirmas.pavarde;
        cout<<"Kiek pazymiu turi " <<pirmas.vardas<<" "<<pirmas.pavarde<<" "; cin>>n;
        for (int a=0;a<n;a++)
        {
            cout<<a+1<<": "; cin >>laik_paz;
            pirmas.paz.push_back(laik_paz);
            sum+=laik_paz;  //alternatyva sum+=pirmas.paz[a]
        }
        cout<<"Iveskite egzamino paz: "; cin>>pirmas.egzaminas;
        pirmas.gal_rezultatas= double(sum)/double(n) * 0.4 + pirmas.egzaminas * 0.6; //kazkodel reikia parasyti double

        // medianos radimas
        vector <int> paz_temp = pirmas.paz; // laikinas pazymiu vektorius, kad butu galima medianos skaiciavimui panaudoti ir egzamino rezultata
        paz_temp.push_back(pirmas.egzaminas);
        int kiek = paz_temp.size();
        sort(paz_temp.begin(),paz_temp.end());
        if(kiek%2 != 0) pirmas.mediana = (double)paz_temp[kiek / 2];
            else pirmas.mediana = (double)(paz_temp[(kiek - 1) / 2] + paz_temp[kiek / 2]) / 2.0;

        return pirmas;

    }
