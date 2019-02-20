/**
 * @file Para.cpp
 * Plik zawierajacy implementacje metod klasy Para.
 * Obiekty klasy Para reprezentuja punkty na plaszczyznie.
 * @date 2009-06-03
 * @author Adam Nowik
 */
#include "Includes.h"
#include "Para.h"
Para::Para() {
		x = y = 0;
}
Para::Para(int i, int j) {
		x = i;
		y = j;
}
Para::~Para() {
}

int Para::getX() {
	return x;
}

void Para::setY(int aY) {
	y = aY;
}

void Para::setX(int aX) {
	x = aX;
}

int Para::getY() {
	return y;
}

bool Para::operator==(const Para& cel) {
	if ((x == cel.x) && (y == cel.y))
		return true;
	return false;
}

bool Para::operator!=(const Para& cel) {
	if ((x != cel.x) || (y != cel.y))
		return true;
	return false;
}

bool Para::operator<(const Para& cel) {
	if (x < cel.x || (x == cel.x && y < cel.y))
		return true;
	return false;
}

bool Para::operator>(const Para& cel) {
	if (x > cel.x || (x == cel.x && y > cel.y))
		return true;
	return false;
}

bool Para::operator<=(const Para& cel) {
	if (*this < cel || *this == cel)
		return true;
	return false;
}


