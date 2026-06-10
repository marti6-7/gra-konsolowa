#include <iostream>  // Umożliwia operacje wejścia/wyjścia, czyli wypisywanie tekstu (cout) i wczytywanie danych (cin).
#include <conio.h>   // Zawiera funkcję _getch(), która pozwala na odczyt wciśniętego klawisza natychmiast, bez klikania Enter.
#include <cstdlib>   // Daje dostęp do funkcji systemowych, np. system("cls") do czyszczenia ekranu konsoli.
#include <ctime>     // Biblioteka obsługująca czas, przydatna np. przy losowości (w tym programie dodana profilaktycznie).
using namespace std; // Pozwala pisać np. 'cout' zamiast pełnego 'std::cout'.

// wymaganie- tablica dwuwymiarowa, mapa
char mapa[10][20];   // Deklaracja globalnej tablicy znaków o rozmiarze 10 wierszy na 20 kolumn, która reprezentuje świat gry.

// Funkcja odpowiedzialna za wypełnienie tablicy i rysowanie mapy na ekranie
void generujMape(int graczX, int graY, int celX, int celY) {
    system("cls");   // Czyści ekran konsoli, aby odświeżyć mapę i nie rysować jej pod spodem poprzedniej.

    // Pętla 'for' przechodząca przez każdy wiersz (i) od 0 do 9
    for (int i = 0; i < 10; i++) {
        // Pętla 'for' przechodząca przez każdą kolumnę (j) w danym wierszu od 0 do 19
        for (int j = 0; j < 20; j++) {

            // Sprawdzenie, czy aktualna pozycja (i, j) to współrzędne gracza
            if (i == graczX && j == graY) {
                mapa[i][j] = 'G'; // Jeśli tak, wstawiamy znak 'G' (Gracz) do tablicy.
            }
            // Sprawdzenie, czy aktualna pozycja to współrzędne celu (skarbu)
            else if (i == celX && j == celY) {
                mapa[i][j] = '$'; // Jeśli tak, wstawiamy znak '$' (Cel) do tablicy.
            }
            // Sprawdzenie, czy jesteśmy na krawędziach mapy (pierwszy/ostatni wiersz lub kolumna)
            else if (i == 0 || i == 9 || j == 0 || j == 19) {
                mapa[i][j] = '#'; // Jeśli tak, tworzymy ścianę (granicę mapy).
            }
            // W przeciwnym wypadku pole jest puste
            else {
                mapa[i][j] = '.'; // Wstawiamy kropkę oznaczającą wolną przestrzeń.
            }

            cout << mapa[i][j] << " "; // Wypisujemy na ekran znak z tablicy i dodajemy spację dla czytelności.
        }
        cout << endl; // Po wypisaniu całego wiersza przechodzimy do nowej linii.
    }
}

// Główna funkcja programu, od której zaczyna się uruchomienie aplikacji
int main() {
    // Ekran startowy - wymaganie 10 (wpisz swoje dane)
    cout << "========================================" << endl; // Rysuje górną ramkę menu.
    cout << "  GRA KONSOLOWA: PORUSZANIE PIONKIEM    " << endl; // Wyświetla tytuł gry.
    cout << "  Autor: Jan Kowalski                   " << endl; // Wyświetla imię i nazwisko autora.
    cout << "========================================" << endl; // Rysuje dolną ramkę menu.
    cout << " Instrukcja: Sterowanie za pomoca WASD." << endl;  // Wyświetla instrukcję sterowania.
    cout << " Dotrzyj do celu '$', aby wygrac!" << endl;        // Wyświetla cel gry.
    cout << " Nacisnij dowolny klawisz, aby zaczac...";         // Informuje użytkownika o akcji.
    _getch(); // Czeka na wciśnięcie dowolnego klawisza przed startem.

    // Początkowe współrzędne gracza (wiersz 5, kolumna 5)
    int gX = 5;
    // Początkowe współrzędne gracza (Y to kolumna w naszej funkcji)
    int gY = 5;

    // Współrzędne celu, do którego gracz musi dojść (wiersz 3, kolumna 14)
    int cX = 3;
    int cY = 14;

    int punkty = 0;      // Zmienna przechowująca liczbę zdobytych punktów.
    int limitRuchow = 25; // Zmienna określająca limit ruchów gracza (warunek zakończenia).

    // Główna pętla gry - działa cały czas, dopóki nie nastąpi wygrana lub przegrana
    while (true) {

        // Wywołanie Twojej funkcji w celu narysowania mapy z aktualnymi pozycjami
        generujMape(gX, gY, cX, cY);

        // Wypisanie aktualnego stanu gry pod mapą
        cout << endl << "Punkty: " << punkty << " | Pozostalo ruchow: " << limitRuchow << endl; // Wyświetla punkty i ruchy.
        cout << "Pozycja pionka (X, Y): (" << gX << ", " << gY << ")" << endl; // Wyświetla współrzędne gracza.

        // Sprawdzenie warunku wygranej - czy gracz stoi na polu z celem
        if (gX == cX && gY == cY) {
            punkty += 10; // Dodajemy punkty za wygraną.
            cout << endl << "GRATULACJE! Dotarles do celu! Zdobyles " << punkty << " punktow." << endl; // Komunikat o wygranej.
            break; // Przerywa pętlę i kończy grę.
        }

        // Sprawdzenie warunku przegranej - brak ruchów
        if (limitRuchow <= 0) {
            cout << endl << "KONIEC RUCHOW! Przegrales." << endl; // Komunikat o przegranej.
            break; // Przerywa pętlę i kończy grę.
        }

        // Oczekiwanie na ruch gracza i pobranie znaku z klawiatury
        char ruch = _getch(); // Zapisuje wciśnięty klawisz (W, A, S lub D) do zmiennej 'ruch'.

        // Reakcja na klawisze sterowania i zmiana współrzędnych
        if ((ruch == 'w' || ruch == 'W') && gX > 1) {
            gX--; // Ruch w górę: zmniejszamy numer wiersza (jeśli nie uderzymy w górną ścianę).
            limitRuchow--; // Każdy ruch zmniejsza limit o 1.
        }
        else if ((ruch == 's' || ruch == 'S') && gX < 😎 {
            gX++; // Ruch w dół: zwiększamy numer wiersza (jeśli nie uderzymy w dolną ścianę).
            limitRuchow--; // Każdy ruch zmniejsza limit o 1.
        }
        else if ((ruch == 'a' || ruch == 'A') && gY > 1) {
            gY--; // Ruch w lewo: zmniejszamy numer kolumny (jeśli nie uderzymy w lewą ścianę).
            limitRuchow--; // Każdy ruch zmniejsza limit o 1.
        }
        else if ((ruch == 'd' || ruch == 'D') && gY < 18) {
            gY++; // Ruch w prawo: zwiększamy numer kolumny (jeśli nie uderzymy w prawą ścianę).
            limitRuchow--; // Każdy ruch zmniejsza limit o 1.
        }
    }

    cout << "Koniec programu. Dziekuje za gre!" << endl; // Napis końcowy po wyjściu z pętli.
    return 0; // Poprawne zakończenie działania funkcji głównej main.
}
