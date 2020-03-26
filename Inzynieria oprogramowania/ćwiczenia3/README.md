## Diagramy sekwencji(przebiegu)

Diagarmy sekwencji należą do grupy diagramów interakcji. Pozwalają modelować wzajemną interakcję obiektów w funkcji czasu jej trwania. 
Obrazują w jaki sposób poszczególne częsci systemu komunikują się ze sobą. Np. w jaki sposób i kiedy pewien obiekt wywołuje metody innego obiektu.
Obiekty diagramu występują jako prostokąty składające się z [nazwa obiektu : nazwa klasy]. Możemy pomijać nazywanie obiektu danej klasy( : nazwa klasy ), wówczas mamy na myśli dowolny obiekt tej klasy.
<br/>
Każdy z obiektów(uczestników) ma pionową linię życia obrazującą czas istnienia danego obiektu.
<br/>
Komunikacja między obiektami odbywa się za pomocą strzałek między liniami życia obiektów.
<img src="https://github.com/JakubMakaruk/UMCS/blob/master/Inzynieria%20oprogramowania/%C4%87wiczenia3/diagsekw%C4%87w1.png">
* na przedstawionym przykładzie mamy obiekt "gracz" klasy Policjant, który wywołuje metodę "obezwładnij" z obiektu klasy Przestepca.,
* nastepnie gracz wywoluje metode zalozKajdanki z obiektu klasy Przestepcy.
* na samym końcu gracz wywoluje metode z obiektu "areszt" klasy Areszt o nazwie umiescPrzestepce, gdzie w parametrach przekazuje wskaźnik do obiektu klasy Przestepca.

<br/>

Występują trzy rodzaje komunikatów między obiektami:
* **synchroniczny** - oznaczony strzałką z wypełnionym grotem,
* **zwrotny** - oznaczony przerywaną linią z zakończoną otwartym grotem,
* **asynchroniczny** - oznaczany strzałką z otwartym grotem(np. wywołania konstruktora/destruktora)

<br/>

**Bloki** - wyodrębnione fragmenty na diagramach sekwencji, które posiadają pewną właściwość. Np. gdy chcemy zaznaczyć na diagramie pewien fragment kodu(grupa operacji), który ma posiadać pewne warunki, wtedy zaznaczamy dany fragment prostokątem obejmującym te operacjie, a w lewym górnym rogu prostokątu umieszczamy słowo kluczowe określające znaczenie danego bloku(tzw. **operator interakcji**).
**Operatory interakcji**:
* **alt**(alternative) - warunek odpowiadający instrukcji **if-else**, warunek umieszcza się wewnątrz bloku w nawiasach kwadratowych,
* **opt**(optional) - reprezentujący instrukcję **if**(bez else),
* **loop** - definiujący pętlę typu **for**(o określonej z góry liczbie iteracji) lub **while**(wykonywanej dopóki pewien warunek jest prawdziwy),
* **break** - wykonanie fragmentu i zakończenie interakcji.

Przykład:
<img src="https://github.com/JakubMakaruk/UMCS/blob/master/Inzynieria%20oprogramowania/%C4%87wiczenia3/diagsekw%C4%87w2.png">
Przeciwnik opcjonalnie wykonuje Atak Odwetowy(tylko wtedy gdy Gracz zaatakuje go wywołując metodę "przyjmijObrazenia().
