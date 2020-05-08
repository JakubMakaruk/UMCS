public class Robota implements Polecenie {
    private Polecenie [] sprawy;

    public Robota(Polecenie [] p) {
        sprawy = p;
    }

    public void wykonaj() {
        for(Polecenie p : sprawy)
            p.wykonaj();
    }

    public void wycofaj() {
        for(Polecenie p : sprawy)
            p.wycofaj();
    }

}