# Fasada

Jest to wzorzec strukturalny. Celem tego wzorca jest uproszczenie korzystania z pewnego systemu poprzez prostszy interfejs. Zazwyczaj implementuje się ją za pomocąjednej klasy, która jest powiązana z innymi klasami. Fasada można powiedzieć, że ukrywa pewną część systemu. </br>
**Przykłady:**
</br>
**1.** Klient chce wypłacić pieniądze z bankomatu. W tym celu wystarczy, że użyje tylko jednej metody "wypłaćPieniądze" zamiast wielu innych typu - uruchomienia silnika, kasety na banknoty. Co więcej klient używając poszczególnych metod ingerowałby w działanie bankomatu. Mógłby wywoływać metody, które nie powinny być dla niego dostępne, bo mógłby na przykład wypłacić więcej pieniędzy niż by chciał. </br>
**2.** Użytkownik chce włączyć komputer. W tym celu wystarczy, że użyje tylko jednej metody "uruchom", zamiast grzebać w komputerze i uruchamiać poszczególne komponenty osobno - plyta glowna, procesor, karta graficzna itd.
Fasada służy do ukrycia szczegółów(złożoności) pewnego systemu przed klientem.

### Przykladowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Fasada/zdj/fasada.png" alt="zdj" height="400px">
</p>

### Glowna czesc programu wygląda następująco:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Fasada/zdj/main1.png" alt="zdj" height="400px">
</p>

### Wynik dzialania programu:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Fasada/zdj/main2.png" alt="zdj" height="400px">
</p>
</br>
Przed użytkownikiem schowana jest cała złożoność komputera. Użytkownik chce tylko włączyć komputer. Więc wywołuje tylko jedną metodę "Uruchom", bez zaglądania do środka komputera.
