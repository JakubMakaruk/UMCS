public class ZestawA extends Budowniczy {
    @Override
    public void zbudujCpu() {
        zestaw.setCpu("Intel Core i5 !!!");
    }

    @Override
    public void zbudujGpu() {
        zestaw.setGpu("Cztery giga !!!");
    }

    @Override
    public void zbudujRam() {
        zestaw.setRam("8 gigabajtow !!!");
    }

    @Override
    public void zbudujDysk() {
        zestaw.setDysk(" tysionc !!!");
    }
}