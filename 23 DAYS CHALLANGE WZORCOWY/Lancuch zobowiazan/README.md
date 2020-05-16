# Łańcuch zobowiązań(Chain of Responsibility)

(Łańcuch odpowiedzialności)Wzorzec projektowy, którego celem jest stworzenie obiektowej wersji instrukcji warunkowych IF, ELSE IF, ELSE. W tym wzorcu żądanie przetwarzane jest przez różne obiekty, w zależności od jego typu. Na łańcuch składają się obiekty, które jeśli nie są w stanie obsłużyć danego żądania to przekazują dane żądanie do kolejnego ogniwa za pomocą metody obecneOgniwo->getNext()->metoda. </br> </br>
**Przykłady:**
</br>
**1.** Głównym zastosowaniem wzorca i przykładem jest każda wiązanka instrukcji warunkowych, które za pomocą te wzorca możemy zapreprezentować obiektowo.

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Lancuch%20zobowiazan/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Lancuch%20zobowiazan/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Lancuch%20zobowiazan/zdj/main2.png" alt="zdj">
</p>
