public class Main {
    public static void main(String[] args)
    {
        Obiad obiadek = new ZiemniakiOpiekane();
        obiadek = new FiletZKurczaka(obiadek);
        obiadek = new Mizeria(obiadek);

        System.out.println("Zamowienie: " + obiadek.getZamowienie());
        System.out.println("Cena: " + obiadek.cena());
    }
}



