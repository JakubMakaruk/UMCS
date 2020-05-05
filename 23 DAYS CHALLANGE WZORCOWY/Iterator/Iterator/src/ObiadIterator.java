public class ObiadIterator implements Iterator {
    private Danie [] dania;
    int pozycja=0; // pozycja iteratora

    public ObiadIterator(Danie [] dania) {
        this.dania = dania;

    }

    @Override
    public boolean hasNext() {
        return pozycja < dania.length && dania[pozycja]!=null;
    }

    @Override
    public Object next() {
        Danie d = dania[pozycja];
        pozycja++;
        return d;
    }
}