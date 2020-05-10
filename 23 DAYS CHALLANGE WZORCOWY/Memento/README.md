# Memento(Pamiątka)

Jest to wzorzec czynnościowy projektowy. Do zadań tego wzorca należy zapamiętywanie i udostępnianie stanów obiektu, np. przywracanie poprzedniego stanu obiektu. We wzorcu tym wyróżnia się 3 klasy:
- **Originator** - klasa zapisująca oraz przywracająca stan obiektu,
- **Memento** - klasa przechowująca obecny stan obiektu, który odczytać możemy za pomocą klasy Originator, 
- **Caretaker** - klasa przechowująca stany operującego obiektu. Zwraca te stany oraz dodaje nowe.
</br></br>

**Przykłady:**
</br>
**1.** Edytor tekstowy. Przykład przedstawiony jest poniżej za pomocą diagramu oraz programu. Głównym założeniem jest pisanie w edytorze tekstowym oraz zapisywaniu danego pliku. Gdy dany plik zapiszemy, będziemy mogli się później po późniejszych zapisach do niego wciąż odwołać. </br>
**2.** Save w grach. Posłużę się jedną z moich ulubionych gier - GTA San Andreas. Gdy chcemy zapisać grę musimy główną postacią(CJ) wejść w "dyskietkę"(obiekt przenoszący nas do save-ów gry). Wtedy możemy wybrać wolny slot gdzie zapiszemy naszą grę na obecnym stanie. Po zapisaniu gdy będziemy się chcieli "pobawić" w mieście czyli. 5 gwiazdek + BAGUVIX, zawsze będziemy mogli wrócić do wcześniejszego stanu gry, który zapisaliśmy na wcześniej wybranym slocie.

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Memento/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Memento/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Memento/zdj/main2.png" alt="zdj">
</p>
