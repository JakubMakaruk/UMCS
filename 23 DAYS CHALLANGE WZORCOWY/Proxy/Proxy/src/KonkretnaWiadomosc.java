public class KonkretnaWiadomosc implements Wiadomosc {
    public String zawartosc;

    public KonkretnaWiadomosc(String s) {
        this.zawartosc = s;
    }

    @Override
    public void wyswietl() {
        System.out.println("WIADOMOSC: " + zawartosc);
    }
}