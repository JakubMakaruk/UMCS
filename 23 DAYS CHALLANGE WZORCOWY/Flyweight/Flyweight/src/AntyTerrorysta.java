public class AntyTerrorysta implements Gracz {
    private String zadanie;
    private String bron;

    public AntyTerrorysta() {
        this.zadanie = "Rozbroic bombe!";
    }
    public void dodaj_bron(String b) {
        this.bron = b;
    }
    public void cel() {
        System.out.println("Anty terrorysta z bronia " + this.bron + " ma cel - " + this.zadanie);
    }
}