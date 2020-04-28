# Singleton

Jest to wzorzec kreacyjny. Celem tego wzorca jest uniemożliwienie tworzenia wielu instancji jednej klasy oraz zapewnienie globalnego dostępu do stworzonego tylko raz obiektu. Używa się tego wzorca gdy chcemy wyróżnić jedną z klas w systemie jako unikatową, a odatkowo możemy zarządzać jednym spójnym obiektem dostępnym z wielu miejsc aplikacji. Każde operacje wykonywane z tej klasy odnoszą się do jedynej istniejącej w systemie, tej samej instancji.
**Przykłady:**
</br>
**1.** Historia przeglądarki. Może być tylko jedyna historia przeglądarki w danej przeglądarce, do której możemy się odwoływać w każdym momencie. </br>
**2.** Nieco mniej sensowny przykład, stworzenie stałej liczby jako obiekt klasy. Np. klasa LiczbaPI, której wartość jest const, a za pomocą getInstance() możemy pobierać instancję tego obiektu - liczbę PI.

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Singleton/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Obserwator/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Obserwator/zdj/main2.png" alt="zdj">
</p>

### Implementacja klasy HistoriaPlików(Singleton):
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Obserwator/zdj/singleton1.png" alt="zdj">
</p>
