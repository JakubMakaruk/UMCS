# Polecenie(Command)

Jest to wzorzec projektowy. Celem wzorca jest hermetyzacja(enkapsulacja) danych potrzebnych do wykonania żądania oraz zapisywanie żądań w kolejce bądź na stosie w celu uzupełnianiu historii żądań, aby później w razie potrzeby była mozliwość wycofywania ich. Wzorzec powinien zaimplementowany być za pomocą:
- interfejs polecenia - deniuje operacje do wykonania,
- obiekt polecenia - konkretny obiekt realizujący dane polecenie,
- klient/grupa klientów - obiekt/obiekty na których polecenie będzie wykonywać operacje,
- nadawca - obiekt tworzący polecenia i dodający do kolejki lub przekazujący do odbiorcy,
- odbiorca - obiekt pobierający i wykonujący polecenia. 

**Przykłady:** </br>
**1.** Pierwszy przykład jest związany z jedną z moich ulubionych gier - Mafia: The city of Lost Heaven. Gra opowiada o przestępczym życiu mafijnym. Wybrałem trzech członków mafii, którzy w tej grze występują, m.in. Tommy, Paul oraz Sam, którzy wchodzą w skład rodziny należącej do Szefa Mafii - Don Salieri. Członkowie Mafii wykonują polecenia, które zostały im narzucone przez szefa tj. "zbieranie haraczu" oraz "planowanie akcji". Dodatkowo zaimplementowałem klasę Robota, w której znajduje się tablica rozkazów dla poszczególnych członków. </br>
**2.** Klub piłkarski. Trener jest obiektem, który przekazuje polecenia do odbiorców - piłkarzów. Możliwe polecenia, które mogłyby się znaleźć w takim systemie to np. "trenujStrzelanie", "trenujBieganie", "trenujDrybling".

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Polecenie/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Polecenie/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Polecenie/zdj/main2.png" alt="zdj">
</p>
