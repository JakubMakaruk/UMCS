public class Niebieski implements Kolor {
    private String k = "NIEBIESKI";

    public void koloruj(Figura f) {
        f.kolor = new Niebieski();
    }
    public String getKolor() {
        return this.k;
    }
}