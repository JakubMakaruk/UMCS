**Gniazdo** - wirutalny interfejs służący do komunikacji między procesami. Gniazda możemy podejrzeć za pomocą komendy *netstat*. 

Dla przykładu - dwa kubki spięte sznurkiem, służące do komunikacji. Sznurek to protokół komunikacji.

**Typy procesów:**
* klient - proces nawiązujący połączenie,
* serwer - proces oczekujący na połączenie na konkretnym porcie.

**Typy gniazd:**
* połączeniowe(strumieniowe) - STREAM np. TCP
* bezpołączeniowe - DGRAM np. UDP

Protokoły TCP i UDP służą do przesyłania pakietów/danych. 
* UDP(User Datagram Protocol) - protokół bezpołączeniowy. Pakiety podczas przesyłania mogą być gubione, modyfikowane lub dostarczane w innej kolejności niż były wysyłane. Protokół nie śledzi i kontroluje pakietów w sieci, więc nie wiadomo czy one w ogóle trafią do odbiorcy. Korzyścią UDP jest szybsza transmisja danych. Protokół ten używany jest w np. czaty video, gry komputerowe online, strumieniowanie, czyli tam gdzie dane muszą być przesyłane szybko.
* TCP(Transmission Control Protocol) - protokół połączeniowy. Charakteryzuje się kontrolowaniem pakietów w sieci. Zapewnia niezawodność kosztem przepustowości, integralność danych oraz zachowaną kolejność wysyłania danych(jeśli strona A wysyła stronie B pakiety w odpowiedniej kolejności to strona B zna tą kolejność). TCP opiekuje się danymi/pakietami, aby dotarły one do celu i w międzyczasie nie zostały zmodyfikowane.

PYTHON

* *Tworzenie gniazda:*

> socket.socket(socket_family, socket_type, protocol)  
 np. s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  
 AF_UNIX - gniazdo unixowe | AF_INET - gniazdo IPv4 \ SOCK.STREAM - TCP | SOCK.DGRAM - UDP
 
 * *Powiązanie gniazda z portem:*
 
 > socket.bind(address)  
 addres - tupla, dwójka zawierająca adres IP(string) oraz port(int)
 
 * *Nasłuchiwanie połączenia:*
 
 > socket.listen(backlog)  
 backlog - maksymalna liczba oczekujących gniazd na połączenie
 
 * *Połączenie z serwerem:*
 
 > socket.connect(address) | socket.connect_ex(address)  
 connect_ex - zwraca 0 jeśli nawiązaliśmy połączenie.  
 np. s.connect(("google.pl", 80)) | result = s.connect_ex(("google.pl", 80))
 
 * *Przyjęcie połączenia:*
 
 > socket.accept()  
 zwraca dwójkę, conn - nowe gniazdo do reprezentacji połączenia, address - dwójka(adres IP i port)
 
 * *Transmisja danych:*
 
 > socket.send(string)  
   socket.recv(bufsize)  
   string - dane do wysłania | bufzise - maksymalny rozmiar odebranych danych(nie oznacza ile danych na pewno uda się pobrać, tylko ile maksymalnie można pobrać)
   
  * *Zamknięcie połączenia:*
  
  > socket.close()  
    socket.shutfown(SHUT_RD/SHUT_WR/SHUT_RDWR)  
    
  * *Pobranie adresu IP znając hostname:*
  
  > hostname = socket.gethostbyname("google.pl")
  
  * *Pobranie hostname znając adres IP:*
  
  > hostname = socket.gethostbyaddr("8.8.8.8")
  
  
Komunikacja
- bezpołączeniowa(DGRAM) - wysoka wydajność, przesyłanie dużej liczby małych komunikatów, brak informowania strony wysyłającej o tym co stalo się z wysłaną wiadomościa, brak gwarancji, że adresat odbierze daną wiadomość. Komunikacja za pomocą konkretnego adresu pojedynczego adresata lub za pomocą trybu rozgłaszania w sieci(wiadomość wysyłana do wszystkich odbiorców w sieci, wpisanych na listę rozgłoszeniową - multicast/broadcast). Przykłady: DNS, DHCP, VOIP.
- połączeniowa(STREAM strumieniowa) - polega na nawiązaniu sesji(logicznego połączenia) między dwiema stronami. Po nawiązaniu sesji przydzielany jest unikatowy numer. W ramach sesji wiadomości przesyłane są niezawodnie(ich zawartość i kolejność odbierania nie zostają naruszone). Dodatkowo jeżeli adresat nie odbierze wiadomości, strona wysyłająca informowana jest o zaistniałym błędzie(gwarancja dostarczenia). Przykłady: HTTP(S), SMTP, FTP. 
 
 <br/> 
 
Modyfikacje na pliku rozpoznajemy za pomocą rozpatrywania sumy kontrolnej. 

 <br/> 
 
**Model OSI**(stos OSI - wzorzec dla rodziny protokołów opisujący strukturę komunikacji sieciowej.
| WARSTWA | ZADANIA |
| ------- | ------- |
| 7. aplikacji | świadczenie usług końcowych dla aplikacji/umożliwienie komunikację z użytkownikiem |
| 6. prezentacji | przetwarzanie, tłumaczenie danych do postaci kanonicznej(standardowego formatu)/konwersja danych |
| 5. sesji | kontrolowanie, nawiązywanie, zrywanie połączenia/odpowiedzialna za zarządzanie sesją/zarządzanie przebiegiem komunikacji |
| 4. transportowa | transfer danych/dbanie o kolejność pakietów/sprawdzanie poprawności przesyłanych pakietów/integralność |
| 3. sieciowa | ustanawianie, utrzymywanie i rozłączanie połączenia/wyznaczanie optymalnej trasy |
| 2. łącza danych | niezawodność łącza danych/ustalanie metod wymiany ramek/difniowanie mechanizmów kontroli błędów/trasowanie pakietów |
| 1. fizyczna | transmisja danych/przesyłanie bitów poprzez media sieciowe |
 
 <br/>
 
**Model TCP/IP** (stos TCP/IP) - zestaw protokołów internetowych. Odzwierciedla strukturę internetu.
| WARSTWA | ZADANIA |
| ------- | ------- |
| 4. aplikacji | kodowanie, reprezentacja danych dla użytkownika |
| 3. transportowa | odpowiedzialna za komunikację między urządzeniami/gwarancja pewności przesyłania danych/kierowanie informacji do odpowiednich aplikacji |
| 2. internetowa | przetwarzanie datagramów z adresami IP/wyznaczanie optymalnej trasy |
| 1. dostępu do sieci | przekazywanie danych przez fizyczne połączenia urządzeń/kontrolowanie urządzeń fizycznych i media |

<p align="center">
 <img src="https://egzamin-e13.pl/wp-content/uploads/2015/11/iso1-1024x682.png" alt="zdj" height="400px">
</p>
