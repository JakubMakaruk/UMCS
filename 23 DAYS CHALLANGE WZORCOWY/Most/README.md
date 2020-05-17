# Most(Bridge)

Strukturalny wzorzec projektowy. Jego celem jest oddzielenie abstrakcji od jej implementacji, dzięki czemu można modyfikować dwa elementy niezależnie od siebie. Wzorzec ten poprawia możliwe w przyszłości łatwe rozbudowy klas, zarówno implementacji, jak i interfejsu(przez dziedziczenie). Dodatkowo zachowuje zasadę hermetyzacji.  </br> </br>
**Przykłady:**
</br>
**1.** Program graficzny. Celem jest stworzenie figury o określonym kolorze. Mamy do czynienia z dwoma warstwami abstrakcji. Pierwsza to figura, a druga to kolor, który wypełnia naszą figurę. </br>
**2.** Pilot - Urządzenie. Chodzi o sterowanie pilotem określone urządzenie. Interfejsem mógłby być Pilot, po którym dziedziczyłyby np klasy PilotLampka, PilotTV. Dostęp do atrybutów oraz metod tych klas zapewniałby interfejs Pilot, który agregowałby interfejs Urządzenie. Z urządzenia dziedziczyłyby klasy Lampka i TV, które odpowiadałyby za wykonanie sterowania.

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Most/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Most/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Most/zdj/main2.png" alt="zdj">
</p>
