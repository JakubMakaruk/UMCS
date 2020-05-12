public class Osoba {
    private String nazwa;
    private InterfejsMediator interfejsMediator;

    public Osoba(String n) {
        nazwa = n;
    }

    public void wyslijWiadomosc(Osoba o, String msg) {
        System.out.println("Wysylanie wiadomosci od " + nazwa + " do " + o.getNazwa() + ": " + msg);
        interfejsMediator.wyslijWiadomosc(o, msg);
    }

    public void dodajMediator(InterfejsMediator m) {
        interfejsMediator = m;
    }

    public String getNazwa() {
        return this.nazwa;
    }

    public void odbierzWiadomosc(String msg) {
        System.out.println("Odebrano wiadomosc: " + msg + ". Przez - " + nazwa);
    }

}