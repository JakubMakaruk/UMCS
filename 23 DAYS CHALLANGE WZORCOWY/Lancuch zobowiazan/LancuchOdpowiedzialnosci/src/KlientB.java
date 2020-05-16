public class KlientB extends Lancuch{
    private double stanKonta = 500;

    public KlientB(String n) {
        super(n);
    }

    @Override
    public boolean autoryzacja(Zamowienie zamowienie) {
        if(stanKonta >= zamowienie.getKoszt()) {
            System.out.println("Klient B(" + getNazwa() +") zlozyl zamowienie: " + zamowienie.toString());
            return true;
        }
        else
            return getNext().autoryzacja(zamowienie);
    }
}
