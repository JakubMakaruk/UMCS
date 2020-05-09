public class KontekstFormatowaniaTekstu {
    private Formatowanie strategia;

    public void setStrategia(Formatowanie s) {
        strategia = s;
    }

    public void wykonajMetode(String tekst) {
        System.out.println(strategia.formatuj(tekst));
    }

}