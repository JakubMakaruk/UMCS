public class Malejaco extends Sortowanie {

    public Malejaco(int[] arr) {
        super(arr);
    }

    @Override
    public boolean porownaj(int a, int b) {
        return a<b;
    }
}