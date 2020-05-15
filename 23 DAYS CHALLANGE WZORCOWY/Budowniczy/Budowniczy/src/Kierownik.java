public class Kierownik {
    private Budowniczy budowniczyKomputera;

    public void setBudowniczy(Budowniczy b) {
        this.budowniczyKomputera = b;
    }
    public void zrealizujZamowienie() {
        budowniczyKomputera.zbudujCpu();
        budowniczyKomputera.zbudujGpu();
        budowniczyKomputera.zbudujRam();
        budowniczyKomputera.zbudujDysk();
    }
    public ZestawKomputerowy getZestaw() {
        return budowniczyKomputera.getZestaw();
    }
}