public class Terrorysta implements Gracz {
    private String zadanie;
    private String bron;

    public Terrorysta() {
        this.zadanie = "Podlozyc bombe!";
    }
    public void dodaj_bron(String b) {
        this.bron = b;
    }
    public void cel() {
        System.out.println("Terrorysta z bronia " + this.bron + " ma cel - " + this.zadanie);
    }
}