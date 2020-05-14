public class Kontroler {
    private Stan maszyna;

    public Kontroler() {
        maszyna = null;
    }

    public void setStan(Stan s) {
        maszyna = s;
    }

    public Stan getStan() {
        return maszyna;
    }

    public void akcja() {
        maszyna.dzialaj();
    }
}