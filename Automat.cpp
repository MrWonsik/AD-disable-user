#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <unistd.h> //funkcja access - sprawdzanie czy folder istnieje

using namespace std;

main(){
string lokalizacja_profili = "\\\\ti-nas\\profiles\\";	

fstream plik;
string login;
string NazwaPliku = "dowylaczenia.txt";
string quota="\"";



plik.open(NazwaPliku.c_str(), ios::in);
	if(plik.good())
	{
		cout << "Otwarto plik! " << NazwaPliku << endl;
		plik.seekp(0,ios::beg);
		
		while(!plik.eof())
		{
			getline(plik, login);
			cout << "======================Dezaktywacja konta, zmiana opisu dla " <<login << ": " << endl << endl;		
			system(("net user "+login+" /active:no /domain").c_str());
			system(("net user "+login+" /comment:"+quota+"Nie pracuje"+quota + " /domain").c_str());
			
			cout << endl << endl << endl;
			
			string profilepathW7=(lokalizacja_profili+login+".V2").c_str();
			string profilepathW10=(lokalizacja_profili+login+".V6").c_str();
			
			const char * profilepath_OK = profilepathW7.c_str();
			if(access(profilepath_OK, F_OK)==0)
			{
				cout << "=========USUWANIE KATALOGU Z PROFILEM W7: " << endl;
				cout << ("rmdir /q /s \""+profilepathW7+"\"").c_str() << endl; 
				system(("rmdir /q /s \""+profilepathW7+"\"").c_str());
				cout << endl << endl << endl;
			}
			else
			{
				cout << "=========Nie istnieje katalog proiflu w systemie windows 7 dla tego uzytkownika" << endl;
				cout << endl << endl << endl;
			}
			
			const char * profilepath_OKW10 = profilepathW10.c_str();
			if(access(profilepath_OKW10, F_OK)==0)
			{
				cout << "=========USUWANIE KATALOGU Z PROFILEM W10: " << endl;
				cout << ("rmdir /q /s \""+profilepathW10+"\"").c_str() << endl; 
				system(("rmdir /q /s \""+profilepathW10+"\"").c_str());
				cout << endl << endl << endl;
			}
			else
			{
				cout << "============Nie istnieje katalog proiflu w systemie windows 10 dla tego uzytkownika" << endl;
				cout << endl << endl << endl;
			}
			
		
		}
		plik.close();
		
		system("Pause");
		plik.open(NazwaPliku.c_str(), ios::out);
		plik.close();

		
	}
	else 
	{
		cout << "Blad odczytu!" << endl;
	}


}








