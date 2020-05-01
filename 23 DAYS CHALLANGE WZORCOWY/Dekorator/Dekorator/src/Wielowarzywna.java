public class Wielowarzywna extends ObiadDekorator2 {
    Obiad obiad;
    public Wielowarzywna(Obiad obiad) {
        this.obiad = obiad;
    }

    @Override
    public String getZamowienie() {
        return this.obiad.getZamowienie() + "Wielowarzywna";
    }

    @Override
    public double cena() {
        return obiad.cena() + 4.50;
    }
}