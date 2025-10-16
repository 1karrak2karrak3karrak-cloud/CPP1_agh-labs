// Laboratorium 2 - Implementacja stosu w C
//
// Prosze dopisać kod i dodać nowe pliki, tak aby program wykonywał się
// a wynik jego działania był taki sam jak podany na końcu tego pliku.
//
// Pliku main.cpp nie wolno modyfikować. Oczywiście, w czasie pracy można
// sobie jego część wykomentować, ale wersja wysłana jako rozwiązanie powinna
// zawierać plik w oryginalnej wersji – będę to sprawdzał diffem :).
//
// Ostateczny program powinien być przyjazny dla programisty
// (mieć czytelny i dobrze napisany kod).
// - co to znaczy? 
//   * kod powinien być podzielony na nagłówki i źródła
//   * nazwy powinny być zrozumiałe i spójne
//   * kod powinien kompilować się bez ostrzeżeń z flagami:
//     -Wall -Wextra -Wpedantic
//   * nie powinien powodować wycieków pamięci,
//     tzn. powinien bezproblemowo przechodzić sprawdzenie valgrindem
//
// Przy wykonywaniu zadania, nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych, wcześniej
// przygotowanych, plików). Jedynym wyjątkiem jest dołączony do zadania plik CMakeLists.txt.
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiązanie należy wgrać na UPeLa
// jako archiwum tar.gz o strukturze takiej jak opisana poniżej.
//
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem labN/, gdzie N to numer zadania/laboratorium
// * katalog z zadaniem powinien zawierać podkatalog include/
//   w którym muszą znajdować się wszystkie niezbędne pliki nagłówkowe
// * katalog z zadaniem powinien zawierać podkatalog src/
//   w którym muszą znajdować się wszystkie niezbędne pliki z kodem źródłowym
// * katalog z zadaniem powinien zawierać podkatalog build/ 
//   w którym powinny znajdować się tylko i wyłącznie pliki wygenerowane 
//   przez CMake (tzn. stan po odpaleniu cmake, a przed wywołaniem make)
//   Powinienem być w stanie wejść do tego katalogu i wykonać make, po czym uzyskać działający program.
// * tworzenie archiwum: tar -czvf nazwa.tar.gz zad/
//   np. tar -czvf lab01.tar.gz lab01/
// * rozpakowanie archiwum: tar -xvf nazwa.tar.gz

#include "Stack.h"
#include <stdio.h>


int main() {
    Stack s;
    stackInit(&s, 4); // initial capacity passed as parameter
    printState(&s);

    stackPush(&s, 10);
    stackPush(&s, 20);
    stackPush(&s, 30);
    stackPush(&s, 40);
    printState(&s);

    printf("Pop: %d\n", stackPop(&s));
    printf("Pop: %d\n", stackPop(&s));

    stackPush(&s, 50);
    stackPush(&s, 60);
    stackPush(&s, 70);   // capacity exceeded, double it
    printState(&s);

    while (!stackEmpty(&s)) {
        printf("Pop: %d\n", stackPop(&s));
    }

    stackDestroy(&s);
    return 0;
}

/** Przykładowy wynik działania programu:
size=0, capacity=4
size=4, capacity=4
Pop: 40
Pop: 30
size=5, capacity=8
Pop: 70
Pop: 60
Pop: 50
Pop: 20
Pop: 10
*/