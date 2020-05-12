# Mediator

Jest to wzorzec projektowy. Za pomocą tego wzorca zapewnia się zmniejszoną ilość powiązań między klasami(ponieważ to Mediator jako jedyny zna większość pracujących ze sobą obiektów), a także daje jednolity interfejs do przesyłania wiadomości pomiędzy obiektami klas. Mediator to jedyna klasa, która zna wszystkie metody innych klas(tych, którymi zarządza). Pozostałe klasy nie muszą nic o sobie wiedzieć, a jedynie przesyłają polecenia mediatorowi, który rozsyła je do odpowiednich adresatów. </br> </br>
**Przykłady:**
</br>
**1.** Wysyłanie wiadomości od nadawcy do odbiorcy. Przykład podany poniżej. Nadawca używa w tym celu wysłania polecenia do mediatora, którego ma zaimplementowanego w swojej strukturze, który ten wysyła wiadomość do konkretnego odbiorcy.</br>

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Mediator/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Mediator/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Mediator/zdj/main2.png" alt="zdj">
</p>
