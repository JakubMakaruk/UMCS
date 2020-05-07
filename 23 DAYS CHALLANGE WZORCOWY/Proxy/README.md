# Proxy(pełnomocnik)

Jest to wzorzec strukturalny. Jego zadaniem jest pełnienie reprezentanta innego obiektu w celu kontrolowania dostępu do niego(tworzenie obiektu zastępującego inny obiekt). Zastosowanie proxy umożliwia realizację dodatkowych operacji, które nie były przewidziane w interfejsie emulowanego obiektu. </br></br>
**Przykłady:**
</br>
**1.** System mailowy. Za pomocą dodatkowych funkcjonalności proxy możemy podejrzeć wiadomość, a także wyznaczyć modyfikacje na niej </br>
**2.** Wersja chroniąca obiekt, na którym pełnione są jedynie "legalne" operacje. "Proxy kontroluje co zostanie przekazane, a co nie."

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Proxy/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Proxy/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Proxy/zdj/main2.png" alt="zdj">
</p>

### Główna część odbywa się w klasie Proxy:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Proxy/zdj/main3.png" alt="zdj">
</p>
