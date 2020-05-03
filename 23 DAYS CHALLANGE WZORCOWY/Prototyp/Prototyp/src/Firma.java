import java.util.Vector;

public class Firma {
    private Vector<PrototypSamochodu> pojazdy = new Vector();

    public void stworzPoczatkowaFirme(){
        PrototypSamochodu p1 = new Opel(); // pierwszy opel w firmie
        p1.setModel("Astra");

        PrototypSamochodu p2 = (PrototypSamochodu) p1.clone(); // drugi opel sklonowany
        p2.setModel("Vectra"); // zmieniony model

        PrototypSamochodu p3 = new Ford();
        p3.setModel("Fiesta");
        PrototypSamochodu p4 = (PrototypSamochodu) p3.clone();
        p4.setModel("Mondeo");

        PrototypSamochodu p5 = new Mercedes();
        p5.setModel("CLK 500");
        PrototypSamochodu p6 = (PrototypSamochodu) p5.clone();
        p6.setModel("A45 AMG");

        pojazdy.add(p1);
        pojazdy.add(p2);
        pojazdy.add(p3);
        pojazdy.add(p4);
        pojazdy.add(p5);
        pojazdy.add(p6);
    }

    public void wyswietlPojazdy() {
        pojazdy.forEach((n) -> System.out.println(n.getNazwa()));
    }

}


