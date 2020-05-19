# Wizytator(Odwiedzający, Visitor)

Wzorzec projektowy, którego celem jest dodawanie nowych funkcjonalności/operacji do istniejącego obiektu, bez konieczności modyfikowania klasy, na których obiekt operuje. Wiąże się to z regułą open/closed(projektowanie w taki sposób, żeby nie trzeba było wprowadzać modyfikacje do już istniejącego kodu, nad którym pracowaliśmy i zakończyliśmy operowanie). Klasa Wizytator powinna mieć przeciążoną metodę visit() w zależności od argumentu, w którym pojawia się inna klasa obiektu. Są to różne wersje tej samej operacji/algorytmu. Natomiast klasy, na których Wizytator będzie oddziałowywać powinny posiadać w swojej strukturze metodę accept(Visitor), która sprowadza się do wywołania visitor.visit(this). </br> </br>
**Przykłady:**
</br>
**1.** Uruchamianie komputera, gdzie poniżej jest to bardziej przedstawione. Główna klasa CzescKomputeraWizytator posiada cztery wersje metody visit, w zależności od argumentu. Wiąże się to także z tym, że klasy na których ten Wizytator operuje posiadają metodę accept(CzescKomputeraWizytator), gdzie w ostateczności następuje wywołanie wizytator.visit(this).

### Przykładowy diagram:
<p align="center">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Wizytator/zdj/diagram.png" alt="zdj">
</p>

### Główna część programu wygląda następująco:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Wizytator/zdj/main1.png" alt="zdj">
</p>

### Wynik działania programu:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Wizytator/zdj/main2.png" alt="zdj">
</p>

### Główna, ważna klasa Komputer, gdzie odbywa się odwiedzenie wszystkich części komputera:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Wizytator/zdj/main3.png" alt="zdj">
</p>

### Poszczególne części komputera:
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Wizytator/zdj/klawiatura.png" alt="zdj">
</p>
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Wizytator/zdj/myszka.png" alt="zdj">
</p>
<p align="left">
 <img src="https://github.com/JakubMakaruk/UMCS/blob/master/23%20DAYS%20CHALLANGE%20WZORCOWY/Wizytator/zdj/monitor.png" alt="zdj">
</p>
