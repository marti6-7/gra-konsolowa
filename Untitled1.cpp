#include <iostream>//
#include <conio.h>//
#include<cstdlib>//
#include<ctime> //
using namespace std;

// wymaganie- tablica dwuwymiarowa, mapa
char mapa[10][20];   // deklaracja tablicy

// wypelnianie tablicy
void generujMape(int graczX, int graY, int celX, int celY) {
    system("cls");   // wyczyszczenie ekranu

    // petle 'for'
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {

            // czy aktualna pozycja (i, j) to współrzędne gracza
            if (i == graczX && j == graY) {
                mapa[i][j] = 'G'; // jak tak wstawiamy znak 'G' czyli gracz do tablicy
            }
            // czy aktualna pozycja to współrzędne celu (skarbu)
            else if (i == celX && j == celY) {
                mapa[i][j] = '$'; // Jeśli tak, wstawiamy znak '$' czyli cel do tablicy.
            }
            // czy jesteśmy na krawędziach mapy na pierwszy/ostatnim wierszu lub kolumnie
            else if (i == 0 || i == 9 || j == 0 || j == 19) {
                mapa[i][j] = '#'; // jezeli tak tworzymy ścianę/granice mapy
            }
            // jezeli nie pole jest puste
            else {
                mapa[i][j] = '.'; // wstawiamy kropkę oznaczającą wolną przestrzeń
            }
cout << mapa[i][j] << " "; // wypisujemy na ekran znak z tablicy i dodajemy spację dla czytelności
        }
        cout << endl; // po wypisaniu całego wiersza przechodzimy do nowej linii
    }
}

// rozpoczecie
int main() {
    // Ekran startowy - wymaganie 10 (wpisz swoje dane)
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; // górną ramka menu
    cout << "  GRA KONSOLOWA: PORUSZANIE PIONKIEM    " << endl; // tytul
    cout << "  projekt zrobiony przez: Marta Malinowska                   " << endl; // moje imie
    cout << " :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) " << endl; // dolna ramka menu
    cout << " Instrukcja: Sterowanie za pomoca klawiszy WASD" << endl;  // instrukcja sterowania
    cout << " musisz dotrzeć do celu '$' aby wygrac!" << endl;        // cel gry
    cout << " nacisnij dowolny klawisz, aby zaczac :) ";         // informacja o akcji dla gracza
    _getch(); // program czeka na wcisniecie dowolnego klawisza przed startem

    // początkowe współrzędne gracza 
    int gX = 5;
    // początkowe współrzędne gracza 
    int gY = 5;

    // współrzędne celu - $ gdzie gracz musi dojść - wiersz 3 kolumna 14
    int cX = 3;
    int cY = 14;

    int punkty = 0;      // zmienna przechowująca liczbę zdobytych punktów.
    int limitRuchow = 25; // zmienna określająca limit ruchów gracza

    // glówna pętla gry - działa cały czas dopóki nie ma wygranej lub przegranej
    while (true) {

        // wywołanie funkcji aby narysowac mape z aktualnymi pozycjami
        generujMape(gX, gY, cX, cY);
        // wypisanie aktualnego stanu gry pod mapą
        cout << endl << "Punkty: " << punkty << " | Pozostalo ruchow: " << limitRuchow << endl; // wyswietla punkty i ruchy
        cout << "Pozycja pionka (X, Y): (" << gX << ", " << gY << ")" << endl; // wys współrzędne gracza

        // warunek wygranej - czy gracz stoi na polu z celem
        if (gX == cX && gY == cY) {
            punkty += 10; // dodanie punktu za wygrana
            cout << endl << "GRATULACJE! Dotarles do celu! Zdobyles " << punkty << " punktow." << endl; // wygrana
            break; // koniec petli przerwana gra
        }

        // sprawdzenie warunku przegranej - brak ruchów
        if (limitRuchow <= 0) {
            cout << endl << "KONIEC RUCHOW! Przegrales." << endl; // przegrana
            break; // koniec petli 
        }

        // oczekuje na ruch ze strony gracza
        char ruch = _getch(); // zapisuje wcisnięty klawisz  do zmiennej ruch

        // Reakcja na klawisze sterowania i zmiana współrzędnych
        if ((ruch == 'w' || ruch == 'W') && gX > 1) {
            gX--; // ruch w górę zmniejszamy numer wiersza esli nie wejdzie w sciane
            limitRuchow--; // kazdy ruch zmniejsza o 1
        }
        else if ((ruch == 's' || ruch == 'S') && gX < 20 {
            gX++; // ruch w dół: zwiększamy numer wiersza
            limitRuchow--; // kazdy ruch zmniejsza limit 1
        }
        else if ((ruch == 'a' || ruch == 'A') && gY > 1) {
            gY--; // ruch w lewo: zmniejszamy numer kolumny (jeśli nie uderzymy w lewą ścianę)
            limitRuchow--; // Każdy ruch zmniejsza limit o 1.
        }
        else if ((ruch == 'd' || ruch == 'D') && gY < 18) {
            gY++; // ruch w prawo zwiększamy numer kolumny 
            limitRuchow--; // kazdy ruch zmniejsza limit o 1
        }
    }

    cout << " dziękuję za gre " << endl; // napis koncowy
    return 0; // zakończenie main
}
