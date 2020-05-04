public class Kwadrat implements Ksztalt {
    private int id;

    public Kwadrat(int id) {
        this.id=id;
    }

    @Override
    public void rysuj() {
        System.out.println("Narysowalem KWADRAT o id " + id);
    }
}