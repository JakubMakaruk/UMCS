public class FiletZKurczaka extends ObiadDekorator1 {
    Obiad obiad;
    public FiletZKurczaka(Obiad obiad) {
        this.obiad = obiad;
    }

    @Override
    public String getZamowienie() {
        return this.obiad.getZamowienie() + "Filet z kurczaka + ";
    }

    @Override
    public double cena() {
        return obiad.cena() + 13.50;
    }

}