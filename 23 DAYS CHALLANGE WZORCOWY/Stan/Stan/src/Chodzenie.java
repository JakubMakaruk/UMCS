public class Chodzenie implements Stan {
    public void dzialaj(Kontroler k) {
        k.setStan(this);
        System.out.println("Gracz jest w stanie: CHODZENIE");
    }

    public String getNazwaStanu() {
        return "Stan: CHODZENIE";
    }
}