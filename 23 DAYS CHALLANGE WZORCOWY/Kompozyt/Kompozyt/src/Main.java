public class Main {
    public static void main(String[] args) {
        Ksztalt k1 = new Kwadrat(1);
        Ksztalt k2 = new Kwadrat(2);
        Ksztalt k3 = new Kwadrat(3);

        Ksztalt k4 = new Kolo(1);

        Ksztalt k5 = new Trojkat(1);

        Kompozyt kompozyt = new Kompozyt();
        kompozyt.dodajKsztalt(k1);
        kompozyt.dodajKsztalt(k2);
        kompozyt.dodajKsztalt(k3);
        kompozyt.dodajKsztalt(k4);
        kompozyt.dodajKsztalt(k5);

        kompozyt.rysuj();
    }
}



