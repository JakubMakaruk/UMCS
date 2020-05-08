# Adapter

Jest to wzorzec strukturalny, projektowy. Jego użycie umożliwia współpracę dwóm klasom o niekompatybilnych interfejsach. Przekształca interfejs jednej z klas na interfejs drugiej klasy. Opakowuje stary interfejs w nowy. </br> </br>
**Przykłady:**
</br>
**1.** System zarządzania kablami do połączenia monitora z komputerem. Za pomocą jednego kabla można użyć adaptera, który umożliwi połączenie tego kabla z nowszą technologią. Niżej jest przedstawiony przykład, gdzie występują dwie klasy VGA oraz HDMI, a także klasa Adapter, dzięki której istnieje współpraca, aby wyświetlić obraz za pomocą VGA lub HDMI. </br>
**2.** System odczytywania plików. Możliwa jest sytuacja, gdzie stary dokument Worda może być niekompatybilny z najnowszymi wersjami. Innymi słowy, istnieje możliwość, że plik zapisany w Word 2003 nie może być odczytany w Word 2017. W tej sytuacji można użyć interfejsu.

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Adapter/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Adapter/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Adapter/zdj/main2.png" alt="zdj">
</p>
