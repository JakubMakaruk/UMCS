public class Main {
    public static void main(String[] args) {
        Osoba o1 = new Osoba("Adam");
        Osoba o2 = new Osoba("Zenek");
        Osoba o3 = new Osoba("Grazyna");

        InterfejsMediator mediator = new Mediator();
        ((Mediator) mediator).dodajOsobe(o1);
        ((Mediator) mediator).dodajOsobe(o2);
        ((Mediator) mediator).dodajOsobe(o3);

        o1.wyslijWiadomosc(o2, "Siema Zenek, co tam?"); // Adam wysyla wiadomosc do Zenek o tresci "Siema to ja!"
        System.out.println();
        o1.wyslijWiadomosc(o3, "Elo Grazia!"); // Adam wysyla wiadomosc do Grazyna o tresci "Elo Grazia!"
    }
}



