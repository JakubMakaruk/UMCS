public class Main {
    public static void main(String[] args) {
        Kontroler kontroler = new Kontroler();

        Chodzenie chodzenie = new Chodzenie();
        chodzenie.dzialaj(kontroler);
        System.out.println(kontroler.getStan().getNazwaStanu());

        System.out.println();

        Zatrzymanie zatrzymanie = new Zatrzymanie();
        zatrzymanie.dzialaj(kontroler);
        System.out.println(kontroler.getStan().getNazwaStanu());
    }
}



