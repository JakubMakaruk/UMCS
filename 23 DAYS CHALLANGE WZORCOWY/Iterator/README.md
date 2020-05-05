# Iterator

Jest to wzorzec czynnościowy projektowy. Zapewnia sekwencyjny dostęp do elementów obiektów łączących się w jedną większą całość. Dzięki iteratorowi możemy uzyskać dostęp do obiektu zagregowanego bez ujawniania jego wewnętrznej reprezentacji. </br>
**Przykłady:**
</br>
**1.** System dla Kelnera. Kelner który zbiera zamówienia na koniec zanosi je do szefa kuchni. Za pomocą iteratora ma dostęp do kolejnych zamówień, które zostały stworzone. W przykładzie poniżej pominięto wczytywanie zestawów obiadowych z Maina. Tworzą się one stałe w konstruktorze Obiad.

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Iterator/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Iterator/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Iterator/zdj/main2.png" alt="zdj">
</p>

### Struktura plików(użyty interfejs):
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Iterator/zdj/main3.png" alt="zdj">
</p>

### Dodawanie obiadów:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Iterator/zdj/dodawanie.png" alt="zdj">
</p>

### Główna część Iteratora:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Iterator/zdj/glownyiterator.png" alt="zdj">
</p>
