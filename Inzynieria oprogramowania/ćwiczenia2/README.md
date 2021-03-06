## RELACJE

* #### *Dziedziczenie*
  > klasa pochodna dziedziczy właściwości po klasie bazowej <br/>
  > **C++ -** class Pochodna : public Bazowa <br/>
  > **Java -** class Pochodna extends Bazowa <br/>
  <img src="https://github.com/JakubMakaruk/UMCS/blob/master/Inzynieria%20oprogramowania/%C4%87wiczenia2/zdj/dziedziczenie.png">
  
* #### *Realizacja/Implementacja(interfejs)
  > **interfejs** - klasa bez żadnych pól/atrybutów, a wszystkie metody są publiczne i abstrakcyjne. <br/>
  > np. żadna klasa pochodna Kwadrat/Koło nie ma takich samych wszystkich pól, więc lepiej zastosować interfejs, który miałby metodę obliczPole()
  <img src="https://github.com/JakubMakaruk/UMCS/blob/master/Inzynieria%20oprogramowania/%C4%87wiczenia2/zdj/realizacjaimplementacjainterfejs.png">
  
* #### *Powiązanie*
  > (zazwyczaj na poziomie pól) <br/>
  > np. podczas zajęć **Student** jest powiązany ze **Stanowiskiem komputerowym**, natomiast po zakończeniu zajęć powiązania tego już nie będzie. <br/>
  > w kodzie wygląda to tak, że **Student** ma wskaźnik(*) na **Stanowisko**, a Stanowisko może mieć wskaźnik na Studenta. <br/>
  > np. **Student** wypożycza **Książkę** z biblioteki. Wtedy pojawia się powiązanie. Gdy Student odda tą Książkę, powiązanie to znika. <br/>
  <img src="https://github.com/JakubMakaruk/UMCS/blob/master/Inzynieria%20oprogramowania/%C4%87wiczenia2/zdj/powiazanie.png">
  
* #### *Zależność*
  > (zazwyczaj na poziomie metod) <br/>
  > np. **Fabryka** ma mieć **Produkt** lub go tworzyć, więc Fabryka potrzebuje klasy Produkt <br/>
  > inaczej mówiąc klasa **Fabryka** jest zależna od klasy **Produkt**, natomiast klasa **Produkt** może istnieć bez klasy **Fabryka**(jest niezależna) <br/>
  > w przypadku zmian w konstruktorze klasy Produkt, zmiany również należy wprowadzić w Fabryce.
  > odwołując się do przykładu Student-Stanowisko, np. klasa **Student** potrzebuje klasy **Komputer**. Student ma wskaźnik na dany Komputer i może wywołać metodę klasy Komputer(np. użyj()), natomiast Komputer nie musi posiadać Studenta, żeby wywołać swoją metodę.
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/Inzynieria%20oprogramowania/%C4%87wiczenia2/zdj/zaleznosc.png"> 
 
* #### *Agregacja*
  > jedna klasa zawiera w swojej strukturze obiekt drugiej klasy. <br/>
  > np. **Bukiet** zawiera w sobie **Kwiaty**, inaczej mówiąc **Bukiet** zawiera w sobie kontener **Kwiatów**
  > <img src="https://github.com/JakubMakaruk/UMCS/blob/master/Inzynieria%20oprogramowania/%C4%87wiczenia2/zdj/agregacja.png">
  
* #### *Kompozycja*
  > szczególny przypadek agregacji, <br/>
  > jedna klasa nie może istnieć bez drugiej. <br/>
  > np. człowiek - serce(jak nie ma serca to nie ma człowieka) lub samochód - silnik. <br/>
  > zazwyczaj dotyczy to stałej liczby elementów, np. jedno serce, jeden silnik
  <img src="https://github.com/JakubMakaruk/UMCS/blob/master/Inzynieria%20oprogramowania/%C4%87wiczenia2/zdj/kompozycja.png">
<br/>
W pliku ćw1.mdj znajduje się model wykonany w StarUML przedstawiający prosty schemat(do obejrzenia w pliku ćw2.png), w którym wykorzystano każdy typ relacji(praca domowa).
