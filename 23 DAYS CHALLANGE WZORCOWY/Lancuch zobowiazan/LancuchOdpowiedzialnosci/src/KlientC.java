public class KlientC extends Lancuch{
    private double stanKonta = 10000;

    public KlientC(String n) {
        super(n);
    }

    @Override
    public boolean autoryzacja(Zamowienie zamowienie) {
        if(stanKonta >= zamowienie.getKoszt()) {
            System.out.println("Klient C(" + getNazwa() +") zlozyl zamowienie: " + zamowienie.toString());
            return true;
        }
        else
            return getNext().autoryzacja(zamowienie);
    }
}
