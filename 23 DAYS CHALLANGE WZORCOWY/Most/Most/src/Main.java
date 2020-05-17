public class Main {
    public static void main(String[] args) {
        Kwadrat kwadrat = new Kwadrat();
        kwadrat.setKolor(new Czerwony());
        kwadrat.rysuj();

        Trojkat trojkat = new Trojkat();
        trojkat.setKolor(new Niebieski());
        trojkat.rysuj();
    }
}


