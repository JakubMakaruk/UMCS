public class Mizeria extends ObiadDekorator2 {
    Obiad obiad;
    public Mizeria(Obiad obiad) {
        this.obiad = obiad;
    }

    @Override
    public String getZamowienie() {
        return this.obiad.getZamowienie() + "Mizeria";
    }

    @Override
    public double cena() {
        return obiad.cena() + 3;
    }
}