public class Main {
    public static void main(String[] args) {
        Kierownik kierownik = new Kierownik();

        Budowniczy opcja1 = new ZestawA();
        Budowniczy opjca2 = new ZestawB();

        kierownik.setBudowniczy(opcja1);
        kierownik.zrealizujZamowienie();
        ZestawKomputerowy produkt1 = kierownik.getZestaw();

        kierownik.setBudowniczy(opjca2);
        kierownik.zrealizujZamowienie();
        ZestawKomputerowy produkt2 = kierownik.getZestaw();

        System.out.println("PRODUKT 1");
        produkt1.wyswietl();
        System.out.println("\nPRODUKT 2");
        produkt2.wyswietl();
    }
}


