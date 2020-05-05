public class Kelner {
    private Zamowienie zamowionyObiad;

    public Kelner(Zamowienie z) {
        this.zamowionyObiad = z;
    }

    public void pokazZamowienie() {
        Iterator it = zamowionyObiad.createIterator();

        System.out.println("ZAMÓWIENIE:");
        while(it.hasNext()) {
            Danie temp = (Danie) it.next();
            System.out.println(temp.getNazwa());
        }
    }
}