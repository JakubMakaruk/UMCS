public class Obiad implements Zamowienie {
    private Danie [] dania;
    int liczbaElementow=0;

    public Obiad() {
        dania = new Danie[3];

        dodajDanie("Rosół / Schabowy");
        dodajDanie("Pomidorowa / Golonka");
        dodajDanie("Ogórkowa / Filet z kurczaka");
    }

    public void dodajDanie(String s) {
        Danie d = new Danie(s);
        dania[liczbaElementow] = d;
        liczbaElementow++;
    }

    public Iterator createIterator() {
        return new ObiadIterator(dania);
    }
}