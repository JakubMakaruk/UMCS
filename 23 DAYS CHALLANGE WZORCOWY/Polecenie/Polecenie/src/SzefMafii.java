public class SzefMafii {
    private Polecenie rozkaz;

    public void setPolecenie(Polecenie p) {
        rozkaz = p;
    }

    public void wykonaj() {
        rozkaz.wykonaj();
    }

    public void wycofaj() {
        rozkaz.wycofaj();
    }
}