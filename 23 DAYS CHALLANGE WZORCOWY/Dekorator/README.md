# Dekorator

Jest to wzorzec strukturalny. Stosuje się go gdy chcemy dodawać nowe funkcje do istniejących klas dynamicznie podczas działania programu. Dynamicznie dołącza dodatkowe obowiązki do obiektu. Wzorzec ten opakowuje oryginalną klasę w nową klasę "dekorującą". 
"Dekoratory są alternatywą dla dziedziczenia. Dziedziczenie rozszerza zachowanie klasy w trakcie kompilacji, w przeciwieństwie do dekoratorów, któe rozszerzają klasy w czasie działania programu." </br> </br>
**Przykłady:**
</br>
**1.** Aplikacja tworzenia własnej pizzy. Za każdym razem gdy chcemy dodać składnik do pizzy(udekorować pizzę) wywołujemy konstruktor na obiekcie Pizza już istniejącym. W ten sposób dokładamy kolejne funkcje do głównej instancji klasy(w tym przypadku składniki do głównej pizzy) </br>
**2.** Aplikacja wybierania obiadu z pojedynczych składników. Przykład zbliżony do przedstawionego wyżej. Tworzymy pełny obiad składający się z poszczególnych składników(ziemniaki, mięso, surówki). Podstawowy obiad rozszerzamy o kolejne składniki. Najpierw tworzymy obiad składający się z samych ziemniaków, później do ziemniaków dodajemy mięso, a następnie surówkę.

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Dekorator/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Dekorator/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Dekorator/zdj/main2.png" alt="zdj">
</p>
