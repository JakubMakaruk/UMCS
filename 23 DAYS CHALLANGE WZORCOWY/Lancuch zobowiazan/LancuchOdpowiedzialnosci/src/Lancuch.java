public abstract class Lancuch {
    private Lancuch next;
    private String nazwa;

    public abstract boolean autoryzacja(Zamowienie zamowienie);

    public Lancuch(String n) {
        this.nazwa = n;
    }
    public void setNext(Lancuch handler) {
        this.next = handler;
    }
    public Lancuch getNext() {
        return next;
    }
    public String getNazwa() {
        return nazwa;
    }

}
