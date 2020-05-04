public class Trojkat implements Ksztalt {
    private int id;

    public Trojkat(int id) {
        this.id=id;
    }

    @Override
    public void rysuj() {
        System.out.println("Narysowalem TROJKAT o id " + id);
    }
}