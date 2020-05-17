public class Trojkat extends Figura {
    public Trojkat() {
    }

    public void setKolor(Kolor kolor) {
        kolor.koloruj(this);
    }

    public void rysuj() {
        System.out.println("Rysuje TROJKAT o kolorze " + this.kolor.getKolor());
    }
}