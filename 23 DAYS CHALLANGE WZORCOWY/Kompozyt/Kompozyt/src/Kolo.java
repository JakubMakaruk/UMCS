public class Kolo implements Ksztalt {
    private int id;

    public Kolo(int id) {
        this.id = id;
    }

    @Override
    public void rysuj() {
        System.out.println("Narysowalem KOLO o id " + id);
    }
}