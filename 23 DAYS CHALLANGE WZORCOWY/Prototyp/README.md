# Prototyp

Jest to wzorzec kreacyjny. Celem wzorca jest umożliwienie tworzenia obiektów określonej klasy na podstawie prototypowego egzemplarza. Wzorzec Prototyp skupia się na klonowaniu obiektów. Gdy stwierdzimy, że po stworzeniu pierwszej instancji danej klasy, kolejne będą podobne, wówczas używamy metody do klonowania obiektów. </br></br>
**Przykłady:**
</br>
**1.** System tworzenia Pizzy. Wyobraźmy sobie pizzerię, w której kucharz na początku zawsze tworzy standardową pizzę(margherita). Wszystkie inne pizze są takie same(zawierają podstawową wersję - margheritę), z tą różnicą, że mogą zawierać dodatki. W takiej sytuacji, aby stworzyć wszystkie inne pizze możemy skorzystać z prototypu, dzięki któremu stworzymy podstawową wersję dla każdej pizzy, a następnie dla każdej pizzy możemy wywoływać metody typu dodajSzynke(), dodajPapryke(), aby dodać wszystkie składniki dla poszczególnych rodzajów pizzy. </br>
**2.** Tworzenie podstawowych rzeczy do gry. Weźmy na warsztat grę Euro Truck Simulator 2. Gdy zaczynamy rozgrywkę system tworzy dla nas nasz pierwszy garaż dla tirów. Co prawda jest on pusty, natomiast można to zmodyfikować w ten sposób, aby gracz po rozpoczęciu nowej gry otrzymał garaż z pewnymi tirami, których markę wybrał na początku. Przy tworzeniu każdego tira można użyć wzorca Prototyp, który stworzy N liczbę tirów o marce X za pomocą klonowania, a następnie dla każdego tira wywołana zostanie metoda setModel(). Podobny przykład dla firmy taksówkarskiej przedstawiłem poniżej.

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Prototyp/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Prototyp/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Prototyp/zdj/main2.png" alt="zdj">
</p>

### Główna część odbywa się w instancji klasy Firma:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Prototyp/zdj/main3.png" alt="zdj">
</p>
