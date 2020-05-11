public class Rosnaco extends Sortowanie {
    public Rosnaco(int[] arr) {
        super(arr);
    }

    @Override
    public boolean porownaj(int a, int b) {
        return a>b;
    }
}