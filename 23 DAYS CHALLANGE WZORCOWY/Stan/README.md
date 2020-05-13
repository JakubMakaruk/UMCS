# Stan

Jest to wzorzec projektowy, którego celem jest umożliwienie zmiany zachowania/stanu obiektu, kiedy zmieni się jego wewnętrzny stan. Innymi słowy - jeśli wewnętrzny stan obiektu się zmieni to wtedy zmieniamy również zachowanie tego obiektu. </br> </br>
**Przykłady:**
</br>
**1.** Narzędzie w Paintcie. Każde narzędzie ma inną funkcjonalność. Dla przykłądu:
SelectionTool - będzie służyć do zaznaczania,
PenTool - będzie służyć do rysowania. Gdy zmienimy stan obiektu narzędzia powinniśmy również zmienić funkcjonalność narzędzia, np. gdy było SelectionTool - mogliśmy zaznaczać, a po zmianie narzędzia na PenTool - możemy rysować. </br>
**2.** Maszyna stanów dla gry(FSM). Głowny bohater może zmieniać swój stan za pomocą maszyny stanów, np. z CHODZENIE na stan ATAKOWANIE. Tak samo i w tym przypadku po zmianie stanu gracz powinien "zmienić swoje zachowanie".

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Stan/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Stan/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Stan/zdj/main2.png" alt="zdj">
</p>
