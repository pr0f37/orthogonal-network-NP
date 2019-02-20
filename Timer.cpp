/**
 * @file Timer.cpp
 * Plik zawierajacy implementacje metod klasy Timer.
 * Klasa Generator sluzy do zliczania czasów i wyliczania q.
 * @date 2009-06-08
 * @author Adam Nowik
 */
#include "Includes.h"
#include "Timer.h"

Timer::Timer() {
}

Timer::~Timer() {
}
void Timer::setStart() {
	gettimeofday(&start, NULL);
}

void Timer::setEnd() {
	gettimeofday(&end, NULL);
}

double Timer::getTime(int i) {
	return timetab[i];
}

void Timer::calculateTime(int i) {
	double sec_time;
	double usec_time;
	sec_time = (end.tv_sec - start.tv_sec) * 1000;
	usec_time = (end.tv_usec - start.tv_usec) / 1000;
	timetab[i] = sec_time + usec_time;
}

void Timer::calculateExactTime(int i, int n) {
		etimetab[i] = n * log(n) + (7 * n * n - 5 * n)/2;
		amount[i] = n;
}

void Timer::calculateQ() {
	 double Tnmediana = 0, tnmediana = 0;
	 Tnmediana = (etimetab[4] + etimetab[5])/2;
 	 tnmediana = (timetab[4] + timetab[5])/2;
 	 for (int i = 0; i < 10; i++)
 		 qtab[i] = (timetab[i] * Tnmediana)/(etimetab[i] * tnmediana);
}

void Timer::writeToFile() {
	ofstream out("Qtable.txt");
	out << "n: \t T(n): \t Q(n):" << endl;
	for(int i = 0; i < 10; i++) {
		out << amount[i] << "\t" << timetab[i] << "\t" << qtab[i] << endl;
	}
	out.close();
}
