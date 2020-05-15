public abstract class Budowniczy {
    protected ZestawKomputerowy zestaw;

    public Budowniczy() {
        zestaw = new ZestawKomputerowy();
    }

    public ZestawKomputerowy getZestaw() {
        return zestaw;
    }

    public abstract void zbudujCpu();
    public abstract void zbudujGpu();
    public abstract void zbudujRam();
    public abstract void zbudujDysk();

}