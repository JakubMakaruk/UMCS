public class Stek extends ObiadDekorator1 {
    Obiad obiad;
    public Stek(Obiad obiad) {
        this.obiad = obiad;
    }

    @Override
    public String getZamowienie() {
        return this.obiad.getZamowienie() + "Stek + ";
    }

    @Override
    public double cena() {
        return obiad.cena() + 15.50;
    }
}