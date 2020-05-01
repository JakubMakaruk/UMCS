public class BialaKapusta extends ObiadDekorator2 {
    Obiad obiad;
    public BialaKapusta(Obiad obiad) {
        this.obiad = obiad;
    }

    @Override
    public String getZamowienie() {
        return this.obiad.getZamowienie() + "Biala kapusta";
    }

    @Override
    public double cena() {
        return obiad.cena() + 4;
    }
}