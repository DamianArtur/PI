#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

void zad2() {
	double x, y, z;
	int k, m;
	double w1, w2, w3, w4, w5;
	int ret = -1;

	printf("--------------------------------------- \n");
	printf("Zadanie 2 - obliczanie wyrazen \n");
	printf("--------------------------------------- \n");

	printf("Podaj trzy liczby rzeczywiste: ");
	ret = scanf("%lf%lf%lf", &x, &y, &z);
	printf("Podaj dwie liczby calkowite: ");
	ret += scanf("%d%d", &k, &m);
	
	if (ret != 5) {
		printf("Blad przy wczytaniu \n\n\n");
		return;
	}

	printf("Podales x=%lf, y=%lf, z=%lf, k=%d, m=%d \n", x, y, z, k, m);

	if(x == 0.0 || y == 0.0) {
		printf("Nie mozna obliczyc pierwszego wyrazenia: x i/lub y rowne 0. \n");
	} else{
		w1 = cbrt(x / (y * z)) * log(x * x + y * y);
		printf("w1 = %.8lf \n", w1);
	}
	
	w2 = sin(k * x / 2) * cos(m * y) + y * exp(2 * x - 1);
	printf("w2 = %.8lf \n", w2);

	w3 = fabs(x / (2 * y * y + 1)) + sqrt(y / (z * z + 3)) + 5 * pow(y + z, 3);
	printf("w3 = %.8lf \n", w3);

	if (x == 0.0 || z == 0.0) {
		printf("Nie mozna obliczyc czwartego wyrazenia: x i/lub z rowne 0. \n");
	}
	else {
		w4 = x / (y * z) * cbrt(z + 1) + pow(x * x + z * z + 1, 1 / (double)k) - fabs(y);
		printf("w4 = %.8lf \n", w4);
	}

	if (x == 0.0) {
		printf("Nie mozna obliczyc piatego wyrazenia: x rowne 0. \n");
	}
	else {
		w5 = 1 / sqrt(x * x + y * y + k * (double)k) + (1 / x) * sin(k * y);
		printf("w5 = %.8lf \n", w5);
	}

	printf("\n\n");
}

void zad3() {
	double a = 0.0, b = 0.0, c = 0.0;
	int ret = -1;

	printf("--------------------------------------- \n");
	printf("Zadanie 3 - program do obliczania rzeczywistych i zespolonych pierwiastkow rownania kwadratowego \n");
	printf("--------------------------------------- \n");
	printf("W rownaniu ax^2 + bx + c = 0 podaj a, b i c: ");
	ret = scanf("%lf%lf%lf", &a, &b, &c);

	if (ret != 3) {
		printf("Blad przy wczytaniu \n\n\n");
		return;
	}

	printf("Wczytane: a = %lf, b = %lf, c = %lf \n", a, b, c);

	const double tol = 1e-14;
	if (fabs(a) <= tol) {
		printf("To nie jest rownanie kwadratowe: a == 0 \n\n\n");
		return;
	}

	printf("Rownanie kwadratowe: %lf * x^2 %+lf * x %+lf = 0 \n", a, b, c);

	double D = b * b - 4 * a * c;
	if (D >= 0.0) {
		double p1, p2, x1, x2;
		p1 = -b / (2.0 * a);
		p2 = sqrt(D) / (2.0 * a);
		x1 = p1 + p2;
		x2 = p1 - p2;
		printf("Pierwiastki: x1 = %lf \t x2 = %lf \n", x1, x2);
	}
	else {
		double r1, r2, u1, u2;
		r1 = r2 = -b / (2 * a);
		u1 = sqrt(fabs(pow(b / (2 * a), 2) - c / a));
		u2 = -u1;
		printf("Pierwiastki: x1 = %lf %+lf i \t x2 = %lf %+lf i \n", r1, u1, r2, u2);
	}

	printf("\n\n");
}

void zad4() {
	double a, b, c;
	int ret = -1;

	printf("--------------------------------------- \n");
	printf("Zadanie 4 - sprawdzanie warunku trojkata \n");
	printf("--------------------------------------- \n");
	printf("Podaj dlugosci bokow trojkata: ");
	ret = scanf("%lf%lf%lf", &a, &b, &c);

	if (ret != 3) {
		printf("Blad przy wczytywaniu \n\n\n");
		return;
	}

	if (!(a < b + c && b < a + c && c < a + b)) {
		printf("Podane dlugosci nie spelniaja warunku istnienia trojkata \n");
	}
	else {
		double p = (a + b + c) / 2;
		double S = sqrt(p * (p - a) * (p - b) * (p - c));
		double R = S / p;

		printf("Pole tego trojkata wynosi: %lf \n", S);
		printf("Promien kola wpisanego w trojkat wynosi: %lf \n", R);
	}

	printf("\n\n");
}

void zad5() {
	int a, b, c, d;
	int ret = -1;

	printf("--------------------------------------- \n");
	printf("Zadanie 5 - znajdowanie indeksu najwiekszej z czterech liczb \n");
	printf("--------------------------------------- \n");
	printf("Podaj cztery liczby calkowite: ");
	ret = scanf("%d%d%d%d", &a, &b, &c, &d);

	if (ret != 4) {
		printf("Blad przy wczytywaniu \n\n\n");
		return;
	}

	if (a > b && a > c && a > d) {
		printf("Najwieksza jest liczba na pozycji 1 \n");
	}
	else if (b > a && b > c && b > d) {
		printf("Najwieksza jest liczba na pozycji 2 \n");
	}
	else if (c > a && c > b && c > d) {
		printf("Najwieksza jest liczba na pozycji 3 \n");
	} else
		printf("Najwieksza jest liczba na pozycji 4 \n");

	printf("\n\n");
}

double pole_trojkata(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double obwod_trojkata(double a, double b, double c) {
	return a + b + c;
}

double pole_kwadratu(double a) {
	return a * a;
}

double obwod_kwadratu(double a) {
	return 4 * a;
}

double pole_prostokata(double a, double b) {
	return a * b;
}

double obwod_prostokata(double a, double b) {
	return 2 * a + 2 * b;
}

double pole_kola(double r) {
	return M_PI * r * r;
}

double obwod_kola(double r) {
	return 2 * M_PI * r;
}

void zad6() {
	double trojkat_a, trojkat_b, trojkat_c, kwadrat_a, prostokat_a, prostokat_b, kolo_r;
	int ret = -1;

	printf("--------------------------------------- \n");
	printf("Zadanie 6 - pola i obwody figur \n");
	printf("--------------------------------------- \n");

	printf("Podaj boki trojkata: ");
	ret = scanf("%lf%lf%lf", &trojkat_a, &trojkat_b, &trojkat_c);
	printf("Podaj bok kwadratu: ");
	ret += scanf("%lf", &kwadrat_a);
	printf("Podaj boki prostokatu: ");
	ret += scanf("%lf%lf", &prostokat_a, &prostokat_b);
	printf("Podaj promien kola: ");
	ret += scanf("%lf", &kolo_r);

	if (ret != 7) {
		printf("Blad wczytywania \n\n\n");
		return;
	}

	if (trojkat_a < 0 || trojkat_b < 0 || trojkat_c < 0) {
		printf("Dlugosc boku trojkata nie moze byc ujemna \n");
	}
	else if (!(trojkat_a < trojkat_b + trojkat_c && trojkat_b < trojkat_a + trojkat_c && trojkat_c < trojkat_a + trojkat_b)) {
		printf("Podane dlugosci bokow nie spelniaja warunkow trojkata. \n");
	}
	else {
		printf("Pole trojkata wynosi: %lf \n", pole_trojkata(trojkat_a, trojkat_b, trojkat_c));
		printf("Obwod trojkata wynosi: %lf \n", obwod_trojkata(trojkat_a, trojkat_b, trojkat_c));
	}

	if (kwadrat_a < 0) {
		printf("Dlugosc boku kwadratu nie moze byc ujemna. \n");
	}
	else {
		printf("Pole kwadratu wynosi: %lf \n", pole_kwadratu(kwadrat_a));
		printf("Obwod kwadratu wynosi: %lf \n", obwod_kwadratu(kwadrat_a));
	}

	if (prostokat_a < 0 || prostokat_b < 0) {
		printf("Dlugosc boku prostokata nie moze byc ujemna. \n");
	}
	else {
		printf("Pole prostokata wynosi: %lf \n", pole_prostokata(prostokat_a, prostokat_b));
		printf("Obwod prostokata wynosi: %lf \n", obwod_prostokata(prostokat_a, prostokat_b));
	}
	
	if (kolo_r < 0) {
		printf("Dlugosc promienia kola nie moze byc ujemna. \n");
	}
	else {
		printf("Pole kola wynosi: %lf \n", pole_kola(kolo_r));
		printf("Obwod kola wynosi: %lf \n", obwod_kola(kolo_r));
	}

	printf("\n\n");
}

int main(int argc, char* argv[]) {
	zad2();
	zad3();
	zad4();
	zad5();
	zad6();

	printf("Wyjscie - Ctrl + Z Enter \n");
	int ch;
	while ((ch = getchar()) != EOF)
		;
}