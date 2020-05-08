public class Main {
    public static void main(String[] args) {
        SzefMafii szef = new SzefMafii();

        CzlonekMafii cz1 = new CzlonekMafii("Tommy");
        CzlonekMafii cz2 = new CzlonekMafii("Paulie");
        CzlonekMafii cz3 = new CzlonekMafii("Sam");

        ZaplanujAkcje zaplanujAkcje = new ZaplanujAkcje(cz1); // Tommy planuje akcje
        ZbierajHaracz zbierajHaracz = new ZbierajHaracz(cz2); // Paulie zbiera haracz

        szef.setPolecenie(zaplanujAkcje);
        szef.wykonaj();
        szef.setPolecenie(zbierajHaracz);
        szef.wykonaj();

        System.out.println("");

        // Tommy planuje akcje, Paulie i Sam zbieraja haracz.
        Polecenie [] tablica_rozkazow = {new ZaplanujAkcje(cz1), new ZbierajHaracz(cz2), new ZbierajHaracz(cz3)};
        Robota robota = new Robota(tablica_rozkazow);

        szef.setPolecenie(robota);
        szef.wykonaj();
        szef.wycofaj();
    }
}



