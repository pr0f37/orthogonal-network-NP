/**
 * @file Net.cpp
 * Plik zawierajacy implementacje klasy Net.
 * Klasa Net pozwala na utworzenie minimalnej ortogonalnej
 *  sieci dla punktow przechowywanych w obiekcie klasy vector z biblioteki STL.
 * @date 2009-06-04
 * @author Adam Nowik
 */

#include "Includes.h"
#include "Net.h"
#include "Para.h"
Net::Net(){

}

Net::~Net(){

}

void Net::createNet(vector<Para>& lista) {
	net.clear();
	for (int i = 0; i < (int)lista.size()-1; i++) {
		createRoute(lista, lista.at(i), i);
	}
}

void Net::createRoute(vector<Para>& lista, Para& target, int i) {
	activePoint = target;
	xList.clear();
	yList.clear();
	for (int j = 0; j < (int)lista.size(); j++) {
		if (isLine(activePoint, lista.at(j))) {
			net.push_back(activePoint);
			net.push_back(lista.at(j));
		}
	}
	for (int j = i+1; j < (int)lista.size(); j++) {
		Para tempPoint1(activePoint.getX(), lista.at(j).getY());
		Para tempPoint2(lista.at(j).getX(), activePoint.getY());
			xList.push_back(tempPoint1);
			yList.push_back(tempPoint2);
	}
	findNearestInLists(activePoint);
	activePoint = target;
	if (nearestPointInList != activePoint)
		createRoute(lista, nearestPointInList, i + 1);
	nearestPoint = findNearest(lista.at(i));
	if (nearestPoint != activePoint) {
		Para point(activePoint.getX(), nearestPoint.getY());
		net.push_back(activePoint);
		net.push_back(point);
		net.push_back(point);
		net.push_back(nearestPoint);
		point.setX(nearestPoint.getX());
		point.setY(lista.at(i).getY());
		net.push_back(nearestPoint);
		net.push_back(point);
		net.push_back(point);
		net.push_back(lista.at(i));
	}
}
bool Net::isLine(Para& punkt1, Para& punkt2) {
	if (punkt1.getX() == punkt2.getX() || punkt1.getY() == punkt2.getY())
		return true;
	return false;
}

bool Net::isBetween(Para& badany, Para& sectionStart, Para& sectionEnd) {
		if (sectionStart.getX() == sectionEnd.getX()) { // odcinek pionowy
			if ((badany.getX() == sectionStart.getX())
					&& ((sectionStart.getY() <= sectionEnd.getY() && badany.getY() >= sectionStart.getY() && badany.getY() <= sectionEnd.getY()) || (sectionStart.getY() >= sectionEnd.getY() && badany.getY() <= sectionStart.getY() && badany.getY() >= sectionEnd.getY())))
				return true;
		} else {									// odcinek poziomy
			if (badany.getY() == sectionStart.getY()
					&& (badany.getX() >= sectionStart.getX() && badany.getX() <= sectionEnd.getX()))
				return true;
		}
	return false;

}

Para Net::findNearest(Para& badany) {
	Para nearestPoint = activePoint;
	Para point;
	int minDistance = 99999999;
	int x1 = activePoint.getX();
	int y1 = activePoint.getY();
	int x2 = badany.getX();
	int y2 = badany.getY();
	for (int i = 0; i < (int)net.size(); i++) {
		if (net.at(i).getX() >= x1 && net.at(i).getX() <= x2)	//sprawdzam czy punkt znajduje sie w kracie utworzonej przez badany i activePoint
			if ((y1 <= y2 && net.at(i).getY() >= y1 && net.at(i).getY() <= y2 )
					||
				(y1 >= y2 && net.at(i).getY() <= y1 && net.at(i).getY() >= y2)) {
				int xDistance = abs(net.at(i).getX() - x2);
				int yDistance = abs(net.at(i).getY() - y2);
				if (xDistance + yDistance < minDistance) {
					minDistance = xDistance + yDistance;
					nearestPoint = net.at(i);
				}
			}
		if ((i % 2 == 0) && (i < (int)net.size() - 1)) {	// sprawdzam czy odcinek nie znajduje sie w kracie
			if (x2 >= net.at(i).getX() && x2 <= net.at(i+1).getX()) {
				point.setX(x2);
				point.setY(net.at(i).getY());
			}
			if (y2 >= net.at(i).getY() && y2 <= net.at(i+1).getY()) {
				point.setX(net.at(i).getX());
				point.setY(y2);
			}
			if ((y1 <= y2 && point.getY() >= y1 && point.getY() <= y2 )
					||
					(y1 >= y2 && point.getY() <= y1 && point.getY() >= y2)) {
				int xDistance = abs(point.getX() - x2);
				int yDistance = abs(point.getY() - y2);
				if (xDistance + yDistance < minDistance) {
					minDistance = xDistance + yDistance;
					nearestPoint = point;
				}
			}
		}
	}
	return nearestPoint;
}

void Net::findNearestInLists(Para& target) {
	nearestPointInList = target;
	int minDistance = INF;
	int x1 = target.getX();
	int y1 = target.getY();
	for (int i = 0; i < (int)xList.size(); i++) {
		int x2 = yList.at(i).getX();
		int y2 = xList.at(i).getY();
		int xDistance = abs(x1 - x2);
		int yDistance = abs(y1 - y2);
		if (xDistance < minDistance) {
			minDistance = xDistance;
			nearestPointInList = yList.at(i);
		}
		if (yDistance < minDistance) {
			minDistance = yDistance;
			nearestPointInList = xList.at(i);
		}
	}
}

void Net::drawNet(vector<Para>& lista) {
	ofstream out("rysunek.svg");
	out << "<?xml version=\"1.0\" standalone=\"no\"?>" << endl;
	out << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" << endl;
	out << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << endl;
	out << "<svg width=\"100%\" height=\"100%\" version=\"1.1\"" << endl;
	out << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
	int xStart, yStart, xEnd, yEnd;
	string style = "style=\"stroke:black;stroke-width:2\"";
	string circleStyle = " r=\"2\" stroke=\"black\" stroke-width=\"2\" fill=\"black\"/>";

	for (int i = 0; i < (int)net.size() - 1; i += 2) {
		xStart = net.at(i).getX();
		yStart = net.at(i).getY();
		xEnd = net.at(i+1).getX();
		yEnd = net.at(i+1).getY();
		out << "<line x1=\"" << xStart << "\" y1=\"" << yStart << "\" x2=\"" << xEnd
		<< "\" y2=\"" << yEnd << "\"" << endl;
		out << style << "/>" << endl;
	}
	for (int i = 0; i < (int)lista.size(); i++) {
		xStart = lista.at(i).getX();
		yStart = lista.at(i).getY();
		out << "<circle cx=\"" << xStart << "\" cy=\"" << yStart << "\"" << circleStyle << endl;
	}
	out << "</svg>" << endl;
	out.close();
}
