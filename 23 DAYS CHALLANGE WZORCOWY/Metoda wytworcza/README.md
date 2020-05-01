# Metoda wytwórcza

Jest to wzorzec konstrukcyjny. Używa się go do określenia intrefejsu w celu tworzenia obiektów. Podklasy zajmują się tworzeniem obiektów. We wzorcu występują dwie ogólne klasy lub interfejsy, które definiują typ zasobów (Product) oraz sposób ich tworzenia (Creator).
Wzorzec ten stosuje się, gdy:
- w klasie nie można z góry ustalić wszystkich klas obiektów, które trzeba stworzyć(istnieje możliwość rozbudowy systemu o dodatkowe klasy),
- chcemy zachować zasadę Open/Closed Principle(SOLID).

Jeżeli w przyszłości będziemy chceli rozbudować aplikację o kolejne klasy, wówczas wskazane będzie wrócić do wcześniejszych metod i je modyfikować poprzez dodanie kolejnego ifa/case. </br>
"Kod powinien być napisany tak, aby dodawanie nowych elementów nie wymagało modyfikowania już zaimplementowanych i zamkniętych." </br></br>
**Przykłady:**
</br>
**1.** Gra strategiczna(np. Plemiona), w której za pomocą obiektu Ratusz możliwe jest tworzenie Postaci typu "Miecznik"/"Łucznik"/"Topornik", aby dodać te postacie do swojej armii. Gdybyśmy chcieli do tej aplikacji dodać nową postać, wystarczyłoby, że stworzylibyśmy nową klasę tej postaci oraz jej Kreator(zachowalibyśmy drugą zasadę SOLIDa). </br>
**2.** Fabryka chipsów, nowy smak chpisów równa się nowa klasa oraz kreator tej klasy. Za pomocą kreatora danego smaku chipsów tworzylibyśmy obiekty.

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Metoda%20wytworcza/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Metoda%20wytworcza/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Metoda%20wytworcza/zdj/main2.png" alt="zdj">
</p>
