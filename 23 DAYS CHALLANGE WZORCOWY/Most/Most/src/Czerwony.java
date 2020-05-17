public class Czerwony implements Kolor {
    private String k = "CZERWONY";

    public void koloruj(Figura f) {
        f.kolor = new Czerwony();
    }
    public String getKolor() {
        return this.k;
    }
}