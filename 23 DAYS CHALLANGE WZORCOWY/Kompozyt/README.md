# Kompozyt

Jest to wzorzec strukturalny. Wzorzec ten umożliwia użytkownikowi złożenie wszystkich obiektów w jeden pojedynczy obiekt. Gdybyśmy chcieli wykonać operację na każdym obiekcie musielibyśmy wywoływać metodę na każdym obiekcie ręcznie. Dzięki kompozytowi - obiekcie klasy, który jest kontenerem obiektów i realizuje interfejs. </br></br>
**Przykłady:**
</br>
**1.** Paint. Wyobraźmy sobie sytuację, że po utworzeniu kształtu nie pojawiają się one automatycznie na ekranie. Jeśli tworzylibyśmy X kształtów każdy pojedynczo musielibyśmy wyświetlać wywołując metodę rysuj(). Dzięki kompozytowi przez jednorazowe wywołanie metody rysuj() wyświetlą się wszystkie utworzone kształty

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Kompozyt/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Kompozyt/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Kompozyt/zdj/main2.png" alt="zdj">
</p>

### Struktura plików(użyty interfejs):
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Kompozyt/zdj/main3.png" alt="zdj">
</p>
