public class Klient {
    private Samochod s;
    private Kluczyki k;

    public Klient(FabrykaAbstrakcyjna fabryka) {
        s = fabryka.stworzSamochod();
        k = fabryka.stworzKluczyki();
        dajCzymsJezdzic();
    }
    public void dajCzymsJezdzic() {
        System.out.println("Zaczynamy tworzyć specjalnie nową furkę dla Ciebie!");
        s.stworz();
        k.stworz();
        System.out.println("Mozesz wyjezdzac z salonu!");
    }
}