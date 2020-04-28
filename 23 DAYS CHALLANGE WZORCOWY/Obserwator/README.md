# Obserwator

Jest to wzorzec czynnościowy. We wzorcu tym wyróżniamy dwa typy obiektów jakimi są:
- **obserwowany**(ang. observable),
- **obserwator**(ang. observer). 

Obserwowany to obiekt, o którym chcemy pozyskiwać informacje o jego działanich(np. zmiana położenia w grze RPG). Obserwator natomiast to obiekt, który czeka na powiadomienie o wykonanych działaniach obserwowanego.
Głównym celem tego wzorca jest powiadamianie zainteresowanych obiektów o zmianie stanu głównego, obserwowanego obiektu. </br></br>
**Przykłady:**
</br>
**1.** Gra RPG, w której mamy główną postać oraz potwory. Potwory domyślnie przyjmują stan pokojowy, natomiast gdy w ich określonym okręgu(liczenie dystansów położenia) pojawi się nasz bohater, wówczas stają się one agresywne i zaczynają atakować naszego bohatera. Potwory czekają na powiadomienia gdy bohater gry zmieni swoje położenie.

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Obserwator/zdj/obserwator.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Obserwator/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Obserwator/zdj/main2.png" alt="zdj">
</p>

### Struktura plików(użyty interfejs):
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Obserwator/zdj/main3.png" alt="zdj">
</p>
