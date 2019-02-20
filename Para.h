/**
 * @file Para.h
 * Plik naglowkowy klasy Para.
 * Plik zawiera definicje ciala klasy Para, oraz prototypy metod tej klasy.
 * @date 2009-06-03
 * @author Adam Nowik
 */

#ifndef PARA_H_
#define PARA_H_
#include "Includes.h"
/**
 * Klasa Para sluzy do tworzenia obiektow przechowujacych pary liczb, ktore reprezentuja punkt na plaszczyznie.
 * Miedzy obiektami tej klasy rozpinana jest minimalna ortogonalna siec polaczen.
 * @sa Net
 */
class Para {
private:
	/**
	 * Wspolrzedna X punktu.
	 */
	int x;
	/**
	 * Wspolrzedna Y punktu.
	 */
	int y;
public:
	/**
	 * Konstruktor domyslny obiektu klasy Para
	 */
	Para();
	/**
	 * Konstruktor dwuargumentowy obiektu klasy Para.
	 * Tworzy obiekt klasy para o wspolrzednych rownych liczbom calkowitym przekazanym jako parametry.
	 * @param int wspolrzedna X.
	 * @param int wspolrzedna Y.
	 */
	Para(int, int);
	/**
	 * Destruktor obiektu klasy Para.
	 */
	~Para();
	/**
	 * Metoda zwracajaca wspolrzedna X obiektu.
	 * @return int wspolrzedna X.
	 */
	int getX();
	/**
	 * Metoda zwracajaca wspolrzedna Y obiektu.
	 * @return int wspolrzedna Y.
	 */
	int getY();
	/**
	 * Metoda ustawiajaca wspolrzedna X obiektu, na wartosc przekazana jako parametr.
	 * @param int wspolrzedna X.
	 */
	void setX(int);
	/**
	 * Metoda ustawiajaca wspolrzedna Y obiektu, na wartosc przekazana jako parametr.
	 * @param int wspolrzedna Y.
	 */
	void setY(int);
	/**
	 * Przeciazany operator == dla obiektow typu Para.
	 * @return True jesli wspolrzedne X i Y dwoch punktow sa takie same, false w przeciwnym przypadku.
	 */
	bool operator==(const Para&);
	/**
	 * Przeciazany operator != dla obiektow typu Para.
	 * @return True jesli wspolrzedne X lub Y dwoch punktow sa rozne, false w przeciwnym przypadku.
	 */
	bool operator!=(const Para&);
	/**
	 * Przeciazany operator < dla obiektow typu Para.
	 * @return True jesli lewy operand operatora jest mniejszy niz prawy (ma mniejsza wspolrzedna X,
	 * lub rowna wspolrzedna X i mniejsza wspolrzedna Y), false w przeciwnym przypadku.
	 */
	bool operator<(const Para&);
	/**
	 * Przeciazany operator > dla obiektow typu Para.
	 * @return True jesli lewy operand operatora jest wiekszy niz prawy (ma wieksza wspolrzedna X,
	 * lub rowna wspolrzedna X i wieksza wspolrzedna Y), false w przeciwnym przypadku.
	 */
	bool operator>(const Para&);
	/**
	 * Przeciazany operator <= dla obiektow typu Para.
	 * @return True jesli lewy operand jest mniejszy lub rowny prawemu operandowi, false w przeciwnym przypadku.
	 */
	bool operator<=(const Para&);
};

#endif /* PARA_H_ */
