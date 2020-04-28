public class Main {
    public static void main(String[] args) {
        HistoriaPrzegladarki h1 = HistoriaPrzegladarki.getInstance(); // utworzy pierwszą i jedyną instancję
        HistoriaPrzegladarki h2 = HistoriaPrzegladarki.getInstance(); // nie utworzy kolejnej instancji
        h1.setNapis("siema");
        h2.setNapis("sieniema");
        System.out.println(h1.getNapis()); // wynik: sieniema
        System.out.println(h2.getNapis()); // wynik: sieniema
    }
}
