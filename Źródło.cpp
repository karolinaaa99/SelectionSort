#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void init(int tab[], int n) //funkcja zapełniająca tablicę tab o rozmiarze n losowymi licbami
{
	for (int i = 0; i < n; i++)
	{
		tab[i] = rand() % 100 + 1; //zapelniam tablice liczbami losowymi z przedzialu <1, 100>
	}
}

void print(int tab[], int n) //funkcja do wyświetlenia danych z tablicy
{
	for (int i = 0; i < n; i++)
	{
		cout << tab[i] << " ";
	}
}

void sort(int tab[], int n) //sortowanie przez proste wybieranie (selekcje), selectionsort
{
	int max, pomoc;

	for (int i = 0; i < n; i++) // zaczynamy od pierwszego elementu i konczymy na ostatnim
	{
		max = i; // indeks najmniejszego znalezionego elementu
		for (int j = i + 1; j < n; j++) // poszukujemy najmniejszego elementu poczawszy od i
		{
			if (tab[j] < tab[max]) // jezeli znalezlismy mniejszy element zapisujemy jego indeks w max
				max = j;
		}
		// wstawiamy najmniejszy element na odpowiednie miejsce
		pomoc = tab[max];
		tab[max] = tab[i];
		tab[i] = pomoc;
	}
}


int main()
{
	cout << "SelectionSort" << endl;
	cout << "***************" << endl;

	int n;
	clock_t poczatek;
	clock_t koniec;
	double wynik;

	srand(time(NULL));
	cout << endl;

	poczatek = clock();

	cout << "Podaj ile liczb chcesz posortowac n = ";
	cin >> n;
	cout << endl;

	int* tab = new int[n];

	//zapelniam tablice
	init(tab, n);

	cout << "Zawartosc tablicy przed sortowaniem:" << endl;
	print(tab, n);
	cout << endl;

	//wywoluje algorytm sortowania przez proste wybieranie(selekcje)
	sort(tab, n);
	cout << endl;

	cout << "Zawartosc tablicy po sortowaniu:" << endl;
	print(tab, n);
	cout << endl;

	koniec = clock();
	wynik = (double)(koniec - poczatek) / CLOCKS_PER_SEC;
	cout << endl;

	cout << "Czas dzialania sortowania przez proste wybieranie (selekcje) : " << wynik << " sek" << endl;


	return 0;
}