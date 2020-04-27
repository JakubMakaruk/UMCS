import pack.*;

public class Main {
    public static void main(String[] args)
    {
        Wilk w1 = new Wilk(1,1);
        Tygrys t1 = new Tygrys(2,2);
        Niedzwiedz n1 = new Niedzwiedz(3,3);

        Bohater b1 = new Bohater(10, 10);
        b1.dodajObserwatora(w1);
        b1.dodajObserwatora(t1);
        b1.dodajObserwatora(n1);

        b1.zmienPolozenie(1,1); // wynik: "Wilk atakuje!"
        b1.zmienPolozenie(2,2); // wynik: "Tygrys atakuje!"
        b1.zmienPolozenie(3,3); // wynik: "Niedzwiedz atakuje!"
        b1.zmienPolozenie(3,4); // wynik:
    }
}
