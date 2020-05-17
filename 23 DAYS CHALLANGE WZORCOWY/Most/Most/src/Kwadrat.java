public class Kwadrat extends Figura {
    public Kwadrat() {
    }

    public void setKolor(Kolor kolor) {
        kolor.koloruj(this);
    }

    public void rysuj() {
        System.out.println("Rysuje KWADRAT o kolorze " + this.kolor.getKolor());
    }
}