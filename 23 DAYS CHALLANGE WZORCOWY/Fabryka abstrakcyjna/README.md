# Fabryka abstrakcyjna

Jest to wzorzec kreacyjny. Celem wzorca jest udostępnienie interfejsu w celu tworzenia różnych powiązanych obiektów jednej rodziny lub zależnych od siebie obiektów bez określania ich klas konkretnych. Wzorzec ten jest podobny do Metody Wytwórczej natomiast tutaj konentrujemy się na całych rodzinach produktów. Jeżeli dany system należy skonfigurować za pomocą jednej z wielu rodzin produktów. </br></br>
**Przykłady:**
</br>
**1.** Wytwarzanie zestawu komputerowego. Gdy chcemy utworzyć zestaw komputerowy dla użytkownika składający się z Monitora, Myszki, Klawiatury. "Te elementy to interfejsy, które będą realizowane przez konkretne klasy np. MonitorASUS, MonitorBENQ, MyszkaRazer, KlawiaturaHyperX."
**2.** System salonów samochodowych. Tworzymy dla klienta zestaw(rodzinę produktów) składający się z Samochodu i Kluczyków do tego samochodu. Przykład widoczny niżej w diagramie oraz kodzie.

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/23-DAYS-CHALLANGE-WZORCOWY/blob/master/Fabryka%20abstrakcyjna/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/23-DAYS-CHALLANGE-WZORCOWY/blob/master/Fabryka%20abstrakcyjna/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/23-DAYS-CHALLANGE-WZORCOWY/blob/master/Fabryka%20abstrakcyjna/zdj/main2.png" alt="zdj">
</p>

### Struktura plików(użyte interfejsy):
<p align="left">
 <img src="https://github.com/JakubMakaruk/23-DAYS-CHALLANGE-WZORCOWY/blob/master/Fabryka%20abstrakcyjna/zdj/main3.png" alt="zdj">
</p>
