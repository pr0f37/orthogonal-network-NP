/**
 * @file: main.cpp
 *
 * @date 2009-05-15
 * @author Adam Nowik
 */


#include "Includes.h"
#include "Para.h"
#include "Generator.h"
#include "Net.h"
#include "Timer.h"
using namespace std;


int main(int argc, char* argv[] ) {
	Generator gen;
	string name;
	Net myNet;
	Timer myTimer;
	vector <Para> kolejka;
	if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 't') {
		for (int i = 0; i < 10; i++) {
			if (i == 0)
				name = "test1";
			else if (i == 1)
				name = "test2";
			else if (i == 2)
				name = "test3";
			else if (i == 3)
				name = "test4";
			else if (i == 4)
				name = "test5";
			else if (i == 5)
				name = "test6";
			else if (i == 6)
				name = "test7";
			else if (i == 7)
				name = "test8";
			else if (i == 8)
				name = "test9";
			else if (i == 9)
				name = "test10";
			gen.setName(name);
			kolejka.clear();
			gen.readData(kolejka);
			myTimer.setStart();
			gen.mergeSort(kolejka);
			myNet.createNet(kolejka);
			myTimer.setEnd();
			myTimer.calculateTime(i);
			myTimer.calculateExactTime(i, kolejka.size());
			cout << "plik " << i << " przerobiony w czasie: " << myTimer.getTime(i) << "ms" << endl;
		}
		myTimer.calculateQ();
		myTimer.writeToFile();
	}
	else {
		int c = 10;
		do {
			cout << "1. Generuj n punktów i zapisz pliku" << endl;
			cout << "2. Załaduj punkty z pliku" << endl;
			cout << "3. Uruchom algorytm i wyświetl wyniki" << endl;
			cout << "Podaj liczbę:" << endl;
			cin >> c;
			switch (c) {
				case 0:
					break;
				case 1:
					cout << "Podaj nazwę pliku: (jeśli chcesz zostawić nazwę podaj 0)" << endl;
					cin >> name;
					if (name != "0")
					gen.setName(name);
					gen.generate();
					break;
				case 2:
					kolejka.clear();
					cout << "Podaj nazwę pliku: (jeśli chcesz zostawić nazwę podaj 0)" << endl;
					cin >> name;
					if (name != "0")
						gen.setName(name);
					gen.readData(kolejka);
					break;
				case 3:
					myTimer.setStart();
					gen.mergeSort(kolejka);
					myNet.createNet(kolejka);
					myTimer.setEnd();
					myTimer.calculateTime(0);
					cout << "czas: " <<  myTimer.getTime(0)  << " ms ilość punktów: " << (int)kolejka.size() << endl;
					myNet.drawNet(kolejka);
					break;
				default:
					cout << "Nie ma takiej opcji. Spróbuj jeszcze raz\n" << endl;
					fflush(stdin);
					sleep(1);
			}
		} while(c != 0);
		cout << "Koniec" << endl;

	}
		return 0;
}



