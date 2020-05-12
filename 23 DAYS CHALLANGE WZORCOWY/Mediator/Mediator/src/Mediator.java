public class Mediator implements InterfejsMediator {
    Osoba [] tablica = new Osoba[5];
    int index=0;

    public void dodajOsobe(Osoba o) {
        o.dodajMediator(this);
        tablica[index] = o;
        index++;
    }

    public void wyslijWiadomosc(Osoba o, String msg) {
        for(Osoba i : tablica)
            if(i == o)
            {
                i.odbierzWiadomosc(msg);
            }
    }
}