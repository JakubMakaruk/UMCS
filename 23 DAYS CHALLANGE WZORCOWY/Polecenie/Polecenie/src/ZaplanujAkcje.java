public class ZaplanujAkcje implements Polecenie {
    private CzlonekMafii osoba;

    public ZaplanujAkcje(CzlonekMafii cz) {
        osoba = cz;
    }

    public void wykonaj() {
        osoba.zaplanujAkcje();
    }

    public void wycofaj() {
        osoba.przestanPlanowacAkcje();
    }
}