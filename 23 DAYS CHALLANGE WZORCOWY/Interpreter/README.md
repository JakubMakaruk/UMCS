# Interpreter

Jest to wzorzec projektowy. Wzorzec ten można wykorzystać w celu zdefiniowania pewnego zapisu i stworzenie dla niego interpretera. Gdy zdanie zapisane jest w pewnym interpretowalnym języku, może być reprezentowane jako drzewo składniowe. Istnieje pewna gramatyka opisująca ten język. Ogólnie mówiąc wzorzec dotyczy ewaluowania wyrażeń pewnego języka. </br> </br>
**Przykłady:**
</br>
**1.** Kalkulator ONP(Infix to Postfix) - w takim kalkulatorze wymagane jest interpretowanie wyrażeń zapisanych w odwrotnej notacji polskiej oraz sprawdzenie poprawności reguł. Przykład przedstawiony jest poniżej w formie diagramu oraz kodu z uwzględnieniem tylko dodawania oraz odejmowania.

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Interpreter/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Interpreter/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Interpreter/zdj/main2.png" alt="zdj">
</p>

### Główna klasa rozwiązująca problem oraz klasy interpretujące wyrażenie.
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Interpreter/zdj/main3.png" alt="zdj">
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Interpreter/zdj/interpreter1.png" alt="zdj">
</p>
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Interpreter/zdj/interpreter2.png" alt="zdj">
</p>
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Interpreter/zdj/interpreter3.png" alt="zdj">
</p>
