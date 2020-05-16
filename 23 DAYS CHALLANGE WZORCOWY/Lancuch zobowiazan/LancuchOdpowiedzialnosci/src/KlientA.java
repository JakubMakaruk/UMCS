public class KlientA extends Lancuch{
    private double stanKonta = 200;

    public KlientA(String n) {
        super(n);
    }

    @Override
    public boolean autoryzacja(Zamowienie zamowienie) {
        if(stanKonta >= zamowienie.getKoszt()) {
            System.out.println("Klient A(" + getNazwa() +") zlozyl zamowienie: " + zamowienie.toString());
            return true;
        }
        else
            return getNext().autoryzacja(zamowienie);
    }
}
