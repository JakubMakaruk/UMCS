# Strategia

Jest to wzorzec projektowy. Wzorzec ten zapewnia czytelność kodu oraz łatwe utrzymanie poprzez wydzielenie wspólnej abstrakcji dla wszystkich bloków warunkowych. Abstrakcaja to interfejs. Zawartość każdego bloku to osobny algorytm, osobna instrukcja warunkowa. Gdyby w naszym kodzie pojawiła by się wiązanka ifów, w których byłyby bloki kodu wielkości kilkudziesięciu linijek, ten kod byłby strasznie nieczytelny. Aby znaleźć daną instrukcję warunkową trzeba byłoby przewijać bloki kodów innych instrukcji warunkowych. Za pomocą tego wzorca każde bloki kodu, które występują w ifach, zapisujemy do oddzielnych klas. </br> </br>
**Przykłady:**
</br>
**1.** 5 ifów, w których znajdowałyby się implementacje różnych algorytmów sortujących. Zamiast pisać algorytm quicksorta, insertsorta, selectionsorta, bubblesorta, mergesorta, wszystkie te algorytmy możemy zapisać do osobnych klas, a w ifach jedynie wywoływać metodę z tych klas. </br>
**2.** Formatowanie tekstu na różne sposoby. Przykład pokazany poniżej. Gdy chcemy dany tekst sformatować na przeróżny sposób. W prawdzie osobne klasy nie są tu aż tak potrzebne, ponieważ np. zamiana tekstu na wielkie litery to sprawa jednej linijki i wywołania jednej metody. Natomiast formatowanie tekstu w taki sposób, że co druga litera jest literą wielką - to wymaga już kilka linijek kodu, więc można to "ukryć" w osobnej klasie.

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Strategia/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Strategia/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Strategia/zdj/main2.png" alt="zdj">
</p>
