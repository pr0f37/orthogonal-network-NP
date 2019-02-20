/**
 * @file Net.h
 * Plik naglowkowy klasy Net.
 * Zawiera definicje ciala klasy Net oraz prototypy metod tej klasy.
 * @date 2009-06-03
 * @author Adam Nowik
 */

#ifndef NET_H_
#define NET_H_
#include "Includes.h"
#include "Para.h"

/**
 * 	Klasa Net umozliwia tworzenie minimalnej ortogonalnej sieci pomiedzy zbiorem punktow na plaszczyznie.
 * 	@sa Para
 */
class Net {
private:
	/**
	 * 	Lista punktow bedacych wierzcholkami krat typu manhattan pomiedzy punktami dla ktorych klasa Net
	 * 	tworzy minimalna ortogonalna siec sciezek. Punkty na tej liscie posiadaja taka sama wspolrzedna X
	 * 	co punkt dla ktorego rozpinamy siec.
	 * 	@sa Para
	 */
	vector<Para> xList;
	/**
	 * 	Lista punktow bedacych wierzcholkami krat typu manhattan pomiedzy punktami dla ktorych klasa Net
	 * 	tworzy minimalna ortogonalna siec sciezek. Punkty na tej liscie posiadaja taka sama wspolrzedna Y
	 * 	co punkt na ktorego rozpinamy siec.
	 * 	@sa Para
	 */
	vector<Para> yList;
	/**
	 * 	Punkt, dla ktorego rozpinamy siec.
	 * 	@sa Para
	 */
	Para activePoint;
	/**
	 * 	Najblizszy punkt w sieci pomiedzy punktem aktywnym a aktualnie badanym podczas rozpinania sieci punktem.
	 * 	@sa Para
	 */
	Para nearestPoint;
	/**
	 * 	Najblizszy punkt wsrod punktow z list xList i yList dla punktu activePoint.
	 *	@sa Para
	 *	@sa xList
	 *	@sa yList
	 */
	Para nearestPointInList;
	/**
	 *	Lista punktow przechowujaca odcinki sieci (kazde dwa sasiednie punkty to poczatek i koniec odcinka)
	 * 	@sa Para
	 */
	vector<Para> net;

public:
	/**
	 * 	Konstruktor domyslny obiektu klasy Net.
	 */
	Net();
	/**
	 * 	Destruktor obiektu klasy Net.
	 */
	~Net();
	/**
	 * 	Metoda tworzaca minimalna ortogonalna siec dla listy punktow podanych jako parametr.
	 * 	@param vector <Para>& referencja na liste punktow.
	 *	@sa Para
	 */
	void createNet(vector <Para>&);
	/**
	 * 	Metoda sprawdzajaca czy przez dwa punkty mozna poprowadzic ortogonalna linie prosta.
	 * 	@param Para& referencja na pierwszy punkt dla ktorego jest badane istnienie ortogonalnej linii prostej.
	 * 	@param Para& referencja na drugi punkt dla ktorego jest badane istnienie ortogonalnej linii prostej.
	 * 	@return True jesli mozna utworzyc linie prosta, false jesli utworzenie linii jest niemozliwe.
	 * 	@sa Para
	 */
	bool isLine(Para&, Para&);
	/**
	 * 	Metoda sprawdzajaca czy punkt podany jako pierwszy parametr lezy na odcinku utworzonym przez punkty podane
	 * 	jako parametry drugi i trzeci.
	 * 	@param Para& referencja na pierwszy punkt.
	 * 	@param Para& referencja na drugi punkt.
	 * 	@param Para& referencja na trzeci punkt.
	 * 	@return True jesli punkt lezy na odcinku utworzonym przez punkty drugi i trzeci, false jesli lezy poza tym odcinkiem.
	 * 	@sa Para
	 */
	bool isBetween(Para&, Para&, Para&);
	/**
	 * 	Metoda znajdujaca i zwracajaca punkt znajdujacy sie najblizej punktu podanego jako parametr.
	 * 	@param Para& referencja na punkt, dla ktorego poszukiwany jest punkt najblizszy znajdujacy sie w sieci.
	 * 	@return Para punkt znajdujacy sie w sieci, polozony najblizej punktu podanego jako parametr.
	 * 	@sa Para
	 */
	Para findNearest(Para&);
	/**
	 * 	Metoda znajdujaca w listach xList i yList punkt znajdujacy sie najblizej punktu podanego jako parametr.
	 * 	@param Para& referencja na punkt dla ktorego poszukiwany jest punkt najblizszy sposrod punktow z xList i yList.
	 * 	@sa Para
	 * 	@sa xList
	 * 	@sa yList
	 */
	void findNearestInLists(Para&);
	/**
	 * 	Metoda tworzaca sciezke pomiedzy punktami wywolujaca sie rekurencyjnie
	 * 	@param vector <Para>& referencja na liste punktow dla ktorych tworzona jest siec.
	 * 	@param Para& referencja na punkt od ktorego tworzone sa polaczenia do nastepnych punktow w sieci.
	 * 	@param int numer elementu sieci od ktorego tworzone sa polaczona od badanego punktu
	 * 	@sa Para
	 */
	void createRoute(vector <Para>&, Para&, int);
	/**
	 * 	Metoda rysujaca siec w pliku SVG (tworzaca plik i parsujaca go).
	 * 	@param vector <Para>& lista punktow miedzy ktorymi rysowana jest siec.
	 * 	@sa Para
	 */
	void drawNet(vector <Para>&);
};

#endif /* NET_H_ */
