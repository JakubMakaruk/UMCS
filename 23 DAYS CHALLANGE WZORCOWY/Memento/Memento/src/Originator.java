public class Originator {
    private String stan;

    public void setStan(String s) {
        stan = s;
    }

    public Memento save() {
        return new Memento(stan);
    }

    public void cofnij(Memento m) {
        stan = m.getTekst();
    }

    public String getObecnyStan() {
        return stan;
    }
}