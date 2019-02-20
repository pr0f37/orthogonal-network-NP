/**
 * @file Timer.h
 * Plik zawierajacy definicje ciala kalsy Timer, oraz prototypu jej metod
 * Obiekty klasy timer pozwalaja na rejestracje czasu dzialania algorytmu wyznaczania minimalnej ortogonalnej sieci
 * oraz wyliczenie zlozonosci algorytmu.
 * @date 2009-06-08
 * @author Adam Nowik
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "Includes.h"
	/**
	 * Klasa Timer pozwala na tworzenie obiektow rejestrujacych czasy oraz wyliczajacych zlozonosc algorytmu
	 * tworzenia minimalnej ortogonalnej sieci polaczen.
	 */
class Timer {
private:
	/**
	 * Tablica czasow (w milisekundach) trwania dzialania algorytmu wyznaczania sieci.
	 */
	double timetab[10];
	/**
	 * Rejestruje chwile, z ktora startuje algorytm wyznaczania sieci.
	 */
	timeval start;
	/**
	 * Rejestruje chwile, z ktora algorytm wyznaczania sieci konczy swoje dzialanie.
	 */
	timeval end;
	/**
	 * Tablica dokładnych czasów trwania algorytmu.
	 */
	double etimetab[10];
	/**
	 * Tablica q.
	 */
	double qtab[10];
	/**
	 * Tablica przechowujaca ilosc punktow dla jakiej uruchomiono algorytm.
	 */
	int amount[10];
public:
	/**
	 * Konstruktor domyslny obiektu typu Timer.
	 */
	Timer();
	/**
	 * Destruktor obiektu typu Timer.
	 */
	~Timer();
	/**
	 * Zarejestrowanie chwili startu algorytmu.
	 */
	void setStart();
	/**
	 * Zarejestrowanie chwili zakonczenia algorytmu.
	 */
	void setEnd();
	/**
	 * Metoda zwracajaca wartosc czasu trwania algorytmu spod indeksu podanego jako parametr.
	 * @param int wartosc indeksu spod ktorego zwracany jest czas algorytmu.
	 * @return double czas algorytmu (w milisekundach)
	 */
	double getTime(int);
	/**
	 * Obliczenie czasu trwania algorytmu. Zapisanie wartosci w tablicy timetab.
	 * @param int indeks pod ktorym zapisywany jest czas trwania.
	 */
	void calculateTime(int);
	/**
	 * Obliczenie T(n)
	 * @param int indeks do którego zostanie zapisany T(n)
	 * @param int ilość punktów dla jakiej uruchomiono algorytm.
	 */
	void calculateExactTime(int, int);
	/**
	 * Obliczenie q
	 */
	void calculateQ();
	/**
	 * Zapisanie wyników pomiarów do pliku
	 */
	void writeToFile();
};

#endif /* TIMER_H_ */
