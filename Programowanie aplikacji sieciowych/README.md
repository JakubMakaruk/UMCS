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
 
 ```sh
 ```
