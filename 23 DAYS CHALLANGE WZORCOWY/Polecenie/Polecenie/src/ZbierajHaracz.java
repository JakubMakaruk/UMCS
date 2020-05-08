public class ZbierajHaracz implements Polecenie {
    private CzlonekMafii osoba;

    public ZbierajHaracz(CzlonekMafii cz) {
        osoba = cz;
    }

    public void wykonaj() {
        osoba.zbierajHaracz();
    }

    public void wycofaj() {
        osoba.przestanZbieracHaracz();
    }
}