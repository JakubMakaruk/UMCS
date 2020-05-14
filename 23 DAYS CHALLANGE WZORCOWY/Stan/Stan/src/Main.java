public class Main {
    public static void main(String[] args) {
        Kontroler kontroler = new Kontroler();

        Chodzenie chodzenie = new Chodzenie();
        kontroler.setStan(chodzenie);
        System.out.println(kontroler.getStan().getNazwaStanu());
        kontroler.akcja();

        System.out.println();

        Zatrzymanie zatrzymanie = new Zatrzymanie();
        kontroler.setStan(zatrzymanie);
        System.out.println(kontroler.getStan().getNazwaStanu());
        kontroler.akcja();
    }
}



