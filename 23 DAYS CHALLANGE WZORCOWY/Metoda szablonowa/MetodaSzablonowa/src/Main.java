public class Main {
    public static void main(String[] args) {
        int[] tab = {1, 3, 5, 4, 2};
        Rosnaco rosnaco = new Rosnaco(tab);
        rosnaco.sortowanie();
        rosnaco.wyswietl();

        System.out.println();
        Malejaco malejaco = new Malejaco(tab);
        malejaco.sortowanie();
        malejaco.wyswietl();
    }
}


