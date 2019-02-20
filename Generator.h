/**
 * @file Generator.h
 * Plik naglowkowy klasy Generetor.
 * Plik zawiera definicje ciala klasy Generator, oraz prototypy metod tej klasy.
 * @date 2009-06-03
 * @author Adam Nowik
 */

#ifndef GENERATOR_H_
#define GENERATOR_H_
#include "Includes.h"
#include "Para.h"
	/**
	 * Obiekty klasy Generator odpowiedzialne sa za tworzenie plikow zawierajacych parzysta, losowa liczbe
	 * losowo wygenerowanych liczb calkowitych, odczytywanie ich i na ich podstawie tworzenie list punktow
	 * o losowych wspolrzednych, obiekty te maja takze mozliwosc sortowania list punktow (za pomoca algorytmu Merge-Sort).
	 */
class Generator {
private:
	/**
	 * Nazwa pliku na ktorym ma dzialac obiekt klasy Generator.
	 */
	string nazwa;
public:
	/**
	 * Konstruktor domyslny obiektow klasy Generator.
	 */
	Generator();
	/**
	 * Konstruktor jednoargumentowy klasy Generator.
	 * Obiekt utworzony za pomoca tego generatora bedzie dzialal na pliku o nazwie przekazanej jako parametr.
	 * @param string nazwa pliku.
	 */
	Generator(string);
	/**
	 * Destruktor obiektu klasy Generator.
	 */
	~Generator();
	/**
	 * Metoda ustawiajaca parametr nazwa na wartosc podana jako parametr. Generator bedzie dzialal na pliku o takiej nazwie.
	 * @param string nazwa pliku.
	 * @sa nazwa
	 */
	void setName(string);
	/**
	 * Metoda sluzaca generacji parzystej, losowej liczby wartosci calkowitych i zapisaniu jej do pliku o nazwie przekazywanej
	 * jako parametr.
	 * @sa nazwa
	 */
	void generate();
	/**
	 * Metoda sluzaca do odczytu danych z pliku o nazwie przechowywanej w atrybucie nazwa. I umieszczenia ich jako listy punktow
	 * w obiekcie klasy vector<Para> do ktorego referencja przekazywana jest jako parametr.
	 * @param vector <Para>& referencja na liste do ktorej maja byc zapisane dane z pliku.
	 * @sa nazwa
	 * @sa Para
	 */
	void readData(vector <Para>&);
	/**
	 * Metoda slozaca do sortowania punktow za pomoca algorytmu Merge-Sort, na liscie punktow przekazanej jako parametr.
	 * @param vector <Para>& referencja na liste na ktorej dane maja byc posortowane.
	 * @sa Para
	 */
	void mergeSort(vector<Para>&);
};
#endif /* GENERATOR_H_ */
