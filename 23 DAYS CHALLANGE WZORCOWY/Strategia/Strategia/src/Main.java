public class Main {
    public static void main(String[] args) {
        KontekstFormatowaniaTekstu kontekst = new KontekstFormatowaniaTekstu();

        String napis = "Przykladowy napis do roboty";

        kontekst.setStrategia(new DuzeLiteryFormat());
        kontekst.wykonajMetode(napis);

        kontekst.setStrategia(new MaleLiteryFormat());
        kontekst.wykonajMetode(napis);

        kontekst.setStrategia(new CoDrugaLiteraMalaFormat());
        kontekst.wykonajMetode(napis);
    }
}



