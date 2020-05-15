public class ZestawB extends Budowniczy {
    @Override
    public void zbudujCpu() {
        zestaw.setCpu("Intel Core i3 !!!");
    }

    @Override
    public void zbudujGpu() {
        zestaw.setGpu("Dwa giga !!!");
    }

    @Override
    public void zbudujRam() {
        zestaw.setRam("4 gigabajtow !!!!");
    }

    @Override
    public void zbudujDysk() {
        zestaw.setDysk("ES ES DE 128 GIGABAJTOW !!!");
    }
}