#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;

struct studentas
{
    string vardas;
    string pavarde;
    vector<int> paz;
    int egzaminas;
    double gal_rezultatas;
    double mediana;
};

studentas stud_iv();
void spausdinti_grupe(vector<studentas>& grupe);
int main()
{
    srand(time(0));

    vector<studentas> grupe;
    int pasirinkimas;

    do
    {
        cout << "Ka norite atlikti?"<<endl;
        cout << "1. Ivesti nauja studenta"<<endl;;
        cout << "2. Atspausdinti rezultatus"<<endl;
        cout << "3. Iseiti"<<endl;
        cout << "Pasirinkite veiksma: "<<endl;
        cin >> pasirinkimas;

        switch (pasirinkimas)
        {
        case 1:
            grupe.push_back(stud_iv());
            break;
        case 2:
            spausdinti_grupe(grupe);
            break;
        case 3:
            cout << "Pabaiga."<<endl;
            break;
        default:
            cout << "Neteisingas pasirinkimas."<<endl;
        }

    }
    while (pasirinkimas != 3);

    return 0;
}

studentas stud_iv()
{
    studentas pirmas;
    int sum = 0, n = 0;
    int laik_paz;

    cout << "Iveskite studento duomenis"<<endl;
    cout << "Vardas: "<<endl;
    cin >> pirmas.vardas;
    cout << "Pavarde: "<<endl;
    cin >> pirmas.pavarde;

    int generuoti;
    cout << "Ar pazymius generuoti atsitiktinai? (1 - generuoti, 0 - vesti ranka): "<<endl;
    cin >> generuoti;

    if (generuoti == 1)
    {
        int kiek = rand() % 6 + 5; // 5-10 pazymiu
        for (int i = 0; i < kiek; i++)
        {
            int random_paz = rand() % 10 + 1; // 1-10
            pirmas.paz.push_back(random_paz);
            sum += random_paz;
            n++;
        }
        pirmas.egzaminas = rand() % 10 + 1;
    }
    else
    {
        int kl;
        cout<<"Ar zinote, kiek pazymiu turi "<<pirmas.vardas<<" "<<pirmas.pavarde<<"?"<<" Taip - 1, ne - 0."<<endl;
        cin>>kl;

        if (kl==0)
        {
            int laik_paz = -1;
            while (laik_paz != 0)
            {
                cout << "Jei daugiau pazymiu studentas neturi, iveskite 0, kitu atveju iveskite pazymi: ";
                cin >> laik_paz;
                pirmas.paz.push_back(laik_paz);
                sum += laik_paz;
                n++;
            }
            cout << "Iveskite egzamino pazymi: ";
            cin >> pirmas.egzaminas;
        }
        else
        {
            cout<<"Kiek pazymiu turi " <<pirmas.vardas<<" "<<pirmas.pavarde<<" ";
            cin>>n;
            for (int a=0; a<n; a++)
            {
                cout<<a+1<<": ";
                cin >>laik_paz;
                pirmas.paz.push_back(laik_paz);
                sum+=laik_paz;  //alternatyva sum+=pirmas.paz[a]
            }
            cout<<"Iveskite egzamino pazymi: ";
            cin>>pirmas.egzaminas;

        }
    }

    // Galutinis rezultatas (vidurkis)
    pirmas.gal_rezultatas = double(sum) / double(n) * 0.4 + pirmas.egzaminas * 0.6;

    // Mediana
    vector<int> paz_temp = pirmas.paz;
    paz_temp.push_back(pirmas.egzaminas);
    sort(paz_temp.begin(), paz_temp.end());
    int kiek = paz_temp.size();
    if (kiek % 2 != 0) pirmas.mediana = double(paz_temp[kiek / 2]);
    else pirmas.mediana = double(paz_temp[(kiek - 1) / 2] + paz_temp[kiek / 2]) / 2.0;

    return pirmas;
}

void spausdinti_grupe(vector<studentas>& grupe)
{
    if (grupe.empty())
    {
        cout << "Nera studentu"<<endl;
        return;
    }

    cout << setw(10) << left << "Vardas" << "|"
         << setw(15) << right << "Pavarde" << "|"
         << setw(20) << right << "Galutinis (Vid.)" << "|"
         << setw(20) << right << "Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------------------------"<<endl;

    for (auto& stud : grupe)
    {
        cout << setw(10) << left << stud.vardas << "|"
             << setw(15) << right << stud.pavarde << "|"
             << fixed << std::setprecision(2) << setw(20) << right << stud.gal_rezultatas << "|"
             << fixed << std::setprecision(2) << setw(20) << right << stud.mediana << endl;
    }
}
