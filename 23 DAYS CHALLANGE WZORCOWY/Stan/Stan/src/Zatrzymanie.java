public class Zatrzymanie implements Stan {
    public void dzialaj(Kontroler k) {
        k.setStan(this);
        System.out.println("Gracz jest w stanie: ZATRZYMANIE SIE");
    }

    public String getNazwaStanu() {
        return "Stan: ZATRZYMANIE SIE";
    }
}