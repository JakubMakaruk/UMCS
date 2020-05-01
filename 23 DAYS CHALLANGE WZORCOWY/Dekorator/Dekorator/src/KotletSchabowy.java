public class KotletSchabowy extends ObiadDekorator1 {
    Obiad obiad;
    public KotletSchabowy(Obiad obiad) {
        this.obiad = obiad;
    }

    @Override
    public String getZamowienie() {
        return this.obiad.getZamowienie() + "Kotlet schabowy + ";
    }

    @Override
    public double cena() {
        return obiad.cena() + 10;
    }
}