public class Proxy implements Wiadomosc {
    public KonkretnaWiadomosc dane;
    private String zawartoscWiadomosci;

    public Proxy(String s) {
        this.zawartoscWiadomosci = s;
    }
    public void wyswietl() {
        if(dane==null)
            dane = new KonkretnaWiadomosc(zawartoscWiadomosci);
        dane.wyswietl();
    }
}



