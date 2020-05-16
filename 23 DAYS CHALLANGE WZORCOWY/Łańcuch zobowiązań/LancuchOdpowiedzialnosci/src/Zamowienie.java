public class Zamowienie {
    private int id;
    private double koszt;
    private String opis;

    public Zamowienie(int id, double koszt, String opis) {
        this.id = id;
        this.koszt = koszt;
        this.opis = opis;
    }

    @Override
    public String toString() {
        return id + ". " + opis + " | Koszt: " + koszt;
    }
    public double getKoszt() {
        return koszt;
    }
}
