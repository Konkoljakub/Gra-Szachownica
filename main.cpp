#include <iostream>
#include <inttypes.h>
#include <fstream>
using namespace std;

uint32_t licznik_wej;
uint8_t licznik = 0 ;

uint8_t wektor = 0xAA ; //dla szyfrowania
uint8_t tekst;
uint8_t szyfr;
uint8_t bufor[16];
fstream szf;
fstream st; //

uint8_t u_bufor[16]; //dla odszyfrowywania
uint8_t u_tekst;

uint8_t zmienna_i;

int wybor;
int main ()
{
	cout<<"Podaj stan licznika: ";
	cin>>licznik_wej;
	licznik = licznik_wej;

	cout<<"Menu"<<endl;
	cout<<"1. Zaszyfruj"<<endl;
	cout<<"2. Odszyfruj"<<endl;
	cout<<"Twoj wybor: ";
	cin>>wybor;
		switch(wybor)
		{
			case 1:
	//			fstream st; 
			    st.open("text.txt",ios::in);   
			
			    if(!st)
			    {
			        cout<<"No such file";
			        return 0;
			    }
			    
			     szf.open("szyfr.txt",ios::out); 
			    if(!szf) 
			    {
			        cout<<"File creation failed";
			        return 0;
			    } 
			    
			    
				while (!st.eof()) //sprawdzenie pliku
				{
					for(int i = 0; i < 16; i++)
					{
						if(!st.eof())
							{
							bufor[i] = st.get();	//wpisuje do  komorek tabeli wartosci z pliku
							zmienna_i = i;
							}
						else 
						{
						
							break;
						}
					}
					if(st.eof())
					{
						for(int i = 0; i<zmienna_i; i++)
						{
							szyfr = (bufor[i]^wektor^licznik);	
							printf("tekst:%x ", bufor[i]);
							printf("licznik:%x ", licznik);
							printf("wektor:%x ", wektor); 
							printf("szyfr:%x ", szyfr); 
//							cout<<" "<<szyfr;
							cout<<i;
							cout<<endl;
							licznik++; //samo wraca do zera bo 256 bitow
							wektor = szyfr;
							szf<<szyfr;	
						}
						cout<<endl;
					}
					else 
					{
						for(int i = 0; i < 16; i++)
						{
						
							szyfr = (bufor[i]^wektor^licznik);	
							printf("tekst:%x ", bufor[i]);
							printf("licznik:%x ", licznik);
							printf("wektor:%x ", wektor); 
							printf("szyfr:%x ", szyfr); 
	//						cout<<" "<<szyfr;
							cout<<i;
							cout<<endl;
							licznik++; //samo wraca do zera bo 256 bitow
							wektor = szyfr;
							szf<<szyfr;	
	
						}
						cout<<endl;
					}
				}

				szf.close();
				st.close();
				break;
				
				
					//*********************************************UNCODING********************************************************************************//
			
			case 2: 
			
				fstream coded; //klasa zaszyfrowanego tekstu
			    coded.open("szyfr.txt",ios::in);  //otwieranie zaszyfrowanego pliku
			
			    if(!coded)
			    {
			        cout<<"No such file"; //przypadek braku pliku
			        return 0;
			    } 
			    fstream uncoded; //klasa odszyfrowanego tekstu
			    uncoded.open("uncoded.txt",ios::out); //utworzenie pliku z odszyfrowana zawartoscia
			    if(!uncoded) 
			    {
			        cout<<"File creation failed";
			        return 0;
			    } 
			    
				while(!coded.eof())
				{
					for(int i = 0; i < 16; i++)
					{
						if(!coded.eof())
						{
						u_bufor[i] = coded.get();
						zmienna_i = i;
						}
						else 
						{
							
							break;
						}
						
					}
					if(coded.eof())
					{
						for(int i = 0; i < zmienna_i; i++)
						{
							
								u_tekst = (u_bufor[i]^wektor^licznik);
								cout<<i<<" ";
								printf("u_szyfr:%x ", u_bufor[i]);
								printf("licznik:%x ", licznik);
								printf("wektor:%x ", wektor); 
								printf("u_tekst:%x ", u_tekst); 
								
								cout<<u_tekst<<endl;
								wektor = u_bufor[i];
								uncoded<<u_tekst;
								licznik++;	

						}
						cout<<endl;
					}
					else
					{
							for(int i = 0; i < 16; i++)
						{
							if(!coded.eof())
							{
								u_tekst = (u_bufor[i]^wektor^licznik);
								cout<<i<<" ";
								printf("u_szyfr:%x ", u_bufor[i]);
								printf("licznik:%x ", licznik);
								printf("wektor:%x ", wektor); 
								printf("u_tekst:%x ", u_tekst); 
								
								cout<<u_tekst<<endl;
								wektor = u_bufor[i];
								uncoded<<u_tekst;
								licznik++;	
							}
							else return 0;
						}
						cout<<endl;
					}
				}

							szf.close();
				st.close();
				break;
				
		}


	
	


	return 0;
}
