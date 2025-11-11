//add operation code : add
double add(double a, double b) {
	return a + b;
}

//subtract operation code : sub
double sub(double a, double b) {
	return a - b;
}

//multply operation code : tms
double tms(double a, double b) {
	return a * b;
}

//divide operation code : dvd
double dvd(double a, double b) {
	return a / b;
}

//average operation code : avg
double avg(double a, double b) {
	return dvd(add(a, b), 2);
}

//square operation code : sqr
double sqr(double a) {
	return tms(a, a);
}
