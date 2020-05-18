# Flyweight(pyłek)

Jest to wzorzec projektowy. Celem wzorca jest zmniejszenie wykorzystywania pamięci. Podczas tworzenia nowego obiektu, najpierw sprawdzane jest czy taki egzemplarz o tych parametrach już istnieje w pamięci. Jeżeli istnieje, wówczas pobieramy go. W przeciwnym wypadku tworzymy nowy obiekt. Wzorzec przydatny w aplikacjach korzystających z większej liczby identycznych obiektów. </br> </br>
**Przykłady:**
</br>
**1.** Gra Counter Strike, jedna z moich ulubionych, w której istnieje pewne podobieństwo obiektów(modelów) postaci sterowanych przez graczy. Gracze sterują anty-terrorystą lub terrorystą. Obie te klasy realizują interfejs "Gracz", w którym jak widać niżej, wyróżnione są dwie metody. W mainie programu wykonana jest pętla(dla przykładu dla 10obiektów[5vs5 rozgrywka]), w której następuje główna część wzorca, czyli tworzenie nowego obiektu(anty-terrorysty/terrorysty), jeżeli wcześniej go nie utworzono. Następnie przypisanie broni, a finalnie wyświetlenie celu gracza gry. Sprawdzenie czy obiekt już istnieje czy nie odbywa się w klasie FACTORY, gdzie przechowywana jest HashMap-a.

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Flyweight/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Flyweight/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Flyweight/zdj/main2.png" alt="zdj">
</p>

### Struktura klasy Factory:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Flyweight/zdj/main3.png" alt="zdj">
</p>
