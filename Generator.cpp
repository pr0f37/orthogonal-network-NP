/**
 * @file Generator.cpp
 * Plik zawierajacy implementacje metod klasy Generator.
 * Klasa Generator sluzy do generowania, wczytywania i sortowania danych.
 * @date 2009-06-03
 * @author Adam Nowik
 */
#include "Includes.h"
#include "Generator.h"
#include "Para.h"
Generator::Generator() {
	nazwa = "plik.txt";
}

Generator::Generator(string name) {
	nazwa = name + ".txt";
}

Generator::~Generator() {
}

void Generator::setName(string name) {
	nazwa = name + ".txt";
}

void Generator::generate(){
	ofstream out(&nazwa[0]);
	srand((unsigned)time(NULL));
	int n = rand() % MAKS_N;
	n = (n + 1) * 2; // zapewniam parzysta liczbe wylosowanych liczb (i różna od 0)
	int los;
	for (int i = 0; i < n; i++) {
		los = rand() % MAKS_J;
		out << los << "\n";
	}
	out.flush();
	out.close();
}

void Generator::readData(vector<Para>& kolejka) {
	ifstream in(&nazwa[0]);
	int i,j;
	if (in != NULL) {
		while (!in.eof()) {
				in >> i;
				in >> j;
				Para dod(i,j);
				kolejka.push_back(dod);
			}
		kolejka.pop_back();
		in.close();
	} else
		cout << "Podano zla nazwe pliku" << endl;
}

void Generator::mergeSort(vector<Para>& pomoc){
	vector<Para> A;
	vector<Para> B;
	if ((int)pomoc.size() > 1) {
		for (int i = 0; i < (int)(pomoc.size() / 2); i++) {
			A.push_back(pomoc.at(i));
		}
		for (int i = (int)(pomoc.size() / 2); i < (int)(pomoc.size()); i++) {
			B.push_back(pomoc.at(i));
		}
	}
	if ((int)A.size() > 1)
		mergeSort(A);
	if ((int)B.size() > 1)
		mergeSort(B);
	pomoc.clear();
	int i = 0;
	int j = 0;
	while (i < (int)A.size() && j < (int)B.size()) {
		if (A.at(i) <= B.at(j)) {
			pomoc.push_back(A.at(i));
			i++;
		} else {
			pomoc.push_back(B.at(j));
			j++;
		}
	}
	if (i < (int)A.size()) {
		while(i < (int)A.size()) {
			pomoc.push_back(A.at(i));
			i++;
		}
	} else if (j < (int)B.size())
			while(j < (int)B.size()) {
				pomoc.push_back(B.at(j));
				j++;
			}
}

