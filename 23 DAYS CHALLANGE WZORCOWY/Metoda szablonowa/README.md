# Metoda szablonowa

Jest to czynnościowy wzorzec projektowe. Celem wzorca jest zdefiniowanie metody, która ma być szkieletem wybranego algorytmu. Wzorzec charakteryzują:
- klasa abstrakcyjna - która zawiera metodę szkieletu algorytmu,
- przynajmniej dwie klasy, które uzupełniają szkielet algorytmu.
</br>

**Przykłady:**
</br>
**1.** Wybranie sortowania rosnąco/malejąco dla tablicy liczb. Przykład jest przedstawiony niżej. Główny szkielet sortowania(insertion sort) występujący w klasie abstrakcyjnej w swojej zawartości zawiera wywołanie metody "porownaj", która w zależności od instancji obiektu(Rosnaco/Malejaco) używa odpowiedniej metody do zwracania większej/mniejszej wartości. </br>

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Metoda%20szablonowa/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Metoda%20szablonowa/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Metoda%20szablonowa/zdj/main2.png" alt="zdj">
</p>
